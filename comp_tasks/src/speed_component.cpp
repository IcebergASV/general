#include "comp_tasks/speed_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"

namespace comp_tasks
{
  Speed::Speed(const rclcpp::NodeOptions & options)
  : Task(options, "speed")
  {
    Speed::getParam<int>("max_consec_recoveries", p_max_consec_recoveries_, 0, "Maxmimum consecutive recovery attempts before task completes");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Speed::param_callback, this, std::placeholders::_1));
    status_ = States::SENDING_START_PNT;
  }

  rcl_interfaces::msg::SetParametersResult Speed::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "use_start_point") { p_use_start_point_ = params[0].as_int();}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param speed: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Speed::taskLogic(const yolov8_msgs::msg::DetectionArray& detections)
  {
    if (in_guided_)
    {
      switch (status_)
      {
        case States::SENDING_START_PNT:
        {
          RCLCPP_DEBUG(this->get_logger(), "SENDING_START_PNT"); 
          publishBehaviourStatus("Sending start point");

          if (p_use_start_point_)
          {
            publishStartPoint();
          }

          setTimerDuration(p_time_to_find_bay_);
          status_ = States::GOING_TO_BAY;
          break;
        }

        case States::GOING_TO_BAY:
        {
          
          RCLCPP_DEBUG(this->get_logger(), "Going to start point"); 
          publishBehaviourStatus("Going to start point");

          if (bbox_calculations::hasDesiredDetections(detections, target_class_names_))
          {
            updateCalculatedRoute(detections, target_class_names_);
            publishWPTowardsDetections(detections);
            setTimerDuration(p_max_time_between_bay_detections_);
            status_ = States::MANEUVER_THRU_BAY;
          }
          else if(timer_expired_) // Failed to find bay
          {
            signalTaskFinish();
          }
          break;
        }
        case States::MANEUVER_THRU_BAY: 
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_}))
          {
            updateCalculatedRoute(detections, {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_});
          }
          if(timer_expired_)
          {
            sendLocalWPList(calculated_route_);
            wp_reached_cnt_ = 0;
            status_ = States::CALCULATED_ROUTE;
          }
          break;
        }
        case States::CALCULATED_ROUTE:
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            publishWPTowardsDetections(detections, p_blue_buoy_str_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            status_ = States::PASSING_BUOY;
          }
          else
          {
            if (wp_reached_cnt_ >= wps_in_route_) // might need to update this to actually check if we are in same position as where we started
            {
              signalTaskFinish();
            }
          }
          break;
        }
        case States::PASSING_BUOY: 
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            last_blue_buoy_ = detections;
            publishWPTowardsDetections(detections, p_blue_buoy_str_);
            setTimerDuration(p_max_time_between_buoy_detections_);
          }
          else if(timer_expired_)
          {
            calculateReturnRoute(last_blue_buoy_, getDistFromBay());
            wp_reached_cnt_ = 0;
            status_ = States::RETURNING;
          }
          break;
        }
        case States::RETURNING:
        {
          if (wp_reached_cnt_ >= wps_in_route_) // might need to update this to actually check if we are in same position as where we started
          {
            signalTaskFinish();
          }
          break;
        }
      }
    }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Speed)
