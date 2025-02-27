#ifndef mavros_repub_component_HPP
#define mavros_repub_component_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <mavros_msgs/msg/state.hpp>

namespace comp_tasks
{
class MavROSRepublisher : public rclcpp::Node
{
public:
    explicit MavROSRepublisher(const rclcpp::NodeOptions & options);

private:
    void republishMAVROSStatus(const mavros_msgs::msg::State::SharedPtr msg);

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr mavros_state_subscriber;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr mavros_state_publisher;
};
} // namespace comp_tasks

#endif // mavros_repub_component_HPP
