#ifndef LOCAL_TO_GLOBAL_CONVERTER_HPP
#define LOCAL_TO_GLOBAL_CONVERTER_HPP

#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <geographic_msgs/msg/geo_point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <comp_tasks_interfaces/msg/wp_group_info.hpp>

#include <GeographicLib/LocalCartesian.hpp>

class LocalToGlobalConverter : public rclcpp::Node
{
public:
    LocalToGlobalConverter();

private:
    // Callbacks
    void wpGroupCallback(
        const comp_tasks_interfaces::msg::WpGroupInfo::SharedPtr msg
    );

    void refCallback(
        const geographic_msgs::msg::GeoPointStamped::SharedPtr msg
    );

    // ROS interfaces
    rclcpp::Subscription<comp_tasks_interfaces::msg::WpGroupInfo>::SharedPtr
        wp_group_sub_;

    rclcpp::Subscription<geographic_msgs::msg::GeoPointStamped>::SharedPtr
        ref_sub_;

    rclcpp::Publisher<geographic_msgs::msg::GeoPointStamped>::SharedPtr
        global_pub_;

    // Geographic conversion
    std::unique_ptr<GeographicLib::LocalCartesian> enu_converter_;

    // Reference origin (WGS84)
    double lat_ref_{0.0};
    double lon_ref_{0.0};
    double alt_ref_{0.0};
};

#endif // LOCAL_TO_GLOBAL_CONVERTER_HPP
