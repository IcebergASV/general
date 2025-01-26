#include "comp_tasks/maneuvering_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"

namespace comp_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Task(options, "maneuvering")
  {
    Maneuvering::getParam<int>("secs_till_timeout", p_secs_till_timeout_, 0, "Seconds robot is will stay in recovery if no targets found before finishing task, rounded up to nearest multiple of recovery time");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));
    status_ = States::STOPPED;

    consecutive_recovery_attempts_remaining_ = static_cast<int>(std::ceil(p_secs_till_timeout_ / p_time_between_recovery_actions_));
    RCLCPP_DEBUG(this->get_logger(), "Max %d consecutive recovery attempts", consecutive_recovery_attempts_remaining_);
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "secs_till_timeout") { p_secs_till_timeout_ = params[0].as_int();
      consecutive_recovery_attempts_remaining_ = static_cast<int>(std::ceil(p_secs_till_timeout_ / p_time_between_recovery_actions_)); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param man %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Maneuvering::checkIfFinished()
  {
    if (consecutive_recovery_attempts_remaining_ < 1)
    {
      signalTaskFinish();
    }
    else {
      consecutive_recovery_attempts_remaining_--;
    }
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
            publishWPTowardsDetections(detections);

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
            consecutive_recovery_attempts_remaining_ = static_cast<int>(std::ceil(p_secs_till_timeout_ / p_time_between_recovery_actions_));
            publishWPTowardsDetections(detections);

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
          RCLCPP_DEBUG(this->get_logger(), "Heading to Target"); 
          if (timer_expired_)
          {
            publishSearchStatus("Searching");
            if (bbox_calculations::hasDesiredDetections(detections, target_class_names_))
            {
              publishWPTowardsDetections(detections);
            }
          }
          else if (wp_reached_)
          {
            std::string str_cnt = std::to_string(wp_cnt_);
            publishBehaviourStatus("WP " + str_cnt + " Reached"); // TODO this gets overwritten too fast to see i think

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
