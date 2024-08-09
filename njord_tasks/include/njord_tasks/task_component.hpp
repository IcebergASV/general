#ifndef task_HPP
#define task_HPP

#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include "mavros_msgs/msg/state.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "njord_tasks_interfaces/action/task_signal.hpp"
#include "njord_tasks_interfaces/msg/start_task.hpp"
#include "njord_tasks_interfaces/msg/task.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace njord_tasks
{

class Task : public rclcpp::Node
{
public:
    explicit Task(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);
    void poseCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg);
    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg);
    void wait();
    void timerCallback();
    void publishGlobalWP(double lat, double lon);
    void publishStartTaskSignal();
    void taskStatusCallback(const std_msgs::msg::Int32::SharedPtr msg);
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Subscription<geographic_msgs::msg::GeoPoseStamped>::SharedPtr pose_sub_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_sub_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr task_complete_sub_;

    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr wp_pub_;
    rclcpp::Publisher<njord_tasks_interfaces::msg::StartTask>::SharedPtr start_task_pub_;

    int    p_wait_time_;
    double p_global_wp_reached_rad_;
    double p_start_lat_;
    double p_start_lon_;
    double p_finish_lat_;
    double p_finish_lon_;

    bool in_guided_;
    bool wp_reached_;
    bool task_complete_;

    geographic_msgs::msg::GeoPoseStamped current_global_pose_;

    enum States {WAIT_FOR_GUIDED, WAIT_TO_REACH_START, TASK, WAIT_TO_REACH_FINISH, COMPLETE}; 
    States status_;

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
