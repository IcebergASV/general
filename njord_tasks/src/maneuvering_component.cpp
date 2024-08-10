#include "njord_tasks/maneuvering_component.hpp"
#include "njord_tasks/lib/bbox_calculations.hpp"
#include "njord_tasks/lib/task_lib.hpp"
namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&Maneuvering::taskToExecuteCallback, this, _1));
    bbox_sub_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>("/yolo/detections", 10, std::bind(&Maneuvering::bboxCallback, this, _1));

    task_completion_status_pub_ = this->create_publisher<std_msgs::msg::Int32>("njord_tasks/task_completion_status", 10);
    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);
    local_wp_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("mavros/setpoint_position/local", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&Maneuvering::timerCallback, this));

    Maneuvering::getParam<double>("distance_to_move", p_distance_to_move_, 0.0, "Sets a wp this far away");
    Maneuvering::getParam<double>("angle_from_buoys", p_angle_from_buoys_, 0.0, "Angles the wp this far from a single buoy");
    Maneuvering::getParam<double>("wp_reached_radius", p_wp_reached_radius_, 0.0, "Within this many meters to reach point");
    Maneuvering::getParam<int>("camera_res_x", p_camera_res_x_, 0, "Resolution width of camera");
    Maneuvering::getParam<int>("camera_fov", p_camera_fov_, 0, "Camera field of view");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    global_pose_updated_ = false;
    bboxes_updated_ = false;
    start_task_ = false;
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

  void Maneuvering::poseCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg)
  {
    current_global_pose_ = *msg;
    global_pose_updated_ = true;
    // Extract latitude and longitude from the message
    double latitude = msg->pose.position.latitude;
    double longitude = msg->pose.position.longitude;

    // Log the values
    RCLCPP_INFO(this->get_logger(), "Latitude: %f, Longitude: %f", latitude, longitude);
  }

  void Maneuvering::bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
  {
    bboxes_ = *msg;
    bboxes_updated_ = true;

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

  // Function to get and sort detections based on class name
  std::vector<yolov8_msgs::msg::Detection> Maneuvering::filterAndSortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array, const std::string& class_name)
  {
    // Vector to store filtered detections
    std::vector<yolov8_msgs::msg::Detection> filtered_detections;

    // Iterate over all detections
    for (const auto& detection : detection_array.detections) {
        if (detection.class_name == class_name) {
            filtered_detections.push_back(detection);
        }
    }

    // Sort detections by the x value of the center of the bounding box
    std::sort(filtered_detections.begin(), filtered_detections.end(),
        [](const yolov8_msgs::msg::Detection& a, const yolov8_msgs::msg::Detection& b) {
            double center_a_x = a.bbox.center.position.x;
            double center_b_x = b.bbox.center.position.x;
            return center_a_x < center_b_x;
        });

    return filtered_detections;
  }

  geometry_msgs::msg::PoseStamped Maneuvering::getWPFromBuoys()
  {

    std::vector<yolov8_msgs::msg::Detection> red_buoys = filterAndSortLeftToRight(bboxes_, red_buoy_str);
    std::vector<yolov8_msgs::msg::Detection> green_buoys = filterAndSortLeftToRight(bboxes_, green_buoy_str);

    // red - green
    // right most red , left most green

    if (red_buoys.size() == 0 && green_buoys.size() == 0)
    {
      RCLCPP_INFO(this->get_logger(), "No buoys detected"); //TODO HANDLE
    }

    double angle;
    if (red_buoys.size() == 0) // move to left of left most green [0]
    {
      angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, green_buoys[0].bbox.center.position.x);
      angle = angle + p_angle_from_buoys_;
    }
    else if (green_buoys.size() == 0) // move to the right of rightmost red [last]
    {
      angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, red_buoys[red_buoys.size()-1].bbox.center.position.x);
      angle = angle - p_angle_from_buoys_;
    }
    else // move inbetween red [last] and green [0]
    {
      double red_angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, red_buoys[red_buoys.size()-1].bbox.center.position.x);
      double green_angle = bbox_calculations::pixelToAngle(p_camera_fov_, p_camera_res_x_, green_buoys[0].bbox.center.position.x);

      angle = (red_angle + green_angle)/2;
    }

    // relative to local
    geometry_msgs::msg::Point relative_coords = task_lib::polarToCartesian(p_distance_to_move_, angle);

    geometry_msgs::msg::PoseStamped wp = task_lib::getRelativeWPMsg(relative_coords.x, relative_coords.y);

    return wp; 
  }

  bool Maneuvering::atFinish()
  {
    if (task_lib::isReached(finish_pnt_.latitude, finish_pnt_.longitude, current_global_pose_, p_wp_reached_radius_))
    {
      return true;
    }
    return false;

  }
  void Maneuvering::timerCallback()
  {
   switch (status_)
    {
    case States::CHECK_IF_AT_FINISH:
    {
      wait();
      if (global_pose_updated_ && atFinish())
      {
        global_pose_updated_ = false;
        status_ = States::TASK_COMPLETE;
      }
      else if (bboxes_updated_) 
      {
        status_ = States::MANEUVER;
        bboxes_updated_ = false;
      }
      else{
        status_ = States::HEAD_TO_FINISH;
      }
      break;
    }

    case States::HEAD_TO_FINISH:
    {
      sendFinishPnt();
      status_ = States::CHECK_IF_AT_FINISH;
      break;
    }

    case States::MANEUVER:
    {
      geometry_msgs::msg::PoseStamped wp = getWPFromBuoys();
      local_wp_pub_->publish(wp);
      status_ = States::CHECK_IF_AT_FINISH;
      break;
    }

    case States::TASK_COMPLETE:
    {
      RCLCPP_INFO_ONCE(this->get_logger(), "Maneuvering Complete!");

    }
  }
  }
  void Maneuvering::taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
    finish_pnt_ = msg->finish_pnt;
    start_task_ = true;
    RCLCPP_DEBUG(this->get_logger(), "taskToExecuteCallback");
 
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
