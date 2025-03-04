#include "comp_tasks/speed_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"
#include "comp_tasks/lib/task_lib.hpp"
bool isWithinDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2, double dist) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  double dz = p1.z - p2.z;
  return (dx * dx + dy * dy + dz * dz) <= (dist * dist);
}

void removeClosePoints(std::vector<geometry_msgs::msg::Point>& points, 
                     const geometry_msgs::msg::Point& reference_point, 
                     double dist) {
  points.erase(std::remove_if(points.begin(), points.end(),
              [&](const geometry_msgs::msg::Point& p) {
                  return isWithinDistance(p, reference_point, dist);
              }),
              points.end());
}
namespace comp_tasks
{
  Speed::Speed(const rclcpp::NodeOptions & options)
  : Task(options, "speed")
  {
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Speed::on_configure(const rclcpp_lifecycle::State &)
  {
    RCLCPP_DEBUG(this->get_logger(), "on_configure speed callback");

    Task::on_configure(rclcpp_lifecycle::State());
  
    Speed::getParam<double>("time_to_find_bay", p_time_to_find_bay_, 0.0, "Max time to find first detection with bay before timing out");
    Speed::getParam<double>("max_time_between_bay_detections", p_max_time_between_bay_detections_, 0.0, "Max time to search for bay before moving on");
    Speed::getParam<double>("max_time_between_buoy_detections", p_max_time_between_buoy_detections_, 0.0, "Max time to search for blue buoy before turning around");
    Speed::getParam<double>("buoy_offset_angle", p_buoy_offset_angle_, 0.0, "Angle to offset by when heading to a target in degrees, negative is to the left, positive to the right");
    Speed::getParam<double>("estimated_buoy_dist", p_estimated_buoy_dist_, 0.0, "Angle to offset by when heading to a target in degrees, negative is to the left, positive to the right");
    Speed::getParam<double>("buoy_circling_radius", p_buoy_circling_radius_, 0.0, "Circling radius for buoy on calculated route");
    Speed::getParam<int>("num_pnts_on_semicircle", p_num_pnts_on_semicircle_, 0, "How many waypoints to send to turn around buoy on calculated route");
    Speed::getParam<double>("min_dist_from_bay_b4_return", p_min_dist_from_bay_b4_return_, 0.0, "Minimum distance to travel from bay before executing return route");
    Speed::getParam<int>("use_start_point", p_use_start_point_, 0, "Use start point or wait to detect gate");
    Speed::getParam<double>("remove_wp_within_dist", p_remove_wp_within_dist_, 0.0, "Remove WPs within this distance of current position from pre-calculated routes");
    Speed::getStringParam("state", p_state_, "SENDING_START_PNT", "State machine state");

    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Speed::param_callback, this, std::placeholders::_1));
    setState(p_state_);
    wp_cnt_ = 0;
    node_state_ = "SENDING_START_PNT";
    first_seen_bay_pose_.pose.position.x = 0;
    first_seen_bay_pose_.pose.position.y = 0;

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rcl_interfaces::msg::SetParametersResult Speed::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (Task::param_callback(params).successful) {}
    else if (params[0].get_name() == "use_start_point") { p_use_start_point_ = params[0].as_int(); updateYamlParam("use_start_point", params[0].as_int());}
    else if (params[0].get_name() == "time_to_find_bay") { p_time_to_find_bay_ = params[0].as_double(); updateYamlParam("time_to_find_bay", params[0].as_double());}
    else if (params[0].get_name() == "max_time_between_bay_detections") { p_max_time_between_bay_detections_ = params[0].as_double(); updateYamlParam("max_time_between_bay_detections", params[0].as_double());}
    else if (params[0].get_name() == "max_time_between_buoy_detections") { p_max_time_between_buoy_detections_ = params[0].as_double(); updateYamlParam("max_time_between_buoy_detections", params[0].as_double());} 
    else if (params[0].get_name() == "buoy_offset_angle") { p_buoy_offset_angle_ = params[0].as_double(); updateYamlParam("buoy_offset_angle", params[0].as_double());}
    else if (params[0].get_name() == "estimated_buoy_dist") { p_estimated_buoy_dist_ = params[0].as_double();updateYamlParam("estimated_buoy_dist", params[0].as_double());}
    else if (params[0].get_name() == "buoy_circling_radius") { p_buoy_circling_radius_ = params[0].as_double(); updateYamlParam("buoy_circling_radius", params[0].as_double());}
    else if (params[0].get_name() == "num_pnts_on_semicircle") { p_num_pnts_on_semicircle_ = params[0].as_int(); updateYamlParam("num_pnts_on_semicircle", params[0].as_int());}
    else if (params[0].get_name() == "min_dist_from_bay_b4_return") { p_min_dist_from_bay_b4_return_ = params[0].as_double(); updateYamlParam("min_dist_from_bay_b4_return", params[0].as_double());}
    else if (params[0].get_name() == "remove_wp_within_dist") { p_remove_wp_within_dist_ = params[0].as_double(); updateYamlParam("remove_wp_within_dist", params[0].as_double());}
    else if (params[0].get_name() == "state") { setState(params[0].as_string()); updateYamlParam("state", params[0].as_string());}
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param speed: %s", params[0].get_name().c_str());
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Speed::setState(std::string str_state)
  {
    if (str_state == "SENDING_START_PNT")
    {
      node_state_ = "SENDING_START_PNT";
      setTimerDuration(p_time_to_find_bay_, "time to find bay");
      state_ = States::SENDING_START_PNT;
    }
    else if (str_state == "MANEUVER_THRU_BAY")
    {
      node_state_ = "MANEUVER_THRU_BAY";
      setTimerDuration(p_max_time_between_bay_detections_, "max time between bay detections");
      state_ = States::MANEUVER_THRU_BAY;
    }
    else if (str_state == "RETURNING")
    {
      node_state_ = "RETURNING";
      state_ = States::RETURNING;
    }
    else if (str_state == "GOING_STRAIGHT")
    {
      node_state_ = "GOING_STRAIGHT";
      state_ = States::GOING_STRAIGHT;
    }
    else if (str_state == "CONTINUE_PASSING_BUOY")
    {
      node_state_ = "CONTINUE_PASSING_BUOY";
      state_ = States::CONTINUE_PASSING_BUOY;
    }
    else if (str_state == "PASSING_BUOY")
    {
      node_state_ = "PASSING_BUOY";
      setTimerDuration(p_max_time_between_buoy_detections_, "max time between buoy detections");
      state_ = States::PASSING_BUOY;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Invalid State: %s", str_state.c_str());
    }
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateRouteFromGates(const yolov8_msgs::msg::DetectionArray& detections)
  {
    // get wp for circle center
    double angle = bbox_calculations::getAngleBetween2DiffTargets(detections, p_bbox_selection_, p_red_buoy_str_, p_second_red_buoy_str_,p_green_buoy_str_, p_second_green_buoy_str_, p_camera_fov_, p_camera_res_x_, 0);
    geometry_msgs::msg::PoseStamped wp = task_lib::relativePolarToLocalCoords(p_estimated_buoy_dist_, angle, current_local_pose_);

    std::vector<geometry_msgs::msg::Point> route;
    route.push_back(wp.pose.position);
    route.push_back(last_seen_bay_pose_.pose.position);
    route.push_back(first_seen_bay_pose_.pose.position);

    calculated_route_detections_ = detections;

    return route;
  }

  std::vector<geometry_msgs::msg::Point> Speed::calculateReturnRoute(const yolov8_msgs::msg::DetectionArray& detections)
  {
    std::vector<geometry_msgs::msg::Point> semi;
    
    std::vector<geometry_msgs::msg::Point> points = task_lib::generateCirclePoints(current_local_pose_.pose.position, p_buoy_circling_radius_, p_num_pnts_on_semicircle_*2);
    semi = task_lib::createSemicirce(points, last_seen_bay_pose_.pose.position);
    //task_lib::writePointsToCSV(semi, "/home/gracepearcey/repos/iceberg/ros2_ws/src/general/comp_tasks/routes/bb_semi.csv");
    passed_buoy_left_ = bbox_calculations::isLeft(detections, p_blue_buoy_str_, p_camera_fov_, p_camera_res_x_);
    return_route_detections_ = detections;
    return semi;
  }


  void Speed::updateReturnRoute(std::vector<geometry_msgs::msg::Point>& route)
  {
    route = task_lib::translateSemicircle(route, current_local_pose_.pose.position, passed_buoy_left_);

    if (passed_buoy_left_)
    {
      std::reverse(route.begin(), route.end());
    }

    removeClosePoints(route, current_local_pose_.pose.position, p_remove_wp_within_dist_);

    route.push_back(last_seen_bay_pose_.pose.position);
    route.push_back(first_seen_bay_pose_.pose.position);

    //task_lib::writePointsToCSV(route, "/home/gracepearcey/repos/iceberg/ros2_ws/src/general/comp_tasks/routes/bb.csv");
  }

  void Speed::continuePastBuoy()
  {
    Task::publishLocalWP(this->continue_past_buoys_pnt_.pose.position.x, this->continue_past_buoys_pnt_.pose.position.y);
  }

  bool Speed::isFarEnoughFromBay()
  {
    double dist = task_lib::distBetween2Pnts(last_seen_bay_pose_.pose.position, current_local_pose_.pose.position);
    RCLCPP_DEBUG(this->get_logger(), "Dist traveled from last seen gate %f, min dist from gate %f", dist, p_min_dist_from_bay_b4_return_); 
    publishBehaviourStatus("Traveled " + task_lib::toStringWithTwoDecimals(dist) + " of min " + task_lib::toStringWithTwoDecimals(p_min_dist_from_bay_b4_return_) + " from bay");
    return dist > p_min_dist_from_bay_b4_return_;
  }

  double Speed::getDistFromBay()
  {
    double dist = task_lib::distBetween2Pnts(last_seen_bay_pose_.pose.position, last_seen_blue_buoy_pose_.pose.position);
    return dist;
  }
  void Speed::sendNextWP(std::vector<geometry_msgs::msg::Point> route, std::string route_name)
  {
    std::string behaviour = "Pub WP " + std::to_string(wp_cnt_ + 1) + "/" + std::to_string(route.size()) + " of route from " + route_name;    
    publishBehaviourStatus(behaviour);
    publishLocalWP(route[wp_cnt_].x, route[wp_cnt_].y);
    wp_reached_ = false;
  }

  void Speed::handleGateDetections(const yolov8_msgs::msg::DetectionArray& detections)
  {
    publishBehaviourStatus("Going towards gate");
    if (bbox_calculations::hasGate(detections, p_red_buoy_str_, p_second_red_buoy_str_, p_green_buoy_str_, p_second_green_buoy_str_))
    {
      last_seen_bay_pose_ = current_local_pose_;
      if (first_seen_bay_pose_.pose.position.x == 0 && first_seen_bay_pose_.pose.position.y == 0)
      {
        first_seen_bay_pose_ = current_local_pose_;
      }
      calculated_route_ = calculateRouteFromGates(detections);
      publishSearchStatus("Found gate");
    }
    else if (bbox_calculations::hasDesiredDetections(detections, {p_red_buoy_str_, p_second_red_buoy_str_}))
    {
      publishSearchStatus("Found " + p_red_buoy_str_);
    }
    else{
      publishSearchStatus("Found " + p_green_buoy_str_);
    }
    publishWPTowardsGate(detections);
    if (p_time_to_pause_search_ != 0)
    {
      std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(p_time_to_pause_search_)));
    }
    setTimerDuration(p_max_time_between_bay_detections_, "max time between bay detections");
  }

  void Speed::handleBlueBuoyDetections(const yolov8_msgs::msg::DetectionArray& detections)
  {
    publishBehaviourStatus("Going towards blue buoy");
    publishSearchStatus("Found " + p_blue_buoy_str_);
    double offset_angle_corrected;
    return_route_ = calculateReturnRoute(detections);
    passed_buoy_left_ ? offset_angle_corrected = p_buoy_offset_angle_ : offset_angle_corrected = -p_buoy_offset_angle_;
    last_seen_blue_buoy_pose_ = current_local_pose_;
    RCLCPP_DEBUG(this->get_logger(), "buoy_offset angle %f", offset_angle_corrected);
    RCLCPP_INFO(this->get_logger(), "Detected blue buoy - heading towards it with offset of %f", offset_angle_corrected);
    publishWPTowardsLargestTarget(detections, p_blue_buoy_str_, offset_angle_corrected);
    continue_past_buoys_pnt_ = getWPTowardsLargestTarget(detections, p_blue_buoy_str_, offset_angle_corrected, p_min_dist_from_bay_b4_return_);
    if (p_time_to_pause_search_ != 0)
    {
      std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(p_time_to_pause_search_)));
    }
    setTimerDuration(p_max_time_between_buoy_detections_, "max time between buoy detections");
  }

  void Speed::taskLogic(const yolov8_msgs::msg::DetectionArray& detections)
  {
    if (in_guided_)
    {
      switch (state_)
      {
        case States::SENDING_START_PNT:
        {
          RCLCPP_DEBUG(this->get_logger(), "SENDING_START_PNT"); 
          publishStateStatus("SENDING_START_PNT");
          publishSearchStatus("");
          if (p_use_start_point_)
          {
            publishBehaviourStatus("Going to start point");
            publishStartPoint();
          }
          setTimerDuration(p_time_to_find_bay_, "time to find bay");
          node_state_ = "MANEUVER_THRU_BAY";
          state_ = States::MANEUVER_THRU_BAY;
          break;
        }
        case States::MANEUVER_THRU_BAY: 
        {
          RCLCPP_DEBUG(this->get_logger(), "MANEUVER_THRU_BAY"); 
          publishStateStatus("MANEUVER_THRU_BAY");
          publishSearchStatus("Searching for Gates");
          if(bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            handleBlueBuoyDetections(detections);
            node_state_ = "PASSING_BUOY";
            state_ = States::PASSING_BUOY;
          }
          else if (bbox_calculations::hasDesiredDetections(detections, {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_}))
          {
            handleGateDetections(detections);
          }
          else if(timer_expired_)
          {
            if (calculated_route_.size() == 0)
            {
              RCLCPP_WARN(this->get_logger(), "Did not find gate to calculate route"); 
              signalTaskFinish();
            }
            else
          {
            wp_cnt_ = 0;
            sendNextWP(calculated_route_, "gate");
            publishWpGroupInfo(calculated_route_, calculated_route_detections_, "calculated route");
            node_state_ = "GOING_STRAIGHT";
            state_ = States::GOING_STRAIGHT;
            }
          }
          break;
        }
        case States::GOING_STRAIGHT:
        {
          RCLCPP_DEBUG(this->get_logger(), "GOING_STRAIGHT"); 
          publishStateStatus("GOING_STRAIGHT");
          publishSearchStatus("Searching for Blue Buoy");
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            handleBlueBuoyDetections(detections);
            node_state_ = "PASSING_BUOY";
            state_ = States::PASSING_BUOY;
          }
          else
          {
            if (wp_reached_)
            {
              RCLCPP_INFO(this->get_logger(), "WP count: %d, route length: %ld", wp_cnt_, calculated_route_.size());
              if (wp_cnt_ >= static_cast<int>(calculated_route_.size())) // might need to update this to actually check if we are in same position as where we started
              {
                RCLCPP_INFO(this->get_logger(), "Reached all WPs in calculated route, finishing");
                signalTaskFinish();
              }
              else 
              {
                sendNextWP(calculated_route_, "gate");
              }
            }
          }
          break;
        }
        case States::PASSING_BUOY: 
        {
          RCLCPP_DEBUG(this->get_logger(), "PASSING_BUOY"); 
          publishStateStatus("PASSING_BUOY");
          publishSearchStatus("Searching for Blue Buoy");
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            handleBlueBuoyDetections(detections);
          }
          else if(timer_expired_)
          {
            if (isFarEnoughFromBay())
            { 
              if (return_route_.size() == 0)
              {
                RCLCPP_WARN(this->get_logger(), "Did not find blue buoy to calculate return route, finishing");
                signalTaskFinish();
              }
              else
              {
                wp_cnt_ = 0;
                updateReturnRoute(return_route_);
                sendNextWP(return_route_, "buoy");
                std::string buoy_position = passed_buoy_left_ ? "left" : "right";
                publishBehaviourStatus("Buoy is to the " + buoy_position);
                publishWpGroupInfo(return_route_, return_route_detections_, "return route");
                node_state_ = "RETURNING";
                state_ = States::RETURNING;
              }
            }
            else
            {
              continuePastBuoy();
              state_ = States::CONTINUE_PASSING_BUOY;
            }
          }
          break;
        }
        case States::CONTINUE_PASSING_BUOY: 
        {
          RCLCPP_DEBUG(this->get_logger(), "CONTINUE_PASSING_BUOY"); 
          publishStateStatus("CONTINUE_PASSING_BUOY");
          publishBehaviourStatus("Going min distance needed to 'pass buoy'");
          publishSearchStatus("Searching for Blue Buoy");
          if (bbox_calculations::hasDesiredDetections(detections, {p_blue_buoy_str_}))
          {
            handleBlueBuoyDetections(detections);
            node_state_ = "PASSING_BUOY";
            state_ = States::PASSING_BUOY;
          }
          else if (isFarEnoughFromBay())
          {
            if (return_route_.size() == 0)
            {
              RCLCPP_WARN(this->get_logger(), "Return route empty, finishing");
              signalTaskFinish();
            }
            else
            {
              wp_cnt_ = 0;
              updateReturnRoute(return_route_);
              sendNextWP(return_route_, "buoy");
              std::string buoy_position = passed_buoy_left_ ? "left" : "right";
              publishBehaviourStatus("Buoy is to the " + buoy_position);
              publishWpGroupInfo(return_route_, return_route_detections_, "return route");
              node_state_ = "RETURNING";
              state_ = States::RETURNING;
            }
          }
          break;
        }
        case States::RETURNING:
        {
          RCLCPP_DEBUG(this->get_logger(), "RETURNING"); 
          publishStateStatus("RETURNING");
          publishSearchStatus("");
          if (wp_reached_)
          {
            if (wp_cnt_ >= static_cast<int>(return_route_.size())) // might need to update this to actually check if we are in same position as where we started
            {
              RCLCPP_INFO(this->get_logger(), "Reached all WPs in return route, finishing");
              signalTaskFinish();
            }
            else 
            {
              sendNextWP(return_route_, "buoy");
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
