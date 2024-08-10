#include "njord_tasks/navigation_component.hpp"

namespace njord_tasks
{
  navigation::navigation(const rclcpp::NodeOptions & options)
  : Node("navigation", options)
  {
    example_sub_ = this->create_subscription<std_msgs::msg::Int32>("/njord_tasks/subscribing_topic", 10, std::bind(&navigation::callback, this, _1));
    example_pub_ = this->create_publisher<std_msgs::msg::Float64>("njord_tasks/publishing_topic", 10);

   
  }

  void navigation::callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
      // TODO: Change this to start task from task_manager 
       if (msg->data == 1) {


        RCLCPP_INFO(this->get_logger(), "Hello world");
      }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::navigation)
