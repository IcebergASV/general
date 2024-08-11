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
    timer_ = this->create_wall_timer(10000ms, std::bind(&Maneuvering::timerCallback, this));

    Maneuvering::getParam<double>("distance_to_move", p_distance_to_move_, 0.0, "Sets a wp this far away");
    Maneuvering::getParam<double>("angle_from_buoys", p_angle_from_buoys_, 0.0, "Angles the wp this far from a single buoy");
    Maneuvering::getParam<double>("wp_reached_radius", p_wp_reached_radius_, 0.0, "Within this many meters to reach point");
    Maneuvering::getParam<int>("camera_res_x", p_camera_res_x_, 0, "Resolution width of camera");
    Maneuvering::getParam<int>("camera_fov", p_camera_fov_, 0, "Camera field of view");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    global_pose_updated_ = false;
    local_pose_updated_ = false;
    bboxes_updated_ = false;
    start_task_ = false;
    wp_reached_ = false;
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_double(); }
    else if (params[0].get_name() == "angle_from_buoys") { p_angle_from_buoys_ = params[0].as_double(); }
    else if (params[0].get_name() == "wp_reached_radius") { p_wp_reached_radius_ = params[0].as_double(); }
    else if (params[0].get_name() == "camera_res_x") { p_camera_res_x_ = params[0].as_int(); }
    else if (params[0].get_name() == "camera_fov") { p_camera_fov_ = params[0].as_int(); }
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

  void Maneuvering::bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
  {
    bboxes_ = *msg;
    if (hasDesiredDetections(bboxes_)) //TODO
    {
      bboxes_updated_ = true;
    }
  }

  void Maneuvering::sendFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(finish_pnt_.latitude, finish_pnt_.longitude);
    global_wp_pub_->publish(finish_wp);
  }

  void Maneuvering::wait()
  {
    rclcpp::Rate rate(1);
    rate.sleep();
  }

  void Maneuvering::wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
    mavros_msgs::msg::WaypointReached wpr = msg;
    wp_reached_ = true;
  }

  std::vector<yolov8_msgs::msg::Detection> Maneuvering::filterAndSortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array, const std::string& class_name)
  {
    std::vector<yolov8_msgs::msg::Detection> filtered_detections;

    for (const auto& detection : detection_array.detections) {
        if (detection.class_name == class_name) {
            filtered_detections.push_back(detection);
        }
    }

    std::sort(filtered_detections.begin(), filtered_detections.end(),
        [](const yolov8_msgs::msg::Detection& a, const yolov8_msgs::msg::Detection& b) {
            double center_a_x = a.bbox.center.position.x;
            double center_b_x = b.bbox.center.position.x;
            return center_a_x < center_b_x;
        });

    return filtered_detections;
  }

  bool Maneuvering::hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array) {
      // Iterate through the detections
      for (const auto& detection : detection_array.detections) {
          // Check if the class name is either "red_buoy" or "green_buoy"
          if (detection.class_name == red_buoy_str_ || detection.class_name == green_buoy_str_) {
              return true; // Return true if a match is found
          }
      }
      return false; // Return false if no matches are found
  }

  void Maneuvering::getWPFromBuoys(geometry_msgs::msg::PoseStamped& wp)
  {

    std::vector<yolov8_msgs::msg::Detection> red_buoys = filterAndSortLeftToRight(bboxes_, red_buoy_str_);
    std::vector<yolov8_msgs::msg::Detection> green_buoys = filterAndSortLeftToRight(bboxes_, green_buoy_str_);

    if (red_buoys.size() == 0 && green_buoys.size() == 0)
    {
      RCLCPP_WARN(this->get_logger(), "No red or green buoys detected"); //TODO HANDLE
      return;
    }

    double angle;
    if ((red_buoys.size() == 0) & (green_buoys.size() > 0)) // move to left of left most green
    {
      RCLCPP_INFO(this->get_logger(), "Detected only green buoys");
      angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, green_buoys[0].bbox.center.position.x);
      RCLCPP_INFO(this->get_logger(), "Left most green buoy detected at %f degrees", angle*180/M_PI);
      angle = angle + p_angle_from_buoys_*M_PI/180;
      RCLCPP_INFO(this->get_logger(), "Heading towards %f degrees", angle*180/M_PI);
    }
    else if ((green_buoys.size() == 0) && (red_buoys.size() > 0)) // move to the right of rightmost red
    {
      RCLCPP_INFO(this->get_logger(), "Detected only red buoys");
      angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, red_buoys[red_buoys.size()-1].bbox.center.position.x);
      RCLCPP_INFO(this->get_logger(), "Right most red buoy detected at %f degrees", angle*180/M_PI);
      angle = angle - p_angle_from_buoys_*M_PI/180;
      RCLCPP_INFO(this->get_logger(), "Heading towards %f degrees", angle*180/M_PI);
    }
    else if ((green_buoys.size() > 0) && (red_buoys.size() > 0))// move in between innermost red and green
    {
      
      double red_angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, red_buoys[red_buoys.size()-1].bbox.center.position.x);
      double green_angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, green_buoys[0].bbox.center.position.x);
      angle = (red_angle + green_angle)/2;
      RCLCPP_INFO(this->get_logger(), "Detected red buoy at %f degrees and green buoy at %f degrees, heading towards %f degrees", red_angle*180/M_PI, green_angle*180/M_PI, angle*180/M_PI);
    }
    else 
    {
      RCLCPP_WARN(this->get_logger(), "ERROR COUNTING BUOYS");
    }
    angle = angle - M_PI/2;
    wp = task_lib::relativePolarToLocalCoords(p_distance_to_move_, angle, current_local_pose_);
    return;
  }

  void Maneuvering::timerCallback()
  {
    if (start_task_)
    {
      switch (status_)
      {
        case States::CHECK_FOR_BUOYS:
        {
          wait();
          RCLCPP_INFO(this->get_logger(), "Checking for buoys");
          if (bboxes_updated_ && local_pose_updated_) 
          {
            status_ = States::MANEUVER;
            bboxes_updated_ = false;
            local_pose_updated_ = false;
          }
          else{
            status_ = States::HEAD_TO_FINISH;
          }
          break;
        }

        case States::HEAD_TO_FINISH:
        {
          wp_reached_ = false;
          RCLCPP_INFO(this->get_logger(), "No buoys detected, Heading towards finish point");

          sendFinishPnt();
          status_ = States::CHECK_FOR_BUOYS;
          break;
        }

        case States::MANEUVER:
        {
          RCLCPP_INFO(this->get_logger(), "Maneuvering through buoys");
          geometry_msgs::msg::PoseStamped wp;
          getWPFromBuoys(wp);
          local_wp_pub_->publish(wp);
          status_ = States::CHECK_FOR_BUOYS;
          break;
        }

        // case States::TASK_COMPLETE:
        // {
        //   RCLCPP_INFO_ONCE(this->get_logger(), "Maneuvering Complete!");

        // }
      }
    }
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
