#include "njord_tasks/navigation_component.hpp"

namespace njord_tasks
{
  navigation::navigation(const rclcpp::NodeOptions & options)
  : Node("navigation", options)
  {
    example_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&navigation::callback, this, _1));
    example_pub_ = this->create_publisher<std_msgs::msg::Float64>("njord_tasks/publishing_topic", 10);
  }

  void navigation::callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
      RCLCPP_INFO(this->get_logger(), "Hello World")
     
      if(msg->task.current_task == NAVIGATION){





      }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::navigation)
