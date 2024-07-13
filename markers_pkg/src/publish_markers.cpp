#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "markers_pkg_interfaces/msg/prop.hpp"
#include "markers_pkg_interfaces/msg/prop_array.hpp"
#include "markers_pkg_interfaces/msg/waypoint.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("FakePropPub");

    auto publisher = node->create_publisher<markers_pkg_interfaces::msg::PropArray>("props", 10);
    auto publisher2 = node->create_publisher<markers_pkg_interfaces::msg::Waypoint>("waypoint", 10);

    markers_pkg_interfaces::msg::Prop p1;
    p1.color = "red";
    p1.x = 1;
    p1.y = 1;

    markers_pkg_interfaces::msg::Prop p2;
    p2.color = "blue";
    p2.x = 1;
    p2.y = -1;

    markers_pkg_interfaces::msg::Prop p3;
    p3.color = "green";
    p3.x = 3;
    p3.y = 3;

    markers_pkg_interfaces::msg::PropArray ar;
    ar.props.push_back(p1);
    ar.props.push_back(p2);
    ar.props.push_back(p3);
    
    markers_pkg_interfaces::msg::Waypoint wp;
    wp.x = 1;
    wp.y = 0;

    rclcpp::WallRate loop_rate(2);

    while (rclcpp::ok()) {
        RCLCPP_INFO(node->get_logger(), "Fake prop publisher node");
        publisher->publish(ar);
        publisher2->publish(wp);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}