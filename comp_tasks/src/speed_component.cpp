#include "comp_tasks/speed_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"
#include "comp_tasks/lib/task_lib.hpp"

namespace comp_tasks
{
  Speed::Speed(const rclcpp::NodeOptions & options)
  : Task(options, "speed")
  {
    Speed::getParam<double>("time_to_find_bay", p_time_to_find_bay_, 0.0, "Max time to find first detection with bay before timing out");
    Speed::getParam<double>("max_time_between_bay_detections", p_max_time_between_bay_detections_, 0.0, "Max time to search for bay before moving on");
    Speed::getParam<double>("max_time_between_buoy_detections", p_max_time_between_buoy_detections_, 0.0, "Max time to search for blue buoy before turning around");
    Speed::getParam<double>("buoy_offset_angle", p_buoy_offset_angle_, 0.0, "Angle to offset by when heading to a target in degrees, negative is to the left, positive to the right");
    Speed::getParam<double>("estimated_buoy_dist", p_estimated_buoy_dist_, 0.0, "Angle to offset by when heading to a target in degrees, negative is to the left, positive to the right");
    Speed::getParam<double>("buoy_circling_radius", p_buoy_circling_radius_, 0.0, "Circling radius for buoy on calculated route");
    Speed::getParam<int>("num_pnts_on_semicircle", p_num_pnts_on_semicircle_, 0, "How many waypoints to send to turn around buoy on calculated route");
    Speed::getParam<double>("min_dist_from_bay_b4_return", p_min_dist_from_bay_b4_return_, 0.0, "Minimum distance to travel from bay before executing return route");
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
    else if (params[0].get_name() == "estimated_buoy_dist") { p_estimated_buoy_dist_ = params[0].as_double();}
    else if (params[0].get_name() == "buoy_circling_radius") { p_buoy_circling_radius_ = params[0].as_double();}
    else if (params[0].get_name() == "num_pnts_on_semicircle") { p_num_pnts_on_semicircle_ = params[0].as_int();}
    else if (params[0].get_name() == "min_dist_from_bay_b4_return") { p_min_dist_from_bay_b4_return_ = params[0].as_double();}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param speed: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateRouteFromGates(const yolov8_msgs::msg::DetectionArray& detections)
  {
    // get wp for circle center
    double angle = bbox_calculations::getAngleBetween2DiffTargets(detections, p_bbox_selection_, p_red_buoy_str_, p_second_red_buoy_str_,p_green_buoy_str_, p_second_green_buoy_str_, p_camera_fov_, p_camera_res_x_, 0);
    geometry_msgs::msg::PoseStamped wp = task_lib::relativePolarToLocalCoords(p_estimated_buoy_dist_, angle, current_local_pose_);

    // calculate points around center
    std::vector<geometry_msgs::msg::Point> points = task_lib::generateCirclePoints(wp.pose.position, p_buoy_circling_radius_, p_num_pnts_on_semicircle_*2);

    // create a semicircle around the estimated buoy position by cutting out the part of the circle closest to our current position
    std::vector<geometry_msgs::msg::Point> route = task_lib::createSemicirce(points, current_local_pose_.pose.position);

    // add current position to the route so we can get back to the starting point
    route.push_back(current_local_pose_.pose.position);

    return route;
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateReturnRoute(const yolov8_msgs::msg::DetectionArray& detections)
  {
    std::vector<geometry_msgs::msg::Point> route;

    // calculate points around current position
    std::vector<geometry_msgs::msg::Point> points = task_lib::generateCirclePoints(current_local_pose_.pose.position, p_buoy_circling_radius_, p_num_pnts_on_semicircle_*2);
    route = task_lib::createSemicirce(points, last_seen_bay_pose_.pose.position);

    bool left;
    if (bbox_calculations::isLeft(detections, p_blue_buoy_str_, p_camera_fov_, p_camera_res_x_))
    {
      left = true;
    }
    else{
      left = false;
    }
    task_lib::createQuarterCircle(route, task_lib::quaternionToHeading(current_local_pose_.pose.orientation), left);

    route.push_back(last_seen_bay_pose_.pose.position);

    return route;
  }

  void Speed::continuePastBuoy()
  {
    Task::publishLocalWP(this->continue_past_buoys_pnt_.pose.position.x, this->continue_past_buoys_pnt_.pose.position.y);
  }

  bool Speed::isFarEnoughFromBay()
  {
    double dist = task_lib::distBetween2Pnts(last_seen_bay_pose_.pose.position, current_local_pose_.pose.position);
    return p_min_dist_from_bay_b4_return_ > dist;
  }

  double Speed::getDistFromBay()
  {
    double dist = task_lib::distBetween2Pnts(last_seen_bay_pose_.pose.position, last_seen_blue_buoy_pose_.pose.position);
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

          if (bbox_calculations::hasDesiredDetections(detections, {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_}))
          {
            last_seen_bay_pose_ = current_local_pose_;
            if (bbox_calculations::hasGate(detections, p_red_buoy_str_, p_second_red_buoy_str_, p_green_buoy_str_, p_second_green_buoy_str_))
            {
              calculated_route_ = calculateRouteFromGates(detections);
            }
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
            last_seen_bay_pose_ = current_local_pose_;
            if (bbox_calculations::hasGate(detections, p_red_buoy_str_, p_second_red_buoy_str_, p_green_buoy_str_, p_second_green_buoy_str_))
            {
              calculated_route_ = calculateRouteFromGates(detections);
            }
            publishWPTowardsGate(detections);
            setTimerDuration(p_max_time_between_bay_detections_);
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
            last_seen_blue_buoy_pose_ = current_local_pose_;
            publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_);
            continue_past_buoys_pnt_ = getWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_, p_min_dist_from_bay_b4_return_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            status_ = States::PASSING_BUOY;
          }
          else
          {
            if (wp_reached_)
            {
              if (wp_cnt_ >= static_cast<int>(calculated_route_.size())) // might need to update this to actually check if we are in same position as where we started
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
            last_seen_blue_buoy_pose_ = current_local_pose_;
            publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_);
            continue_past_buoys_pnt_ = getWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_, p_min_dist_from_bay_b4_return_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            calculateReturnRoute(detections);
          }
          else if(timer_expired_)
          {
            if (isFarEnoughFromBay())
            {
              sendNextWP(return_route_);
              status_ = States::RETURNING;
            }
            else
            {
              continuePastBuoy();
              status_ = States::CONTINUE_PASSING_BUOY;
            }
          }
          break;
        }
        case States::CONTINUE_PASSING_BUOY: 
        {
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            last_seen_blue_buoy_pose_ = current_local_pose_;
            publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_);
            continue_past_buoys_pnt_ = getWPTowardsLargestTarget(detections, p_blue_buoy_str_, p_buoy_offset_angle_, p_min_dist_from_bay_b4_return_);
            setTimerDuration(p_max_time_between_buoy_detections_);
            status_ = States::PASSING_BUOY;
          }
          else if (isFarEnoughFromBay())
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
            if (wp_cnt_ >= static_cast<int>(return_route_.size())) // might need to update this to actually check if we are in same position as where we started
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
