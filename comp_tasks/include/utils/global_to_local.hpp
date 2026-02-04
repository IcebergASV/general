#ifndef GLOBAL_TO_LOCAL_CONVERTER_HPP
#define GLOBAL_TO_LOCAL_CONVERTER_HPP

#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <geographic_msgs/msg/geo_pose_stamped.hpp>
#include <geographic_msgs/msg/geo_point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

#include <GeographicLib/LocalCartesian.hpp>

class GlobalToLocalConverter : public rclcpp::Node
{
public:
    GlobalToLocalConverter();

private:
    // Callbacks
    void globalCallback(
        const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg
    );

    void refCallback(
        const geographic_msgs::msg::GeoPointStamped::SharedPtr msg
    );

    // ROS interfaces
    rclcpp::Subscription<geographic_msgs::msg::GeoPoseStamped>::SharedPtr
        global_sub_;

    rclcpp::Subscription<geographic_msgs::msg::GeoPointStamped>::SharedPtr
        ref_sub_;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr
        local_pub_;

    // Geographic conversion
    std::unique_ptr<GeographicLib::LocalCartesian> enu_converter_;

    // Reference origin (WGS84)
    double lat_ref_{0.0};
    double lon_ref_{0.0};
    double alt_ref_{0.0};
};

#endif // GLOBAL_TO_LOCAL_CONVERTER_HPP
