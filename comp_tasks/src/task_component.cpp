#include "comp_tasks/task_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"
#include "comp_tasks/lib/task_lib.hpp"

namespace comp_tasks
{
  Task::Task(const rclcpp::NodeOptions & options, std::string node_name)
  : Node(node_name, options)
  {
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

    bbox_sub_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>("/yolo/detections", 10, std::bind(&Task::bboxCallback, this, _1));
    wp_reached_sub_ = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&Task::wpReachedCallback, this, _1));
    global_pose_sub_ = this->create_subscription<sensor_msgs::msg::NavSatFix>("/mavros/global_position/global", qos, std::bind(&Task::globalPoseCallback, this, _1));
    local_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&Task::localPoseCallback, this, _1));
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&Task::stateCallback, this, _1));

    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);
    local_wp_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("mavros/setpoint_position/local", 10);
    status_logger_pub_ = this->create_publisher<std_msgs::msg::String>("/comp_tasks/task/status", 10);

    //timer_ = this->create_wall_timer(50ms, std::bind(&Task::timerCallback, this));

    Task::getParam<double>("distance_to_move", p_distance_to_move_, 0.0, "Sets a wp this far away");
    Task::getParam<double>("angle_from_target", p_angle_from_target_, 0.0, "Angles the wp this far from a target buoy");
    Task::getParam<int>("camera_res_x", p_camera_res_x_, 0, "Resolution width of camera");
    Task::getParam<int>("camera_fov", p_camera_fov_, 0, "Camera field of view");
    Task::getParam<double>("finish_lat", p_finish_lat_, 0.0, "Finish latitude");
    Task::getParam<double>("finish_lon", p_finish_lon_, 0.0, "Finish longitude");
    Task::getStringParam("recovery_behaviour", p_recovery_behaviour_, "STOP", "Recovery behaviour");
    Task::getParam<double>("time_to_pause_search", p_time_to_pause_search_, 0.0, "Miliseconds to wait after finding a target before starting to search for new ones");
    Task::getParam<double>("time_between_recovery_actions", p_time_between_recovery_actions_, 0.0, "Miliseconds between executing a recovery action (like sending a waypoint)");
    Task::getParam<double>("time_to_stop_before_recovery", p_time_to_stop_before_recovery_, 0.0, "Miliseconds to stop robot before switching to recovery state if no targets found");
    Task::getStringParam("red_buoy_label", p_red_buoy_str_, "red_buoy", "Red buoy label");
    Task::getStringParam("green_buoy_label", p_green_buoy_str_, "green_buoy", "Green buoy label");
    Task::getStringParam("second_red_buoy_label", p_second_red_buoy_str_, "red_buoy", "Additional red buoy label");
    Task::getStringParam("second_green_buoy_label", p_second_green_buoy_str_, "green_buoy", "Additional green buoy label");
    Task::getParam<int>("frame_stack_size", p_frame_stack_size_, 0, "Number of frames to stack before calculating angle");
    Task::getStringParam("bbox_selection", p_bbox_selection_, "LARGEST", "Selectes either largest or innermost bounding boxes");

    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Task::param_callback, this, std::placeholders::_1));

    bboxes_updated_ = false;
    wp_reached_ = false;
    wp_cnt_ = 0;
    detection_frame_cnt_ = 0;

    if (p_time_to_stop_before_recovery_ == 0.0)
    {
      timer_expired_ = true;
    }
    else 
    {
      setTimerDuration(p_time_to_stop_before_recovery_);
    }

    target_class_names_ = {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_};
  }

  rcl_interfaces::msg::SetParametersResult Task::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_double(); }
    else if (params[0].get_name() == "angle_from_target") { p_angle_from_target_ = params[0].as_double(); }
    else if (params[0].get_name() == "camera_res_x") { p_camera_res_x_ = params[0].as_int(); }
    else if (params[0].get_name() == "camera_fov") { p_camera_fov_ = params[0].as_int(); }
    else if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "red_buoy_label") { p_red_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "recovery_behaviour") { p_recovery_behaviour_ = params[0].as_string(); }
    else if (params[0].get_name() == "time_to_pause_search") { p_time_to_pause_search_ = params[0].as_double(); }
    else if (params[0].get_name() == "time_between_recovery_actions") { p_time_between_recovery_actions_ = params[0].as_double(); }
    else if (params[0].get_name() == "time_to_stop_before_recovery") { p_time_to_stop_before_recovery_ = params[0].as_double(); }
    else if (params[0].get_name() == "green_buoy_label") { p_green_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "second_red_buoy_label") { p_second_red_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "second_green_buoy_label") { p_second_green_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "frame_stack_size") { p_frame_stack_size_ = params[0].as_int(); }
    else if (params[0].get_name() == "bbox_selection") { p_bbox_selection_ = params[0].as_string(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Task::globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
  {
    current_global_pose_ = *msg;
    RCLCPP_DEBUG(this->get_logger(), "Latitude: %f, Longitude: %f", current_global_pose_.latitude, current_global_pose_.longitude);
  }

  void Task::localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    current_local_pose_ = *msg;
    RCLCPP_DEBUG(this->get_logger(), "Local Pose: x: %f, y: %f", msg->pose.position.x, msg->pose.position.y);
  }

  void Task::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    bool prev_guided = in_guided_;
    in_guided_ = task_lib::inGuided(current_state);
    if (in_guided_ && !prev_guided)
    {
      RCLCPP_INFO(this->get_logger(), "In GUIDED");
    }
    else if (!in_guided_)
    {
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Waiting for GUIDED");
    }
    return;
  }

  void Task::wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
    mavros_msgs::msg::WaypointReached wpr = msg;
    wp_reached_ = true;
  }

  void Task::bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
  {
    yolov8_msgs::msg::DetectionArray new_detections = *msg;
    stacked_detections_.detections.insert(stacked_detections_.detections.end(), new_detections.detections.begin(), new_detections.detections.end());
    detection_frame_cnt_++;
    if (detection_frame_cnt_ >= p_frame_stack_size_)
    {
      this->taskLogic(stacked_detections_);
      detection_frame_cnt_ = 0;
      stacked_detections_.detections.clear();
    }
  }

  void Task::publishSearchStatus(std::string str_msg)
  {
    std_msgs::msg::String msg;
    msg.data = "SEARCH STATUS: " + str_msg;
    status_logger_pub_->publish(msg);
  }
  void Task::publishBehaviourStatus(std::string str_msg)
  {
    std_msgs::msg::String msg;
    msg.data = "BEHAVIOUR STATUS: " + str_msg;
    status_logger_pub_->publish(msg);
  }

  void Task::publishWPTowardsDetections(const yolov8_msgs::msg::DetectionArray& detections)
  {
    wp_reached_ = false;
    publishSearchStatus("Found");
    double angle = bbox_calculations::getAngleBetween2DiffTargets(detections, p_bbox_selection_, p_red_buoy_str_, p_second_red_buoy_str_,p_green_buoy_str_, p_second_green_buoy_str_, p_camera_fov_, p_camera_res_x_, p_angle_from_target_);
    geometry_msgs::msg::PoseStamped wp = task_lib::relativePolarToLocalCoords(p_distance_to_move_, angle, current_local_pose_);
    if (wp.pose.position.x != 0 && wp.pose.position.y != 0)
    {
      local_wp_pub_->publish(wp);
      wp_cnt_++;
      std::string str_cnt = std::to_string(wp_cnt_);
      publishBehaviourStatus("Heading to WP " + str_cnt);
    }
    else{
      RCLCPP_WARN(this->get_logger(), "Waypoint Empty - not publishing"); 
    }

    if (p_time_to_pause_search_ != 0.0) 
    {
      setTimerDuration(p_time_to_pause_search_);
    }
    else
    {
      timer_expired_ = true;
    }
  }

  void Task::publishFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(p_finish_lat_, p_finish_lon_);
    global_wp_pub_->publish(finish_wp);
    RCLCPP_DEBUG(this->get_logger(), "Finish WP: lat=%f, lon=%f", finish_wp.pose.position.latitude, finish_wp.pose.position.longitude);
  }

  void Task::executeRecoveryBehaviour()
  {
    if (p_recovery_behaviour_ == "STOP")
    {

    }
    else if (p_recovery_behaviour_ == "STRAIGHT")
    {

    }
    else if (p_recovery_behaviour_ == "FINISH_PNT")
    {

    }
    return;
  }

  void Task::setTimerDuration(double duration)
  {
    timer_expired_ = false;

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double, std::milli>(duration * 1000));
    timer_ = this->create_wall_timer(
        ms, std::bind(&Task::onTimerExpired, this));
    RCLCPP_DEBUG(this->get_logger(), "Timer set to %f ms", duration); 
  }
  void Task::onTimerExpired()
  {
      RCLCPP_DEBUG(this->get_logger(), "Times up"); 
      timer_expired_ = true;
  }

}

