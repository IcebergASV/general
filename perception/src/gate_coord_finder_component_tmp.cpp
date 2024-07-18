#include <cmath>

#include "perception/coord_finder_component.h"

double getGazeboHeading(const geometry_msgs::msg::Quaternion q)
{
  // yaw (z-axis rotation)
  double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
  double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
  double yaw = std::atan2(siny_cosp, cosy_cosp);
  return yaw;
};

namespace perception
{

  CoordFinder::CoordFinder(const rclcpp::NodeOptions & options)
  : Node("coord_finder", options), new_gate_(false)
  {
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

    prop_sub_ = this->create_subscription<perception_interfaces::msg::Gate>("/perception/relative_gates", 10, std::bind(&CoordFinder::gateCallback, this, _1));
    pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&CoordFinder::poseCallback, this, _1));
    prop_coords_pub_ = this->create_publisher<perception_interfaces::msg::Gate>("perception/gate_coords", 10);
  }

  void CoordFinder::gateCallback(const perception_interfaces::msg::Gate::SharedPtr msg)
  {
    //if (msg->gates.size() >0)
    gate_msg_ = *msg;
    new_gate_ = true;
  }

  void CoordFinder::poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    // check that the prop msg has been set before publishing a prop
    if (!new_gate_)
    {
      return;
    }

    RCLCPP_INFO(this->get_logger(), "Pose callback");
    perception_interfaces::msg::Gate gate_with_local_coords;
    pose_msg_ = *msg;
    gate_with_local_coords.red_marker = relativeToLocalCoords(gate_msg_.red_marker);
    gate_with_local_coords.green_marker = relativeToLocalCoords(gate_msg_.green_marker);
    prop_coords_pub_->publish(gate_with_local_coords);
    new_gate_ = false;
  }

  bool CoordFinder::isValidLabel(std::string label)
  {
    std::vector<std::string> prop_labels = {"red_marker", "green_marker", "red_buoy", "green_buoy", "yellow_buoy", "blue_buoy", "black_buoy", "marker", "buoy"};
    auto it = std::find(prop_labels.begin(), prop_labels.end(), label);
    return it != prop_labels.end();
  }

  perception_interfaces::msg::Prop CoordFinder::relativeToLocalCoords(perception_interfaces::msg::Prop relative_prop)
  {
    if (relative_prop.point.x == 0.0 && relative_prop.point.y)
    {
      RCLCPP_ERROR(this->get_logger(), "Empty prop passed into relativeToLocalCoords()");
    }
    
    perception_interfaces::msg::Prop local_prop;
    RCLCPP_INFO(this->get_logger(), "PROP x,y = %f,%f", relative_prop.point.x, relative_prop.point.y);
    RCLCPP_INFO(this->get_logger(), "heading: %f", getGazeboHeading(pose_msg_.pose.orientation)*(180/M_PI));
    double radius = std::sqrt(relative_prop.point.y * relative_prop.point.y + relative_prop.point.x * relative_prop.point.x);
    double angle = std::atan2(relative_prop.point.y, relative_prop.point.x);
    // Convert relative coordinates to local coordinates 
    double heading = getGazeboHeading(pose_msg_.pose.orientation);
    double prop_x_aligned = radius*cos(angle-((M_PI/2)-heading));
    double prop_y_aligned = radius*sin(angle-((M_PI/2)-heading));
    double prop_x =  pose_msg_.pose.position.x + prop_x_aligned;
    double prop_y =  pose_msg_.pose.position.y + prop_y_aligned;
    RCLCPP_INFO(this->get_logger(), "radius = %f", radius);
    RCLCPP_INFO(this->get_logger(), "angle = %f", angle);
    RCLCPP_INFO(this->get_logger(), "Heading= %f", heading);
    RCLCPP_INFO(this->get_logger(), "prop_x_aligned = %f", prop_x_aligned);
    RCLCPP_INFO(this->get_logger(), "prop_y_aligned = %f", prop_y_aligned);

    // Create and publish the Prop message with the prop's local coordinates 
    perception_interfaces::msg::Prop prop_coords_msg;
    prop_coords_msg.label = relative_prop.label;
    prop_coords_msg.point.x = -prop_y; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
    prop_coords_msg.point.y = prop_x; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
    RCLCPP_INFO(this->get_logger(), "x robot = %f", pose_msg_.pose.position.y);
    RCLCPP_INFO(this->get_logger(), "y robot = %f", -pose_msg_.pose.position.x);
    RCLCPP_INFO(this->get_logger(), "x prop = %f", prop_x);
    RCLCPP_INFO(this->get_logger(), "y prop = %f", prop_y);
    return prop_coords_msg;
  }


}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::CoordFinder)