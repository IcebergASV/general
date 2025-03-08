#include "comp_tasks/home_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"

using namespace std::chrono_literals;

namespace comp_tasks
{
  Home::Home(const rclcpp::NodeOptions & options)
  : Task(options, "home")
  {
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Home::on_configure(const rclcpp_lifecycle::State &)
  {
    RCLCPP_DEBUG(this->get_logger(), "on_configure home callback");

    Task::on_configure(rclcpp_lifecycle::State());
  
    Home::getParam<int>("max_consec_recoveries", p_max_consec_recoveries_, 0, "Maxmimum consecutive recovery attempts before task completes");
    Home::getParam<double>("time_between_recovery_actions", p_time_between_recovery_actions_, 0.0, "Miliseconds between executing a recovery action (like sending a waypoint)");
    Home::getParam<double>("time_to_stop_before_recovery", p_time_to_stop_before_recovery_, 0.0, "Miliseconds to stop robot before switching to recovery state if no targets found");    
    Home::getStringParam("state", p_state_, "STOPPED", "State machine state");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Home::param_callback, this, std::placeholders::_1));
    setState(p_state_);
    timer_expired_ = true;
    node_state_ = "STOPPED";
    p_recovery_behaviour_ == "RECOVERY_PNT";

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rcl_interfaces::msg::SetParametersResult Home::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "max_consec_recoveries") { p_max_consec_recoveries_ = params[0].as_int(); updateYamlParam("max_consec_recoveries", params[0].as_int());}
    else if (params[0].get_name() == "time_between_recovery_actions") { p_time_between_recovery_actions_ = params[0].as_double(); updateYamlParam("time_between_recovery_actions", params[0].as_double());}
    else if (params[0].get_name() == "time_to_stop_before_recovery") { p_time_to_stop_before_recovery_ = params[0].as_double(); updateYamlParam("time_to_stop_before_recovery", params[0].as_double());}
    else if (params[0].get_name() == "state") { setState(params[0].as_string()); updateYamlParam("state", params[0].as_string());}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param manuevering: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Home::setState(std::string str_state)
  {
    bboxes_updated_ = false;
    wp_reached_ = false;
    wp_cnt_ = 0;
    detection_frame_cnt_ = 0;

    if (str_state == "RECOVERING")
    {
      node_state_ = "RECOVERING";
      setTimerDuration(p_time_between_recovery_actions_, "time between recovery actions");
      state_ = States::RECOVERING;
    }
    else if (str_state == "HEADING_TO_TARGET")
    {
      node_state_ = "HEADING_TO_TARGET";
      timer_expired_ = true;
      state_ = States::HEADING_TO_TARGET;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Invalid State: %s", str_state.c_str());
    }
  }


  void Home::executeRecoveryBehaviour() //Overwritten recovery behaviour function
  {
    if (p_recovery_behaviour_ == "STOP")
    {
      // Do Nothing
    }
    else if (p_recovery_behaviour_ == "RECOVERY_PNT")
    {
      publishGlobalWP(p_recovery_lat_, p_recovery_lon_, "recovery_pnt");
      RCLCPP_INFO(this->get_logger(), "Sent recovery waypoint");
    }
    else if (p_recovery_behaviour_ == "RECOVERY_GATE") {  //Added Gate recovery behaviour
      publishLocalWP(gate_x_, gate_y_);
      RCLCPP_INFO(this->get_logger(), "Sent recovery waypoint for last gate");
    }

    else 
    {
      RCLCPP_WARN(this->get_logger(), "Invalid Recovery Behavior: %s", p_recovery_behaviour_.c_str());
    }
    return;
  }

  void Home::handleDetections(const yolov8_msgs::msg::DetectionArray& detections)
  {
    publishWPTowardsBlackBuoyGate(detections);

    if (p_time_to_pause_search_ != 0.0)
    {
      setTimerDuration(p_time_to_pause_search_, "time to pause search");
    }
    else
    {
      timer_expired_ = true;
    }

    publishSearchStatus("Found");
  }

  void Home::taskLogic(const yolov8_msgs::msg::DetectionArray& detections)
  {
    if (in_guided_)
    {
      switch (state_)
      {
        case States::RECOVERING: // parameterize recovery behaviour & whether it does a recovery
        {
          RCLCPP_DEBUG(this->get_logger(), "RECOVERING"); 
          publishSearchStatus("Searching");
          publishBehaviourStatus("Recovering with " + p_recovery_behaviour_);
          publishStateStatus("RECOVERING");
          if (bbox_calculations::hasDesiredDetections(detections, {p_black_buoy_str_}))
          {
            handleDetections(detections);
            node_state_ = "HEADING_TO_TARGET";
            state_ = States::HEADING_TO_TARGET;
          }
          else if(timer_expired_)
          {
            executeRecoveryBehaviour();
            setTimerDuration(p_time_between_recovery_actions_, "time between recovery actions");
          }
          break;
        }

        case States::HEADING_TO_TARGET: // parameterize wait time & reorganize
        {
          std::string str_cnt = std::to_string(wp_cnt_);
          publishBehaviourStatus("Heading to WP " + str_cnt);
          RCLCPP_DEBUG(this->get_logger(), "HEADING_TO_TARGET"); 
          publishStateStatus("HEADING_TO_TARGET");
          if (timer_expired_)
          {
            publishSearchStatus("Searching");

            if (bbox_calculations::hasDesiredDetections(detections, {p_black_buoy_str_}))
            {
              handleDetections(detections);
            }
            else
            {
              executeRecoveryBehaviour();
              setTimerDuration(p_time_between_recovery_actions_, "time between recovery actions");
              node_state_ = "RECOVERING";
              state_ = States::RECOVERING;
            }
          }
          else if (wp_reached_)
          {
            std::string str_cnt = std::to_string(wp_cnt_);
            //publishBehaviourStatus("WP " + str_cnt + " Reached"); // TODO this gets overwritten too fast to see i think

            executeRecoveryBehaviour();
            setTimerDuration(p_time_between_recovery_actions_, "time between recovery actions");
            node_state_ = "RECOVERING";
            state_ = States::RECOVERING;
            
          }
          else
          {
            publishSearchStatus("Search Paused");
          }
          break;
        }
      }
    }
  }

}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Home)
