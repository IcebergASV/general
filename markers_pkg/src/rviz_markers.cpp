#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "markers_pkg_interfaces/msg/prop.hpp"
#include "markers_pkg_interfaces/msg/prop_array.hpp"

using std::placeholders::_1;


class PropSubscriber : public rclcpp::Node
{
public:
    PropSubscriber()
    : Node("prop_subscriber")
    {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

        //subscription_ = this->create_subscription<markers_pkg_interfaces::msg::PropArray>("props", 10, std::bind(&PropSubscriber::props_callback, this, _1));
        //subscription2_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10, std::bind(&PropSubscriber::waypoint_callback, this, _1));
        subscription3_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&PropSubscriber::trail_callback, this, _1));
        publisher = this->create_publisher<visualization_msgs::msg::Marker>("robotTrail", 10);
        publisher2 = this->create_publisher<visualization_msgs::msg::Marker>("robotPosition", 10);
    }

    std::vector<geometry_msgs::msg::Point> robot_trail;

private:
    // void props_callback(const markers_pkg_interfaces::msg::PropArray msg)
    // {
    //     auto publisher = this->create_publisher<visualization_msgs::msg::MarkerArray>("markerArray", 10);
    //     RCLCPP_INFO(this->get_logger(), "Received array.");
    //     visualization_msgs::msg::MarkerArray ar;
    //     markers_pkg_interfaces::msg::PropArray propArray = msg;
    //     for (int i = 0; (unsigned)i < propArray.props.size(); i++) {
    //         visualization_msgs::msg::Marker marker;
    //         marker.header.frame_id = "odom";
    //         marker.header.stamp = rclcpp::Time();
    //         marker.ns = "props";
    //         marker.id = i;
    //         marker.type = visualization_msgs::msg::Marker::CYLINDER;
    //         marker.action = visualization_msgs::msg::Marker::ADD;
    //         marker.pose.position.x = propArray.props[i].x;
    //         marker.pose.position.y = propArray.props[i].y;
    //         marker.pose.position.z = 0.2;
    //         marker.pose.orientation.x = 0.0;
    //         marker.pose.orientation.y = 0.0;
    //         marker.pose.orientation.z = 0.0;
    //         marker.pose.orientation.w = 1.0;
    //         marker.scale.x = 0.1;
    //         marker.scale.y = 0.1;
    //         marker.scale.z = 0.4;
    //         if (propArray.props[i].color == "red") {
    //             marker.color.r = 1.0;
    //             marker.color.g = 0.0;
    //             marker.color.b = 0.0;
    //         }
    //         if (propArray.props[i].color == "green") {
    //             marker.color.r = 0.0;
    //             marker.color.g = 1.0;
    //             marker.color.b = 0.0;
    //         }
    //         if (propArray.props[i].color == "blue") {
    //             marker.color.r = 0.0;
    //             marker.color.g = 0.0;
    //             marker.color.b = 1.0;
    //         }
    //         marker.color.a = 1.0;
        
    //         ar.markers.push_back(marker);
    //     }

    //     publisher->publish(ar);
    // }

    // void waypoint_callback(const geometry_msgs::msg::PoseStamped msg)
    // {
    //     auto publisher = this->create_publisher<visualization_msgs::msg::Marker>("wp", 10);
    //     visualization_msgs::msg::Marker waypoint;
    //     geometry_msgs::msg::PoseStamped goal = msg;

    //     waypoint.header.frame_id = "odom";
    //     waypoint.header.stamp = rclcpp::Time();
    //     waypoint.ns = "goal";
    //     waypoint.id = 0;
    //     waypoint.type = visualization_msgs::msg::Marker::ARROW;
    //     waypoint.action = visualization_msgs::msg::Marker::ADD;
    //     geometry_msgs::msg::Point pt1;
    //     pt1.x = goal.pose.position.x;
    //     pt1.y = goal.pose.position.y;
    //     pt1.z = 0.4;
    //     geometry_msgs::msg::Point pt2;
    //     pt2.x = goal.pose.position.x;
    //     pt2.y = goal.pose.position.y;
    //     pt2.z = 0;
    //     waypoint.points.push_back(pt1);
    //     waypoint.points.push_back(pt2);
    //     waypoint.scale.x = 0.1;
    //     waypoint.scale.y = 0.3;
    //     waypoint.scale.z = 0.4;
    //     waypoint.color.r = 1.0;
    //     waypoint.color.g = 0.0;
    //     waypoint.color.b = 0.0;
    //     waypoint.color.a = 1.0;

    //     RCLCPP_INFO(this->get_logger(), "Publishing waypoint.");
    //     publisher->publish(waypoint);
    // }

    void trail_callback(const geometry_msgs::msg::PoseStamped msg)
    {


        visualization_msgs::msg::Marker trail;
        visualization_msgs::msg::Marker robot;
        geometry_msgs::msg::PoseStamped pos = msg;

        // boat trail
        trail.header.frame_id = "odom";
        trail.header.stamp = rclcpp::Time();
        trail.ns = "trail";
        trail.id = 0;
        trail.type = visualization_msgs::msg::Marker::LINE_STRIP;
        trail.action = visualization_msgs::msg::Marker::ADD;
        geometry_msgs::msg::Point pt;
        pt.x = pos.pose.position.x;
        pt.y = pos.pose.position.y;
        robot_trail.push_back(pt);
        trail.points = robot_trail;
        trail.scale.x = 0.01;
        trail.color.r = 0.0;
        trail.color.g = 1.0;
        trail.color.b = 1.0;
        trail.color.a = 0.5;

        // boat marker
        robot.header.frame_id = "odom";
        robot.header.stamp = rclcpp::Time();
        robot.ns = "boat";
        robot.id = 0;
        robot.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
        robot.mesh_resource = "file:///home/repos/icebergasv/Desktop/IcebergASV/ros2_ws/src/markers_pkg/models/boat-assembly-simple.STL";
        robot.action = visualization_msgs::msg::Marker::ADD;
        robot.pose.position.x = pos.pose.position.x-0.6;
        robot.pose.position.y = pos.pose.position.y-0.345;
        robot.pose.position.z = 0;
        robot.pose.orientation.x = pos.pose.orientation.x;
        robot.pose.orientation.y = pos.pose.orientation.y;
        robot.pose.orientation.z = pos.pose.orientation.z;
        robot.pose.orientation.w = pos.pose.orientation.w;
        robot.scale.x = 0.001;
        robot.scale.y = 0.001;
        robot.scale.z = 0.001;
        robot.color.a = 1.0;
        robot.color.r = 1.0;
        robot.color.g = 1.0;
        robot.color.b = 1.0;

        RCLCPP_INFO(this->get_logger(), "Publishing trail point and boat position.");
        publisher->publish(trail);
        publisher2->publish(robot);
    }
    
    std::shared_ptr<rclcpp::Subscription<markers_pkg_interfaces::msg::PropArray>> subscription_;
    std::shared_ptr<rclcpp::Subscription<geometry_msgs::msg::PoseStamped>> subscription2_;
    std::shared_ptr<rclcpp::Subscription<geometry_msgs::msg::PoseStamped>> subscription3_;
    std::shared_ptr<rclcpp::Publisher<visualization_msgs::msg::Marker>> publisher;
    std::shared_ptr<rclcpp::Publisher<visualization_msgs::msg::Marker>> publisher2;
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::WallRate loop_rate(2);

    while (rclcpp::ok()) {
        rclcpp::spin(std::make_shared<PropSubscriber>());
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}