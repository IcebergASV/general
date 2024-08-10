#include "njord_tasks/maneuvering_component.hpp"

namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&Maneuvering::taskToExecuteCallback, this, _1));
    bbox_sub_ = this->create_subscription<yolov8_msgs_::msg::IcebergDetectionArray>("/njord_tasks/task_to_execute", 10, std::bind(&Maneuvering::taskToExecuteCallback, this, _1));

    task_completion_status_pub_ = this->create_publisher<std_msgs::msg::Int32>("njord_tasks/task_completion_status", 10);

    Maneuvering::getParam<double>("distance_to_move", p_distance_to_move_, 0, "Sets a wp this far away");
    Maneuvering::getParam<double>("angle_from_buoys", p_angle_from_buoys_, 0, "Angles the wp this far from a single buoy");
    Maneuvering::getParam<double>("wp_reached_radius", p_wp_reached_radius_, 0, "Within this many meters to reach point")
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    global_pose_updated_ = false;
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_double(); }
    else if (params[0].get_name() == "angle_from_buoys") { p_angle_from_buoys_ = params[0].as_double(); }
    else if (params[0].get_name() == "wp_reached_radius") { p_wp_reached_radius_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Task::poseCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg)
  {
    current_global_pose_ = *msg;
    global_pose_updated_ = true;
    // Extract latitude and longitude from the message
    double latitude = msg->pose.position.latitude;
    double longitude = msg->pose.position.longitude;

    // Log the values
    RCLCPP_INFO(this->get_logger(), "Latitude: %f, Longitude: %f", latitude, longitude);
  }

  void sendFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(finish_pnt.latitude, finish_pnt.longitude);
    

  }

  bool atFinish()
  {
    if (task_lib::isReached(finish_pnt.latitude, finish_pnt.longitude, current_global_pose_, wp_reached_radius_))
    {
      return true;
    }
    return false;

  }
  void Maneuvering::taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
    finish_pnt_ = msg->finish_pnt;
    start_task_ = true;
    RCLCPP_DEBUG(this->get_logger(), "taskToExecuteCallback");
    switch (status_)
    {
    case States::CHECK_IF_AT_FINISH:
    {
      if (global_pose_updated_ && atFinish())
      {
        global_pose_updated_ = false;
        status_ = States::TASK_COMPLETE;
      }
      else if (buoys_detected_) 
      {
        status_ = States::MANEUVER;
        buoys_detected_ = false;
      }
      else{
        status_ = States::HEAD_TO_FINISH
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
      wp = getWPFromBuoys();
      status_ = States::CHECK_IF_AT_FINISH;
      break;
    }

    case States::TASK_COMPLETE:
    {
      RCLCPP_INFO_ONCE(this->get_logger(), "Maneuvering Complete!");

    }
  }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
