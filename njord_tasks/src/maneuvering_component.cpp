#include "njord_tasks/maneuvering_component.hpp"
#include "njord_tasks/lib/bbox_calculations.hpp"
#include "njord_tasks/lib/task_lib.hpp"

namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&Maneuvering::taskToExecuteCallback, this, _1));
    bbox_sub_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>("/yolo/detections", 10, std::bind(&Maneuvering::bboxCallback, this, _1));
    wp_reached_sub_ = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&Maneuvering::wpReachedCallback, this, _1));
    global_pose_sub_ = this->create_subscription<sensor_msgs::msg::NavSatFix>("/mavros/global_position/global", qos, std::bind(&Maneuvering::globalPoseCallback, this, _1));
    local_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&Maneuvering::localPoseCallback, this, _1));

    task_completion_status_pub_ = this->create_publisher<std_msgs::msg::Int32>("njord_tasks/task_completion_status", 10);
    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);
    local_wp_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("mavros/setpoint_position/local", 10);
    local_wp_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("mavros/setpoint_position/local", 10);
    status_logger_pub_ = this->create_publisher<std_msgs::msg::String>("/njord_tasks/maneuvering/status", 10);

    //timer_ = this->create_wall_timer(50ms, std::bind(&Maneuvering::timerCallback, this));

    Maneuvering::getParam<double>("distance_to_move", p_distance_to_move_, 0.0, "Sets a wp this far away");
    Maneuvering::getParam<double>("angle_from_target", p_angle_from_target_, 0.0, "Angles the wp this far from a target buoy");
    Maneuvering::getParam<double>("wp_reached_radius", p_wp_reached_radius_, 0.0, "Within this many meters to reach point");
    Maneuvering::getParam<int>("camera_res_x", p_camera_res_x_, 0, "Resolution width of camera");
    Maneuvering::getParam<int>("camera_fov", p_camera_fov_, 0, "Camera field of view");
    Maneuvering::getParam<int>("testing_angles", p_testing_angles_, 0, "");
    Maneuvering::getParam<double>("test_angle", p_test_angle_, 0.0, "");
    Maneuvering::getParam<double>("finish_lat", p_finish_lat_, 0.0, "Finish latitude");
    Maneuvering::getParam<double>("finish_lon", p_finish_lon_, 0.0, "Finish longitude");
    Maneuvering::getParam<double>("ms_to_pause_search", p_time_to_pause_search_, 0.0, "Miliseconds to wait after finding a target before starting to search for new ones");
    Maneuvering::getParam<double>("ms_between_recovery_actions", p_time_between_recovery_actions_, 0.0, "Miliseconds between executing a recovery action (like sending a waypoint)");
    Maneuvering::getParam<double>("ms_to_stop_before_recovery", p_time_to_stop_before_recovery_, 0.0, "Miliseconds to stop robot before switching to recovery state if no targets found");
    Maneuvering::getStringParam("red_buoy_label", p_red_buoy_str_, "red_buoy", "Red buoy label");
    Maneuvering::getStringParam("green_buoy_label", p_green_buoy_str_, "green_buoy", "Green buoy label");
    Maneuvering::getStringParam("second_red_buoy_label", p_second_red_buoy_str_, "red_buoy", "Additional red buoy label");
    Maneuvering::getStringParam("second_green_buoy_label", p_second_green_buoy_str_, "green_buoy", "Additional green buoy label");

    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    global_pose_updated_ = false;
    local_pose_updated_ = false;
    bboxes_updated_ = false;
    start_task_ = true;
    wp_reached_ = false;
    wp_cnt_ = 0;

    status_ = States::STOPPED;

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

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_double(); }
    else if (params[0].get_name() == "angle_from_buoys") { p_angle_from_target_ = params[0].as_double(); }
    else if (params[0].get_name() == "wp_reached_radius") { p_wp_reached_radius_ = params[0].as_double(); }
    else if (params[0].get_name() == "camera_res_x") { p_camera_res_x_ = params[0].as_int(); }
    else if (params[0].get_name() == "camera_fov") { p_camera_fov_ = params[0].as_int(); }
    else if (params[0].get_name() == "testing_angles") { p_testing_angles_ = params[0].as_int(); }
    else if (params[0].get_name() == "test_angle") { p_test_angle_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "red_buoy_label") { p_red_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "ms_to_pause_search") { p_time_to_pause_search_ = params[0].as_double(); }
    else if (params[0].get_name() == "ms_between_recovery_actions") { p_time_between_recovery_actions_ = params[0].as_double(); }
    else if (params[0].get_name() == "ms_to_stop_before_recovery") { p_time_to_stop_before_recovery_ = params[0].as_double(); }
    else if (params[0].get_name() == "green_buoy_label") { p_green_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "second_red_buoy_label") { p_second_red_buoy_str_ = params[0].as_string(); }
    else if (params[0].get_name() == "second_green_buoy_label") { p_second_green_buoy_str_ = params[0].as_string(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Maneuvering::globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
  {
    current_global_pose_ = *msg;
    global_pose_updated_ = true;
    RCLCPP_DEBUG(this->get_logger(), "Latitude: %f, Longitude: %f", current_global_pose_.latitude, current_global_pose_.longitude);
  }

  void Maneuvering::localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    current_local_pose_ = *msg;
    local_pose_updated_ = true;
    RCLCPP_DEBUG(this->get_logger(), "Local Pose: x: %f, y: %f", msg->pose.position.x, msg->pose.position.y);
  }

  void Maneuvering::publishSearchStatus(std::string str_msg)
  {
    std_msgs::msg::String msg;
    msg.data = "SEARCH STATUS: " + str_msg;
    status_logger_pub_->publish(msg);
  }
  void Maneuvering::publishBehaviourStatus(std::string str_msg)
  {
    std_msgs::msg::String msg;
    msg.data = "BEHAVIOUR STATUS: " + str_msg;
    status_logger_pub_->publish(msg);
  }

  void Maneuvering::setTimerDuration(double duration)
  {
    timer_expired_ = false;

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double, std::milli>(duration * 1000));
    timer_ = this->create_wall_timer(
        ms, std::bind(&Maneuvering::onTimerExpired, this));
    RCLCPP_DEBUG(this->get_logger(), "Timer set to %f ms", duration); 
  }
  void Maneuvering::onTimerExpired()
  {
      RCLCPP_DEBUG(this->get_logger(), "Times up"); 
      timer_expired_ = true;
  }

  void Maneuvering::executeRecoveryBehaviour()
  {
    return; // TODO
  }

  void Maneuvering::publishWPTowardsDetections()
  {
    wp_reached_ = false;
    publishSearchStatus("Found");
    double angle = bbox_calculations::getAngleBetween2DiffTargets(bboxes_,p_red_buoy_str_, p_second_red_buoy_str_,p_green_buoy_str_, p_second_green_buoy_str_, p_camera_fov_, p_camera_res_x_, p_angle_from_target_);
    geometry_msgs::msg::PoseStamped wp = task_lib::relativePolarToLocalCoords(p_distance_to_move_, angle, current_local_pose_);
    if (wp.pose.position.x != 0 && wp.pose.position.y != 0)
    {
      local_wp_pub_->publish(wp);
      wp_cnt_++;
    }
    else{
      RCLCPP_WARN(this->get_logger(), "Waypoint Empty - not publishing"); 
    }

    if (p_time_to_pause_search_ != 0.0) 
    {
      setTimerDuration(p_time_to_pause_search_);
    }
  }


  void Maneuvering::bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
  {
    bboxes_ = *msg;
    if (true) //TODO change to start task.
    {
      switch (status_)
      {
        case States::STOPPED: // parameterize - don't go to this state at all in 0 secs
        {
          publishSearchStatus("Searching");
          publishBehaviourStatus("Stopped");

          if (bbox_calculations::hasDesiredDetections(bboxes_, target_class_names_))
          {
            publishWPTowardsDetections();

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
          publishSearchStatus("Searching");
          publishBehaviourStatus("Recovering with TODO INSERT RECOVERY BEHAVIOUR");
          if (bbox_calculations::hasDesiredDetections(bboxes_, target_class_names_))
          {
            publishWPTowardsDetections();

            status_ = States::HEADING_TO_TARGET;
          }
          if(timer_expired_)
          {
            executeRecoveryBehaviour();
            setTimerDuration(p_time_between_recovery_actions_);
          }
          break;
        }

        case States::HEADING_TO_TARGET: // parameterize wait time
        {
          if (timer_expired_)
          {
            publishSearchStatus("Searching");
          }
          else
          {
            publishSearchStatus("Search Paused");
          }
          
          std::string str_cnt = std::to_string(wp_cnt_);
          publishBehaviourStatus("Heading to WP " + str_cnt);

          if (bbox_calculations::hasDesiredDetections(bboxes_, target_class_names_) && timer_expired_)
          {

            publishWPTowardsDetections();
          }
          else if (wp_reached_)
          {
            std::string str_cnt = std::to_string(wp_cnt_);
            publishBehaviourStatus("WP " + str_cnt + " Reached");

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
          break;
        }
      }
    }
  }

  void Maneuvering::sendFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(p_finish_lat_, p_finish_lon_);
    global_wp_pub_->publish(finish_wp);
    RCLCPP_DEBUG(this->get_logger(), "Finish WP: lat=%f, lon=%f", finish_wp.pose.position.latitude, finish_wp.pose.position.longitude);
  }

  void Maneuvering::wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
    mavros_msgs::msg::WaypointReached wpr = msg;
    wp_reached_ = true;
  }

  void Maneuvering::taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
    finish_pnt_ = msg->finish_pnt;
    start_task_ = true;
    RCLCPP_INFO(this->get_logger(), "Starting maneuvering task");
 
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
