#ifndef home_HPP
#define home_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <comp_tasks/task_component.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"

using std::placeholders::_1;

namespace comp_tasks
{

class Home : public comp_tasks::Task
{
public:
    explicit Home(const rclcpp::NodeOptions & options);

private:
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &) override;
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    void executeRecoveryBehaviour() override;
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    void checkIfFinished();
    void handleDetections(const yolov8_msgs::msg::DetectionArray& detections);

    void setState(std::string str_state);
    
    int p_max_consec_recoveries_;
    double p_time_to_stop_before_recovery_;
    double p_time_between_recovery_actions_;
    std::string p_state_;
    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States state_;
    double gate_x_;
    double gate_y_;
};

} // namespace comp_tasks

#endif // home_HPP
