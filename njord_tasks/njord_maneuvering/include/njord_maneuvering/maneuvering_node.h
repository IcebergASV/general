#ifndef COMPOSITION__MANEUVERING_NODE_HPP_
#define COMPOSITION__MANEUVERING_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "perception_interfaces/msg/bounding_box.hpp"
#include "perception_interfaces/msg/bounding_boxes.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>

using std::placeholders::_1;

namespace njord_maneuvering
{

class ManeuveringNode : public rclcpp::Node
{
public:
    explicit ManeuveringNode(const rclcpp::NodeOptions & options);
    
protected:
    void position_callback(const geometry_msgs::msg::PoseStamped msg);
    void state_callback(const mavros_msgs::msg::State::SharedPtr msg);
    void wp_reached_callback(const mavros_msgs::msg::WaypointReached msg);
    void bbox_callback(const perception_interfaces::msg::BoundingBoxes msg);

private:
    geometry_msgs::msg::PoseStamped local_pose_;
    perception_interfaces::msg::BoundingBoxes bbox_;

    bool in_guided_ = false;
    bool previous_guided_state_ = false;
    bool velocity_mode_ = false;
    int state_ = 0;

    double p_wp1_x_;
    double p_wp1_y_;
    double p_wp2_x_;
    double p_wp2_y_;
    double p_turn_angle_;

    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_sub_;
    rclcpp::Subscription<perception_interfaces::msg::BoundingBoxes>::SharedPtr bbox_sub_;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr waypoint_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vector_pub_;

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    void adjustVelocity();
    bool leftPropCloser();

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

} // namespace njord_maneuvering

#endif