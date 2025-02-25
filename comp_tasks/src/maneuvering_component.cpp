#include "comp_tasks/maneuvering_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"

using namespace std::chrono_literals;

namespace comp_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Task(options, "maneuvering")
  {
    Maneuvering::getParam<int>("max_consec_recoveries", p_max_consec_recoveries_, 0, "Maxmimum consecutive recovery attempts before task completes");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));
    status_ = States::STOPPED;
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "max_consec_recoveries") { p_max_consec_recoveries_ = params[0].as_int(); updateYamlParam("max_consec_recoveries", params[0].as_int());}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param manuevering: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Maneuvering::checkIfFinished()
  {
    if (p_max_consec_recoveries_ < 1)
    {
      signalTaskFinish();
    }
    else {
      p_max_consec_recoveries_--;
    }
  }

  void Maneuvering::executeRecoveryBehaviour() //Overwritten recovery behaviour function
  {
    if (p_recovery_behaviour_ == "STOP")
    {
      // Do Nothing
    }
    else if (p_recovery_behaviour_ == "RECOVERY_PNT")
    {
      publishGlobalWP(p_recovery_lat_, p_recovery_lon_);
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

  void Maneuvering::handleDetections(const yolov8_msgs::msg::DetectionArray& detections)
  {
    geometry_msgs::msg::Point p = publishWPTowardsGate(detections);

    if (p_time_to_pause_search_ != 0.0)
    {
      setTimerDuration(p_time_to_pause_search_);
    }
    else
    {
      timer_expired_ = true;
    }

    if (bbox_calculations::hasGate(detections, p_red_buoy_str_, p_second_red_buoy_str_, p_green_buoy_str_, p_second_green_buoy_str_))
    {
      gate_x_ = p.x;
      gate_y_ = p.y;
    }

    publishSearchStatus("Found");
  }

  void Maneuvering::taskLogic(const yolov8_msgs::msg::DetectionArray& detections)
  {
    if (in_guided_)
    {
      switch (status_)
      {
        case States::STOPPED: // parameterize - don't go to this state at all in 0 secs
        {
          RCLCPP_DEBUG(this->get_logger(), "Stopped"); 
          publishSearchStatus("Searching");
          publishBehaviourStatus("Stopped");

          if (bbox_calculations::hasDesiredDetections(detections, target_class_names_))
          {
            handleDetections(detections);
            status_ = States::HEADING_TO_TARGET;
          }
          else if(timer_expired_)
          {
            executeRecoveryBehaviour();
            setTimerDuration(p_time_between_recovery_actions_);
            status_ = States::RECOVERING;
          }
          break;
        }

        case States::RECOVERING: // parameterize recovery behaviour & whether it does a recovery
        {
          RCLCPP_DEBUG(this->get_logger(), "Recovering"); 
          publishSearchStatus("Searching");
          publishBehaviourStatus("Recovering with " + p_recovery_behaviour_);
          if (bbox_calculations::hasDesiredDetections(detections, target_class_names_))
          {
            handleDetections(detections);
            status_ = States::HEADING_TO_TARGET;
          }
          else if(timer_expired_)
          {
            checkIfFinished();
            executeRecoveryBehaviour();
            setTimerDuration(p_time_between_recovery_actions_);
          }
          break;
        }

        case States::HEADING_TO_TARGET: // parameterize wait time & reorganize
        {
          std::string str_cnt = std::to_string(wp_cnt_);
          publishBehaviourStatus("Heading to WP " + str_cnt);
          RCLCPP_DEBUG(this->get_logger(), "Heading to Target"); 
          if (timer_expired_)
          {
            publishSearchStatus("Searching");


            if (bbox_calculations::hasDesiredDetections(detections, target_class_names_))
            {
              handleDetections(detections);
            }
            else if (p_time_to_stop_before_recovery_ == 0)
            {
              executeRecoveryBehaviour();
              setTimerDuration(p_time_between_recovery_actions_);
              status_ = States::RECOVERING;
            }
            else
            {
              RCLCPP_DEBUG(this->get_logger(), "No targets found, stopping"); 
              setTimerDuration(p_time_to_stop_before_recovery_);
              status_ = States::STOPPED;
            }
          }
          else if (wp_reached_)
          {
            std::string str_cnt = std::to_string(wp_cnt_);
            //publishBehaviourStatus("WP " + str_cnt + " Reached"); // TODO this gets overwritten too fast to see i think

            if (p_time_to_stop_before_recovery_ == 0)
            {
              executeRecoveryBehaviour();
              setTimerDuration(p_time_between_recovery_actions_);
              status_ = States::RECOVERING;
            }
            else
            {
              setTimerDuration(p_time_to_stop_before_recovery_);
              status_ = States::STOPPED;
            }
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

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Maneuvering)
