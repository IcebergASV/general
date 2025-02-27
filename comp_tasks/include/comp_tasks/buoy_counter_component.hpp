#ifndef buoy_counter_HPP
#define buoy_counter_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <yolov8_msgs/msg/detection_array.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2/LinearMath/Matrix3x3.h>

namespace comp_tasks
{
class BuoyCounter : public rclcpp::Node
{
public:
    explicit BuoyCounter(const rclcpp::NodeOptions & options);

private:
    void detection_callback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg);
    void globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg);
    void localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr detection_sub_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr global_pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr local_pose_sub_;

    std::mutex pose_mutex_;
    std::mutex buoy_mutex_;
    sensor_msgs::msg::NavSatFix current_global_pose_;
    geometry_msgs::msg::PoseStamped::SharedPtr current_local_pose_;

    std::vector<geometry_msgs::msg::Point> known_buoys_;
    double exclusion_radius_ = 5.0;
    std::string desired_class_;
    std::shared_ptr<tf2::Matrix3x3> rotation_mat;
};
} // namespace comp_tasks

#endif // buoy_counter_HPP