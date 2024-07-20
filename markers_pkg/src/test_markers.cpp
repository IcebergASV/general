#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("MarkerNode");

    auto publisher = node->create_publisher<visualization_msgs::msg::MarkerArray>("markerArray", 10);

    visualization_msgs::msg::Marker goal_marker;
    goal_marker.header.frame_id = "odom"; // default world coordinate frame, base_link is robot frame
    goal_marker.header.stamp = rclcpp::Time();
    goal_marker.ns = "props"; // can be anything
    goal_marker.id = 0; // can be any number so long as is unique in namespace
    goal_marker.type = visualization_msgs::msg::Marker::CYLINDER;
    goal_marker.action = visualization_msgs::msg::Marker::ADD;
    goal_marker.pose.position.x = 1;
    goal_marker.pose.position.y = 1;
    goal_marker.pose.position.z = 0.2;
    goal_marker.pose.orientation.x = 0.0;
    goal_marker.pose.orientation.y = 0.0;
    goal_marker.pose.orientation.z = 0.0;
    goal_marker.pose.orientation.w = 1.0;
    goal_marker.scale.x = 0.1;
    goal_marker.scale.y = 0.1;
    goal_marker.scale.z = 0.4;
    goal_marker.color.r = 0.0;
    goal_marker.color.g = 0.0;
    goal_marker.color.b = 1.0;
    goal_marker.color.a = 1.0;

    visualization_msgs::msg::Marker goal_marker2;
    goal_marker2.header.frame_id = "odom";
    goal_marker2.header.stamp = rclcpp::Time();
    goal_marker2.ns = "props";
    goal_marker2.id = 1;
    goal_marker2.type = visualization_msgs::msg::Marker::CYLINDER;
    goal_marker2.action = visualization_msgs::msg::Marker::ADD;
    goal_marker2.pose.position.x = -1;
    goal_marker2.pose.position.y = 1;
    goal_marker2.pose.position.z = 0.2;
    goal_marker2.pose.orientation.x = 0.0;
    goal_marker2.pose.orientation.y = 0.0;
    goal_marker2.pose.orientation.z = 0.0;
    goal_marker2.pose.orientation.w = 1.0;
    goal_marker2.scale.x = 0.1;
    goal_marker2.scale.y = 0.1;
    goal_marker2.scale.z = 0.4;
    goal_marker2.color.r = 0.0;
    goal_marker2.color.g = 1.0;
    goal_marker2.color.b = 0.0;
    goal_marker2.color.a = 1.0;

    visualization_msgs::msg::Marker waypoint;
    waypoint.header.frame_id = "odom";
    waypoint.header.stamp = rclcpp::Time();
    waypoint.ns = "goal";
    waypoint.id = 2;
    waypoint.type = visualization_msgs::msg::Marker::ARROW;
    waypoint.action = visualization_msgs::msg::Marker::ADD;
    geometry_msgs::msg::Point pt1;
    pt1.x = 0;
    pt1.y = 1;
    pt1.z = 0.4;
    geometry_msgs::msg::Point pt2;
    pt2.x = 0;
    pt2.y = 1;
    pt2.z = 0;
    waypoint.points.push_back(pt1);
    waypoint.points.push_back(pt2);
    waypoint.scale.x = 0.1;
    waypoint.scale.y = 0.3;
    waypoint.scale.z = 0.4;
    waypoint.color.r = 1.0;
    waypoint.color.g = 0.0;
    waypoint.color.b = 0.0;
    waypoint.color.a = 1.0;

    visualization_msgs::msg::MarkerArray ar;
    ar.markers.push_back(goal_marker);
    ar.markers.push_back(goal_marker2);
    ar.markers.push_back(waypoint);


    rclcpp::WallRate loop_rate(2);

    while (rclcpp::ok()) {
        RCLCPP_INFO(node->get_logger(), "Running marker node");
        publisher->publish(ar);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}