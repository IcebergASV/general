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
    void executeRecoveryBehaviour() override;
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    void checkIfFinished();
    void handleDetections(const yolov8_msgs::msg::DetectionArray& detections);
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    void setState(std::string str_state);
    
    int p_max_consec_recoveries_;
    double p_time_to_stop_before_recovery_;
    double p_time_to_pause_search_;
    double p_time_between_recovery_actions_;
    std::string p_state_;
    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States state_;
    double gate_x_;
    double gate_y_;
};

} // namespace comp_tasks

#endif // maneuvering_HPP
