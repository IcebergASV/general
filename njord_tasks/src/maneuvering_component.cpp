#include "njord_tasks/maneuvering_component.hpp"

namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&Maneuvering::taskToExecuteCallback, this, _1));
    task_completion_status_pub_ = this->create_publisher<std_msgs::msg::Int32>("njord_tasks/task_completion_status", 10);

    Maneuvering::getParam<double>("distance_to_move", p_distance_to_move_, 0, "Multiplies number by this integer");
    Maneuvering::getParam<double>("angle_from_buoys", p_angle_from_buoys_, 0, "Adds this double to a number");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "distance_to_move") { p_distance_to_move_ = params[0].as_int(); }
    else if (params[0].get_name() == "angle_from_buoys") { p_angle_from_buoys_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Maneuvering::taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {

    //task_completion_status_pub_->publish(new_value);
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
