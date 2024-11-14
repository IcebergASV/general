#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <comp_tasks/task_component.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"

using std::placeholders::_1;

namespace comp_tasks
{

class Maneuvering : public comp_tasks::Task
{
public:
    explicit Maneuvering(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr example_sub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr example_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    int p_multiplier_;
    double p_adder_;

    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States status_;
};

} // namespace comp_tasks

#endif // maneuvering_HPP
