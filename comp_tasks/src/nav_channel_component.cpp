#include "comp_tasks/nav_channel_component.hpp"

namespace comp_tasks
{
  NavChannel::NavChannel(const rclcpp::NodeOptions & options)
  : Task(options, "nav_channel")
  {
    example_pub_ = this->create_publisher<std_msgs::msg::Float64>("comp_tasks/publishing_topic", 10);

    NavChannel::getParam<int>("multiplier", p_multiplier_, 0, "Multiplies number by this integer");
    NavChannel::getParam<double>("adder", p_adder_, 0, "Adds this double to a number");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&NavChannel::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult NavChannel::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "multiplier") { p_multiplier_ = params[0].as_int(); }
    else if (params[0].get_name() == "adder") { p_adder_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void NavChannel::taskLogic(const yolov8_msgs::msg::DetectionArray& detections)
  {
    if (in_guided_)
    {
      // TODO
    }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::NavChannel)
