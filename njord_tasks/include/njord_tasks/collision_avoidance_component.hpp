#ifndef collision_avoidance_HPP
#define collision_avoidance_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "mavros_msgs/srv/set_mode.hpp"
#include <mavros_msgs/msg/state.hpp>
#include <chrono>

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace njord_tasks
{

class CollisionAvoidance : public rclcpp::Node
{
public:
    explicit CollisionAvoidance(const rclcpp::NodeOptions & options);

private:
    // void callback(const std_msgs::msg::Int32::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Client<mavros_msgs::srv::SetMode>::SharedPtr set_mode_client_;
    rclcpp::TimerBase::SharedPtr timer_;

    int p_multiplier_;
    double p_adder_;

    bool in_guided_;

    enum States {WAIT_FOR_GUIDED, HOLD}; 
    States status_;

    void change_mode(const std::string &mode);
    void timerCallback();

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

#endif // collision_avoidance_HPP
