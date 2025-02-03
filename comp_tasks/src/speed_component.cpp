#include "comp_tasks/speed_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"

namespace comp_tasks
{
  Speed::Speed(const rclcpp::NodeOptions & options)
  : Task(options, "speed")
  {
    Speed::getParam<double>("time_to_find_bay", p_time_to_find_bay_, 0.0, "Max time to find first detection with bay before timing out");
    Speed::getParam<double>("max_time_between_bay_detections", p_max_time_between_bay_detections_, 0.0, "Max time to search for bay before moving on");
    Speed::getParam<double>("max_time_between_buoy_detections", p_max_time_between_buoy_detections_, 0.0, "Max time to search for blue buoy before turning around");
    Speed::getParam<double>("buoy_offset_angle", p_buoy_offset_angle_, 0.0, "Angle to offset by when heading to a target in degrees, negative is to the left, positive to the right");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Speed::param_callback, this, std::placeholders::_1));
    status_ = States::SENDING_START_PNT;
    wp_cnt_ = 0;
  }

  rcl_interfaces::msg::SetParametersResult Speed::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "use_start_point") { p_use_start_point_ = params[0].as_int();}
    else if (params[0].get_name() == "time_to_find_bay") { p_time_to_find_bay_ = params[0].as_double();}
    else if (params[0].get_name() == "max_time_between_bay_detections") { p_max_time_between_bay_detections_ = params[0].as_double();}
    else if (params[0].get_name() == "max_time_between_buoy_detections") { p_max_time_between_buoy_detections_ = params[0].as_double();}
    else if (params[0].get_name() == "buoy_offset_angle") { p_buoy_offset_angle_ = params[0].as_double();}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param speed: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateRoute(const yolov8_msgs::msg::DetectionArray& detections, const std::vector<std::reference_wrapper<std::string>>& target_class_names_)
  {
    std::vector<geometry_msgs::msg::Point> route;
    // TODO
    return route;
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateReturnRoute(const yolov8_msgs::msg::DetectionArray& detections)
  {
    std::vector<geometry_msgs::msg::Point> route;
    // TODO
    return route;
  }

  double getDistFromBay()
  {
    double dist;
    // TODO
    return dist;
  }
  void Speed::sendNextWP(std::vector<geometry_msgs::msg::Point> route)
  {
    publishLocalWP(route[wp_cnt_].x, route[wp_cnt_].y);
    wp_reached_ = false;
    wp_cnt_++;
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
            calculated_route_ = calculateRoute(detections, target_class_names_);
            publishWPTowardsGate(detections);
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
            calculated_route_ = calculateRoute(detections, {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_});
          }
          if(timer_expired_)
          {
            sendNextWP(calculated_route_);
            status_ = States::CALCULATED_ROUTE;
          }
          break;
        }
        case States::CALCULATED_ROUTE:
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            status_ = States::PASSING_BUOY;
          }
          else
          {
            if (wp_reached_)
            {
              if (wp_cnt_ >= calculated_route_.size()) // might need to update this to actually check if we are in same position as where we started
              {
                signalTaskFinish();
              }
              else 
              {
                sendNextWP(calculated_route_);
              }
            }
          }
          break;
        }
        case States::PASSING_BUOY: 
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            calculateReturnRoute(detections);
          }
          else if(timer_expired_)
          {
            sendNextWP(return_route_);
            status_ = States::RETURNING;
          }
          break;
        }
        case States::RETURNING:
        {
          if (wp_reached_)
          {
            if (wp_cnt_ >= return_route_.size()) // might need to update this to actually check if we are in same position as where we started
            {
              signalTaskFinish();
            }
            else 
            {
              sendNextWP(return_route_);
            }
          }
          break;
        }
      }
    }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Speed)
