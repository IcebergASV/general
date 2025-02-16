#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <comp_tasks/task_component.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"

#include "mavros_msgs/msg/state.hpp"
#include "example_interfaces/msg/bool.hpp"

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
    void republishMAVROSStatus(const mavros_msgs::msg::State::SharedPtr msg);
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    //For subscribing and republishing as std msg
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr mavros_state_subscriber;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr mavros_state_publisher;

    double p_gate_lat_;
    double p_gate_lon_;

    std::vector<std::reference_wrapper<std::string>> p_left_gate_names_;
    std::vector<std::reference_wrapper<std::string>> p_right_gate_names_;
    
    int p_max_consec_recoveries_;

    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States status_;
};

} // namespace comp_tasks

#endif // maneuvering_HPP
