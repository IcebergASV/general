#include "comp_tasks/task_component.hpp"
#include "comp_tasks/lib/bbox_calculations.hpp"
#include "comp_tasks/lib/task_lib.hpp"

namespace comp_tasks
{
  Task::Task(const rclcpp::NodeOptions & options, std::string node_name)
  : rclcpp_lifecycle::LifecycleNode(node_name, options)
  {
    bboxes_updated_ = false;
    wp_reached_ = false;
    activated_ = false;
    wp_cnt_ = 0;
    detection_frame_cnt_ = 0;
    target_class_names_ = {p_red_buoy_str_, p_green_buoy_str_, p_second_red_buoy_str_, p_second_green_buoy_str_};
  }

  rcl_interfaces::msg::SetParametersResult Task::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_double(); updateYamlParam("distance_to_move", params[0].as_double());}
    else if (params[0].get_name() == "angle_from_target") { p_angle_from_target_ = params[0].as_double(); updateYamlParam("angle_from_target", params[0].as_double());}
    else if (params[0].get_name() == "camera_res_x") { p_camera_res_x_ = params[0].as_int(); updateYamlParam("camera_res_x", params[0].as_int());}
    else if (params[0].get_name() == "camera_fov") { p_camera_fov_ = params[0].as_int(); updateYamlParam("camera_fov", params[0].as_int());}
    else if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); updateYamlParam("finish_lat", params[0].as_double());}
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); updateYamlParam("finish_lon", params[0].as_double());}
    else if (params[0].get_name() == "recovery_lat") { p_recovery_lat_ = params[0].as_double(); updateYamlParam("recovery_lat", params[0].as_double());}
    else if (params[0].get_name() == "recovery_lon") { p_recovery_lon_ = params[0].as_double(); updateYamlParam("recovery_lon", params[0].as_double());}
    else if (params[0].get_name() == "start_lat") { p_start_lat_ = params[0].as_double(); updateYamlParam("start_lat", params[0].as_double());}
    else if (params[0].get_name() == "start_lon") { p_start_lon_ = params[0].as_double(); updateYamlParam("start_lon", params[0].as_double());}
    else if (params[0].get_name() == "red_buoy_label") { p_red_buoy_str_ = params[0].as_string(); updateYamlParam("red_buoy_label", params[0].as_string());}
    else if (params[0].get_name() == "recovery_behaviour") { p_recovery_behaviour_ = params[0].as_string(); updateYamlParam("recovery_behaviour", params[0].as_string());}
    else if (params[0].get_name() == "green_buoy_label") { p_green_buoy_str_ = params[0].as_string(); updateYamlParam("green_buoy_label", params[0].as_string());}
    else if (params[0].get_name() == "second_red_buoy_label") { p_second_red_buoy_str_ = params[0].as_string(); updateYamlParam("second_red_buoy_label", params[0].as_string());}
    else if (params[0].get_name() == "second_green_buoy_label") { p_second_green_buoy_str_ = params[0].as_string(); updateYamlParam("second_green_buoy_label", params[0].as_string());}
    else if (params[0].get_name() == "blue_buoy_label") { p_blue_buoy_str_ = params[0].as_string(); updateYamlParam("blue_buoy_label", params[0].as_string());}
    else if (params[0].get_name() == "second_blue_buoy_label") { p_second_blue_buoy_str_ = params[0].as_string(); updateYamlParam("second_blue_buoy_label", params[0].as_string());}    
    else if (params[0].get_name() == "black_buoy_label") { p_black_buoy_str_ = params[0].as_string(); updateYamlParam("black_buoy_label", params[0].as_string());}    
    else if (params[0].get_name() == "frame_stack_size") { p_frame_stack_size_ = params[0].as_int(); updateYamlParam("frame_stack_size", params[0].as_int());}
    else if (params[0].get_name() == "bbox_selection") { p_bbox_selection_ = params[0].as_string(); updateYamlParam("bbox_selection", params[0].as_string());}
    else if (params[0].get_name() == "time_to_pause_search") { p_time_to_pause_search_ = params[0].as_double(); updateYamlParam("time_to_pause_search", params[0].as_double());}
    else if (params[0].get_name() == "target_offset") { p_target_offset_ = params[0].as_double(); updateYamlParam("target_offset", params[0].as_double());}
    else {
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Task::on_configure(const rclcpp_lifecycle::State &)
  {
    RCLCPP_DEBUG(this->get_logger(), "on_configure callback");
  
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

    bbox_sub_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>("/icebergcv/detections", 10, std::bind(&Task::bboxCallback, this, _1));
    wp_reached_sub_ = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&Task::wpReachedCallback, this, _1));
    global_pose_sub_ = this->create_subscription<sensor_msgs::msg::NavSatFix>("/mavros/global_position/global", qos, std::bind(&Task::globalPoseCallback, this, _1));
    local_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&Task::localPoseCallback, this, _1));
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&Task::stateCallback, this, _1));

    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);
    local_wp_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("mavros/setpoint_position/local", 10);
    status_logger_pub_ = this->create_publisher<std_msgs::msg::String>("/comp_tasks/task/status", 10);
    task_complete_pub_ = this->create_publisher<std_msgs::msg::Bool>("/comp_tasks/task/complete", 10);
    timer_cntdwn_pub_ = this->create_publisher<comp_tasks_interfaces::msg::LabelInt>("/comp_tasks/task/timer", 10);
    wp_info_pub_ = this->create_publisher<comp_tasks_interfaces::msg::WpInfo>("/comp_tasks/wp_info", 10);
    global_wp_info_pub_ = this->create_publisher<comp_tasks_interfaces::msg::GlobalWpInfo>("/comp_tasks/global_wp_info", 10);
    wp_group_info_pub_ = this->create_publisher<comp_tasks_interfaces::msg::WpGroupInfo>("/comp_tasks/wp_group_info", 10);

    Task::getParam<double>("distance_to_move", p_distance_to_move_, 0.0, "Sets a wp this far away");
    Task::getParam<double>("angle_from_target", p_angle_from_target_, 0.0, "Angles the wp this far from a target buoy");
    Task::getParam<int>("camera_res_x", p_camera_res_x_, 0, "Resolution width of camera");
    Task::getParam<int>("camera_fov", p_camera_fov_, 0, "Camera field of view");
    Task::getParam<double>("finish_lat", p_finish_lat_, 0.0, "Finish latitude");
    Task::getParam<double>("finish_lon", p_finish_lon_, 0.0, "Finish longitude");
    Task::getParam<double>("recovery_lat", p_recovery_lat_, 0.0, "Recovery latitude");
    Task::getParam<double>("recovery_lon", p_recovery_lon_, 0.0, "Recovery longitude");
    Task::getParam<double>("start_lat", p_start_lat_, 0.0, "Start latitude");
    Task::getParam<double>("start_lon", p_start_lon_, 0.0, "Start longitude");
    Task::getStringParam("recovery_behaviour", p_recovery_behaviour_, "STOP", "Recovery behaviour");
    Task::getStringParam("red_buoy_label", p_red_buoy_str_, "red_buoy", "Red buoy label");
    Task::getStringParam("green_buoy_label", p_green_buoy_str_, "green_buoy", "Green buoy label");
    Task::getStringParam("second_red_buoy_label", p_second_red_buoy_str_, "red_buoy", "Additional red buoy label");
    Task::getStringParam("blue_buoy_label", p_blue_buoy_str_, "blue_buoy", "Blue buoy label");
    Task::getStringParam("black_buoy_label", p_black_buoy_str_, "black_buoy", "Black buoy label");
    Task::getStringParam("second_blue_buoy_label", p_second_blue_buoy_str_, "blue_buoy", "Additional blue buoy label");
    Task::getStringParam("second_green_buoy_label", p_second_green_buoy_str_, "green_buoy", "Additional green buoy label");
    Task::getParam<int>("frame_stack_size", p_frame_stack_size_, 0, "Number of frames to stack before calculating angle");
    Task::getStringParam("bbox_selection", p_bbox_selection_, "LARGEST", "Selectes either largest or innermost bounding boxes");
    Task::getParam<double>("time_to_pause_search", p_time_to_pause_search_, 0.0, "Miliseconds to wait after finding a target before starting to search for new ones");
    Task::getParam<double>("target_offset", p_target_offset_, 0.0, "Miliseconds to wait after finding a target before starting to search for new ones");

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Task::on_activate(const rclcpp_lifecycle::State & )
  {
    RCLCPP_DEBUG(this->get_logger(), "on_activate callback");
    activated_ = true;
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Task::on_deactivate(const rclcpp_lifecycle::State & )
  {
    RCLCPP_DEBUG(this->get_logger(), "on_deactivate callback");
    activated_ = false;
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Task::on_cleanup(const rclcpp_lifecycle::State &)
  {
    RCLCPP_DEBUG(this->get_logger(), "on_cleanup callback");
    global_pose_sub_.reset();
    local_pose_sub_.reset();
    bbox_sub_.reset();
    global_wp_pub_.reset();
    local_wp_pub_.reset();
    wp_reached_sub_.reset();
    status_logger_pub_.reset();
    state_sub_.reset();
    task_complete_pub_.reset();
    timer_cntdwn_pub_.reset();
    timer_.reset();
    countdown_timer_.reset();
    on_set_parameters_callback_handle_.reset();
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Task::on_shutdown(const rclcpp_lifecycle::State &)
  {
    RCLCPP_DEBUG(this->get_logger(), "on_shutdown callback");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  void Task::globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
  {
    current_global_pose_ = *msg;
  }

  bool Task::isActive() {
    auto state = this->get_current_state();
    if (state.id() == lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE) {
        return true;
    }
    return false;
  }

  void Task::localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    current_local_pose_ = *msg;
  }

  void Task::updateYamlParamForDiffNode(const std::string &paramName, double newValue, std::string node_name, std::string filename) {
    if (isActive()){
      try {
          std::string nodeName = "/" + node_name;
          std::filesystem::path current_file(__FILE__); 
          std::filesystem::path package_path = current_file.parent_path().parent_path();

          std::string file_path = package_path.string() + "/config/" + filename;

          // Load the YAML file
          YAML::Node config = YAML::LoadFile(file_path);
    
          // Check if the node and parameter exist
          if (!config[nodeName]) {
              std::cerr << "Error: Node " << nodeName << " not found in YAML file." << std::endl;
              return;
          }

          // Check if the node and parameter exist
          if (!config[nodeName] || !config[nodeName]["ros__parameters"] || !config[nodeName]["ros__parameters"][paramName]) {
              std::cerr << "Error: Parameter " << paramName << " not found in YAML file." << std::endl;
              return;
          }
    
            // Update the parameter value
          std::ostringstream oss;
          oss << std::fixed << std::setprecision(10) << newValue;
          config[nodeName]["ros__parameters"][paramName] = oss.str();

    
          // Write back to file
          std::ofstream outFile(file_path);
          if (!outFile) {
              std::cerr << "Error: Unable to open file for writing." << std::endl;
              return;
          }
          outFile << config;
          outFile.close();
    
          std::cout << "Successfully updated " << paramName << " to "<< newValue << std::endl;
      } catch (const std::exception &e) {
          std::cerr << "Exception: " << e.what() << std::endl;
      }
    }
  }

  void Task::setReturnToHomePnt()
  {
    updateYamlParamForDiffNode("recovery_lat", this->current_global_pose_.latitude, "home", "gps_points.yaml");
    updateYamlParamForDiffNode("recovery_lon", this->current_global_pose_.longitude, "home", "gps_points.yaml");
  }

  void Task::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    bool prev_guided = in_guided_;
    in_guided_ = task_lib::inGuided(current_state);
    in_hold_ = task_lib::inHold(current_state);
    in_manual_ = task_lib::inManual(current_state);
    if (in_manual_ && prev_guided){
      wp_cnt_ = 0;
    }
    if (in_guided_ && !prev_guided)
    {
      RCLCPP_INFO(this->get_logger(), "In GUIDED");
      if(this->get_name() == std::string("maneuvering")){
        setReturnToHomePnt();
      }
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
      RCLCPP_DEBUG(this->get_logger(), "Frame stack");
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
  void Task::publishStateStatus(std::string str_msg)
  {
    std_msgs::msg::String msg;
    msg.data = "STATE: " + str_msg;
    status_logger_pub_->publish(msg);
  }

  //Returns 0, 0 if no valid detections
  geometry_msgs::msg::Point Task::publishWPTowardsGate(const yolov8_msgs::msg::DetectionArray& detections)
  {
    geometry_msgs::msg::PoseStamped wp;
    if (activated_){
      RCLCPP_DEBUG(this->get_logger(), "Publishing waypoint towards gate");
      wp_reached_ = false;
      double angle = bbox_calculations::getAngleBetween2DiffTargets(detections, p_bbox_selection_, p_red_buoy_str_, p_second_red_buoy_str_,p_green_buoy_str_, p_second_green_buoy_str_, p_camera_fov_, p_camera_res_x_, p_angle_from_target_, p_target_offset_);
      wp = task_lib::relativePolarToLocalCoords(p_distance_to_move_, angle, current_local_pose_);
      publishLocalWP(wp.pose.position.x, wp.pose.position.y);
    }
    else{
      RCLCPP_WARN(this->get_logger(), "Task not activated - not publishing waypoint towards gate");
    }
    return wp.pose.position;
  }

  //Returns 0, 0 if no valid detections
  geometry_msgs::msg::Point Task::publishWPTowardsBlackBuoyGate(const yolov8_msgs::msg::DetectionArray& detections)
  {
    geometry_msgs::msg::PoseStamped wp;
    if (activated_){
      RCLCPP_DEBUG(this->get_logger(), "Publishing waypoint towards gate");
      wp_reached_ = false;
      double angle = bbox_calculations::getAngleBetween2SameTargets(detections, p_black_buoy_str_, p_camera_fov_, p_camera_res_x_);
      wp = task_lib::relativePolarToLocalCoords(p_distance_to_move_, angle, current_local_pose_);
      publishLocalWP(wp.pose.position.x, wp.pose.position.y);
    }
    else{
      RCLCPP_WARN(this->get_logger(), "Task not activated - not publishing waypoint towards gate");
    }
    return wp.pose.position;
  }

  // negative angle is to the left of the target, positive angle is to the right of target
  geometry_msgs::msg::PoseStamped Task::publishWPTowardsLargestTarget(const yolov8_msgs::msg::DetectionArray& detections, std::string target_label, double offset_angle)
  {
    geometry_msgs::msg::PoseStamped wp;
    if (activated_){
      wp_reached_ = false;

      wp = getWPTowardsLargestTarget(detections, target_label, offset_angle, p_distance_to_move_);
      publishLocalWP(wp.pose.position.x, wp.pose.position.y);
    }
    return wp;
  }

  geometry_msgs::msg::PoseStamped Task::getWPTowardsLargestTarget(const yolov8_msgs::msg::DetectionArray& detections, std::string target_label, double offset_angle, double dist) //TODO move to lib
  {
    double angle = bbox_calculations::getAngleToLargestTarget(detections, target_label, p_camera_fov_, p_camera_res_x_);
    angle += offset_angle*M_PI/180;
    geometry_msgs::msg::PoseStamped wp = task_lib::relativePolarToLocalCoords(dist, angle, current_local_pose_);
    return wp;
  }
  void Task::publishRecoveryPoint()
  {
    RCLCPP_INFO(this->get_logger(), "Publishing recovery point %f, %f", p_recovery_lat_, p_recovery_lon_);
    publishGlobalWP(p_recovery_lat_, p_recovery_lon_, "recovery_pnt");
  }
  void Task::publishStartPoint()
  {
    RCLCPP_INFO(this->get_logger(), "Publishing start point %f, %f", p_start_lat_, p_start_lon_);
    publishGlobalWP(p_start_lat_, p_start_lon_, "start_pnt");
  }

  void Task::publishFinishPoint()
  {
    RCLCPP_INFO(this->get_logger(), "Publishing finish point");
    publishGlobalWP(p_finish_lat_, p_finish_lon_, "start_pnt");
  }

  void Task::publishGlobalWP(double lat, double lon, std::string type)
  {
    if (activated_)
    {
      geographic_msgs::msg::GeoPoseStamped wp = task_lib::getGlobalWPMsg(lat, lon);
      global_wp_pub_->publish(wp);
      RCLCPP_DEBUG(this->get_logger(), "Global WP: lat=%f, lon=%f", wp.pose.position.latitude, wp.pose.position.longitude);
      publishGlobalWPInfo(p_start_lat_, p_start_lon_, type);
    }
  }

  void Task::publishLocalWP(double x, double y)
  {
    if (activated_)
    {
      if (x != 0 && y != 0)
      {
        geometry_msgs::msg::PoseStamped wp = task_lib::getLocalWPMsg(x, y);
        local_wp_pub_->publish(wp);
        RCLCPP_DEBUG(this->get_logger(), "Local WP: x=%f, y=%f", wp.pose.position.x, wp.pose.position.y);
        wp_cnt_++;
        publishDynamicWPInfo(x, y, stacked_detections_);
      }
      else{
        RCLCPP_WARN(this->get_logger(), "Waypoint Empty - not publishing"); 
      }
    }
  }

  void Task::publishDynamicWPInfo(double x, double y, const yolov8_msgs::msg::DetectionArray& detections)
  {
    comp_tasks_interfaces::msg::WpInfo wp_info;

    auto header = std_msgs::msg::Header();
    header.stamp = this->get_clock()->now();  // Set the timestamp
    header.frame_id = "map";  // Set the frame_id
    wp_info.header = header;

    geometry_msgs::msg::PoseStamped wp = task_lib::getLocalWPMsg(x, y);
    wp_info.wp = wp.pose.position;
    wp_info.current_pose_local = current_local_pose_.pose;
    wp_info.current_pose_global = current_global_pose_;
    wp_info.detection_stack = detections;

    if (in_guided_)
    {
      wp_info.mavros_mode = "guided";
    }
    else if (in_manual_)
    {
      wp_info.mavros_mode = "manual";
    }
    else if (in_hold_)
    {
      wp_info.mavros_mode = "hold";
    }
    else{
      wp_info.mavros_mode = "unknown";
    }
    wp_info.task_node = this->get_name();
    wp_info.node_state = node_state_;

    wp_info_pub_->publish(wp_info);   

  }

  void Task::publishGlobalWPInfo(double lat, double lon, std::string wp_type)
  {
    comp_tasks_interfaces::msg::GlobalWpInfo wp_info;

    auto header = std_msgs::msg::Header();
    header.stamp = this->get_clock()->now();  // Set the timestamp
    header.frame_id = "map";  // Set the frame_id
    wp_info.header = header;
    wp_info.global_wp_type = wp_type;

    geographic_msgs::msg::GeoPoseStamped wp = task_lib::getGlobalWPMsg(lat, lon);
    wp_info.global_wp = wp.pose;
    wp_info.current_pose_local = current_local_pose_.pose;
    wp_info.current_pose_global = current_global_pose_;

    if (in_guided_)
    {
      wp_info.mavros_mode = "guided";
    }
    else if (in_manual_)
    {
      wp_info.mavros_mode = "manual";
    }
    else if (in_hold_)
    {
      wp_info.mavros_mode = "hold";
    }
    else{
      wp_info.mavros_mode = "unknown";
    }
    wp_info.task_node = this->get_name();
    wp_info.node_state = node_state_;

    global_wp_info_pub_->publish(wp_info);   

  }

  void Task::publishWpGroupInfo(std::vector<geometry_msgs::msg::Point> wps,const yolov8_msgs::msg::DetectionArray& detections, std::string group_name)
  {
    RCLCPP_INFO(this->get_logger(),"Publishing WP Group Info");

    std::vector<comp_tasks_interfaces::msg::NamedLocalWp> named_wps;
    
    for (size_t i = 0; i < wps.size(); i++)
    {
      comp_tasks_interfaces::msg::NamedLocalWp wp;
      wp.wp = wps[i];
      wp.wp_name = std::to_string(i);
      named_wps.push_back(wp);
    }

    comp_tasks_interfaces::msg::WpGroupInfo wp_group_info;

    auto header = std_msgs::msg::Header();
    header.stamp = this->get_clock()->now();  // Set the timestamp
    header.frame_id = "map";  // Set the frame_id
    wp_group_info.header = header;

    wp_group_info.wps = named_wps;
    wp_group_info.group_name = group_name;

    wp_group_info.current_pose_local = current_local_pose_.pose;
    wp_group_info.current_pose_global = current_global_pose_;
    wp_group_info.detection_stack = detections;

    if (in_guided_)
    {
      wp_group_info.mavros_mode = "guided";
    }
    else if (in_manual_)
    {
      wp_group_info.mavros_mode = "manual";
    }
    else if (in_hold_)
    {
      wp_group_info.mavros_mode = "hold";
    }
    else{
      wp_group_info.mavros_mode = "unknown";
    }
    wp_group_info.task_node = this->get_name();
    wp_group_info.node_state = node_state_;

    wp_group_info_pub_->publish(wp_group_info);  

  }

  void Task::executeRecoveryBehaviour()
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
    else 
    {
      RCLCPP_WARN(this->get_logger(), "Invalid Recovery Behavior: %s", p_recovery_behaviour_.c_str());
    }
    return;
  }

  void Task::setTimerDuration(double duration, std::string timer_name)
  {
    timer_expired_ = false;
    timer_name_ = timer_name;

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double, std::milli>(duration * 1000));
    timer_ = this->create_wall_timer(
        ms, std::bind(&Task::onTimerExpired, this));
    RCLCPP_DEBUG(this->get_logger(), "Timer set to %f ms", duration); 

    remaining_time_ = static_cast<int>(duration); // Store remaining time as integer seconds
    // // Publish initial countdown value
     auto msg = comp_tasks_interfaces::msg::LabelInt();
    msg.value = remaining_time_;
    msg.label = timer_name_;
    timer_cntdwn_pub_->publish(msg);

    // Countdown timer that updates every second
    countdown_timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      [this]() {
          if (remaining_time_ > 0) {
              remaining_time_--;

              auto msg = comp_tasks_interfaces::msg::LabelInt();
              msg.value = remaining_time_;
              msg.label = timer_name_;
              timer_cntdwn_pub_->publish(msg);

              if (remaining_time_ == 0) {
                  countdown_timer_->cancel(); // Stop publishing when countdown reaches zero
              }
          }
      });

  }
  
  void Task::onTimerExpired()
  {
      RCLCPP_DEBUG(this->get_logger(), "Times up"); 
      timer_expired_ = true;
  }

  void Task::signalTaskFinish()
  {
    std_msgs::msg::Bool task_complete;
    task_complete.data = true;
    task_complete_pub_->publish(task_complete);
  }

}

