#ifndef task_HPP
#define task_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "mavros_msgs/msg/state.hpp"

using std::placeholders::_1;

namespace njord_tasks
{

class Task : public rclcpp::Node
{
public:
    explicit Task(const rclcpp::NodeOptions & options);

private:
    void callback(const std_msgs::msg::Int32::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void state_callback(const mavros_msgs::msg::State::SharedPtr msg);

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr example_sub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr example_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    int p_multiplier_;
    double p_adder_;
    bool in_guided_;

    template <typename T>
    void getParam(std::string param_name, T& param, T default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<T>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + std::to_string(param);
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

      return;
    }
};

} // namespace njord_tasks

#endif // task_HPP
