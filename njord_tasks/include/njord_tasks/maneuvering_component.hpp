#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include "njord_tasks_interfaces/msg/start_task.hpp"

using std::placeholders::_1;

namespace njord_tasks
{

class Maneuvering : public rclcpp::Node
{
public:
    explicit Maneuvering(const rclcpp::NodeOptions & options);

private:
    void taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void poseCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg);
    rclcpp::Subscription<njord_tasks_interfaces::msg::StartTask>::SharedPtr task_to_execute_sub_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr task_completion_status_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Subscription<geographic_msgs::msg::GeoPoseStamped>::SharedPtr pose_sub_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_wp_pub_;

    double p_distance_to_move_;
    double p_angle_from_buoys_;

    enum States {WAIT_FOR_GUIDED, WAIT_TO_REACH_START, TASK, WAIT_TO_REACH_FINISH, COMPLETE}; 
    States status_;

    geographic_msgs::msg::GeoPoseStamped current_global_pose_;
    bool global_pose_updated_;
    geographic_msgs::msg::GeoPoint finish_pnt_;

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
