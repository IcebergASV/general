#ifndef MAVROS_REPUB_HPP
#define MAVROS_REPUB_HPP

#include <rclcpp/rclcpp.hpp>
#include <comp_tasks/task_component.hpp>

using std::placeholders::_1;

namespace comp_tasks
{

class MavROSRepublisher : public comp_tasks::Task
{
public:
    explicit MavROSRepublisher(const rclcpp::NodeOptions & options);

private:
    void republishMAVROSStatus(const mavros_msgs::msg::State::SharedPtr msg);
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections);

    //For subscribing and republishing as std msg
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr mavros_state_subscriber;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr mavros_state_publisher;
};

} // namespace comp_tasks

#endif // maneuvering_HPP
