#include "comp_tasks/mavros_repub_component.hpp"

#include <std_msgs/msg/bool.hpp>

namespace comp_tasks
{
  MavROSRepublisher::MavROSRepublisher(const rclcpp::NodeOptions & options) : Node("mavros_republisher", options)
  {
    mavros_state_subscriber = create_subscription<mavros_msgs::msg::State>(
      "/mavros/state", 10, std::bind(&MavROSRepublisher::republishMAVROSStatus, this, std::placeholders::_1));
      
    mavros_state_publisher = create_publisher<std_msgs::msg::Bool>("/mavros/state_repub", 10);
  }

  void MavROSRepublisher::republishMAVROSStatus(const mavros_msgs::msg::State::SharedPtr msg) {
    auto bool_msg = std_msgs::msg::Bool();
        
    //Check flight mode (adjust "GUIDED" for your autopilot)
    bool_msg.data = (msg->mode == "GUIDED");
        
    mavros_state_publisher->publish(bool_msg);
    RCLCPP_DEBUG(this->get_logger(), "Guided Status: %s", bool_msg.data ? "true" : "false");
}
  
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::MavROSRepublisher)
