#include "njord_tasks/navigation_component.hpp"

namespace njord_tasks
{
  navigation::navigation(const rclcpp::NodeOptions & options)
  : Node("navigation", options)
  {
    example_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&navigation::callback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&navigation::timerCallback, this));
  }

  void navigation::callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
       if(msg->task.current_task == njord_tasks_interfaces::msg::Task::NAVIGATION){
        status_ = States::START_TASK;
       }
  }

  

  void navigation::timerCallback(){
    switch (status_){
      case States::WAIT_FOR_START:
      {
        RCLCPP_INFO(this->get_logger(), "Waiting for task to start");
        break;

      }
      case States::START_TASK:
      {
        RCLCPP_INFO(this->get_logger(), "Starting task");

        break;
      }






    }



  }
  
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::navigation)
