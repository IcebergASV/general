#include "comp_tasks/mavros_repub_component.hpp"


namespace comp_tasks
{

MavROSRepublisher::MavROSRepublisher(const rclcpp::NodeOptions & options) : Task(options, "mavros_republisher") {
  //Create publishers for component statuses
  mavros_state_subscriber = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&MavROSRepublisher::republishMAVROSStatus, this, std::placeholders::_1));
  mavros_state_publisher = this->create_publisher<std_msgs::msg::Bool>("/guided_status", 10);
}

void MavROSRepublisher::republishMAVROSStatus(const mavros_msgs::msg::State::SharedPtr msg) {
  auto bool_msg = std_msgs::msg::Bool();
        
  //Check flight mode (adjust "GUIDED" for your autopilot)
  bool_msg.data = (msg->mode == "GUIDED");  // ArduPilot
  //bool_msg.data = (msg->mode == "OFFBOARD");  // PX4
        
  mavros_state_publisher->publish(bool_msg);
  RCLCPP_DEBUG(this->get_logger(), "Guided Status: %s", bool_msg.data ? "true" : "false");
}

void MavROSRepublisher::taskLogic(const yolov8_msgs::msg::DetectionArray& detections) {
  //Needed because inherits from pure virtual
  return;
}

} // namespace comp_tasks

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::MavROSRepublisher);
