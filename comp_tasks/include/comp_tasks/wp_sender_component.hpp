#ifndef wp_sender_HPP
#define wp_sender_HPP

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <Eigen/Dense>
#include <sstream>

using std::placeholders::_1;

namespace comp_tasks
{

class WPSender : public rclcpp::Node
{
public:
    explicit WPSender(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_subscriber;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_waypoint_publisher;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_waypoint_publisher;

    bool in_guided_;
    bool previous_guided_state_;
    double p_dist_;
    int wp_reached_counter;
    int wp_reached_max_count;

    geometry_msgs::msg::PoseStamped local_position;
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);
    void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg);
    void publish_local_waypoint();
    geometry_msgs::msg::PoseStamped rel_to_local_cord_converter(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose);

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

} // namespace comp_tasks

#endif // wp_sender_HPP
