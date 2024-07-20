#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>

#include <mavros_msgs/msg/state.hpp>

using std::placeholders::_1;

namespace njord_tasks
{

class Maneuvering : public rclcpp::Node
{
public:
    explicit Maneuvering(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    bool in_guided_;
    int p_wait_time_;
    double p_speed_factor_;

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

#endif // maneuvering_HPP
