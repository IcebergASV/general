#ifndef speed_HPP
#define speed_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <comp_tasks/task_component.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"

using std::placeholders::_1;

namespace comp_tasks
{

class Speed : public comp_tasks::Task
{
public:
    explicit Speed(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    void checkIfFinished();
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    
    int p_max_consec_recoveries_;

    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States status_;
};

} // namespace comp_tasks

#endif // speed_HPP
