#ifndef navigation_HPP
#define navigation_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <chrono>
#include "njord_tasks_interfaces/action/task_signal.hpp"
#include "njord_tasks_interfaces/msg/start_task.hpp"
#include "njord_tasks_interfaces/msg/task.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace njord_tasks
{

class navigation : public rclcpp::Node
{
public:
    explicit navigation(const rclcpp::NodeOptions & options);

private:
    void callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg);
    void timerCallback();

    rclcpp::TimerBase::SharedPtr timer_;
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    rclcpp::Subscription<njord_tasks_interfaces::msg::StartTask>::SharedPtr example_sub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr example_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    enum States {WAIT_FOR_START, START_TASK, GOING_TO_WAYPOINT, REACHED_WAYPOINT, GOING_TO_FINISH, COMPLETE}; 
    States status_ = States::WAIT_FOR_START;

    geographic_msgs::msg::GeoPoseStamped next_point;
    std::vector<std::pair<double, double>> test;

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

#endif // navigation_HPP
