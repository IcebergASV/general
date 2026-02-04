#ifndef task_controller_HPP
#define task_controller_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "lifecycle_msgs/msg/state.hpp"
#include "lifecycle_msgs/msg/transition.hpp"
#include "lifecycle_msgs/srv/change_state.hpp"
#include "lifecycle_msgs/srv/get_state.hpp"
#include <std_msgs/msg/bool.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace comp_tasks
{
  template<typename FutureT, typename WaitTimeT>
  std::future_status
  wait_for_result(
    FutureT & future,
    WaitTimeT time_to_wait)
  {
    auto end = std::chrono::steady_clock::now() + time_to_wait;
    std::chrono::milliseconds wait_period(100);
    std::future_status status = std::future_status::timeout;
    do {
      auto now = std::chrono::steady_clock::now();
      auto time_left = end - now;
      if (time_left <= std::chrono::seconds(0)) {break;}
      status = future.wait_for((time_left < wait_period) ? time_left : wait_period);
    } while (rclcpp::ok() && status != std::future_status::ready);
    return status;
  }

class TaskController : public rclcpp::Node
{
public:
    explicit TaskController(const rclcpp::NodeOptions & options);
    void configureNextTask();
    void runTask();
private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void init(std::string node_name);
    void taskCompleteCallback(const std_msgs::msg::Bool::SharedPtr msg);
    unsigned int get_state(std::chrono::seconds time_out = 3s);
    bool change_state(std::uint8_t transition, std::chrono::seconds time_out = 3s);
    bool setNextNodeName();

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr task_complete_sub_;

    std::string p_tasks_;
    std::string node_name_;
    std::string node_get_state_topic;
    std::string node_change_state_topic;
    std::shared_ptr<rclcpp::Client<lifecycle_msgs::srv::GetState>> client_get_state_;
    std::shared_ptr<rclcpp::Client<lifecycle_msgs::srv::ChangeState>> client_change_state_;
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
    void getStringParam(std::string param_name, std::string& param, std::string default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<std::string>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + param;
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 
      return;
    }
};

} // namespace comp_tasks

#endif // task_controller_HPP
