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
  : Node("coord_finder", options), new_prop_(false)
  {
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

    prop_sub_ = this->create_subscription<perception_interfaces::msg::PropArray>("/perception/lidar_detected_props", 10, std::bind(&CoordFinder::propCallback, this, _1));
    pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&CoordFinder::poseCallback, this, _1));
    prop_coords_pub_ = this->create_publisher<perception_interfaces::msg::Prop>("perception/prop_coords", 10);
  }

  void CoordFinder::propCallback(const perception_interfaces::msg::PropArray::SharedPtr msg)
  {
    if (msg->props.size() >0)
      prop_msg_ = *msg;
    new_prop_ = true;
  }

  void CoordFinder::poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    // check that the prop msg has been set before publishing a prop
    if (!new_prop_)
    {
      return;
    }
    for (perception_interfaces::msg::Prop prop : prop_msg_.props)
    {
      RCLCPP_ERROR(this->get_logger(), "label: %s", prop.label.c_str());
      if (isValidLabel(prop.label))
      {
          pose_msg_ = *msg;
          RCLCPP_ERROR(this->get_logger(), "heading: %f", getGazeboHeading(pose_msg_.pose.orientation)*(180/M_PI));
          double radius = std::sqrt(prop.point.y * prop.point.y + prop.point.x * prop.point.x);
          double angle = std::atan2(prop.point.y, prop.point.x);

          // Convert relative coordinates to local coordinates 
          double heading = getGazeboHeading(pose_msg_.pose.orientation);
          double prop_x_aligned = radius*cos(angle-((M_PI/2)-heading));
          double prop_y_aligned = radius*sin(angle-((M_PI/2)-heading));
          double prop_x =  pose_msg_.pose.position.x + prop_x_aligned;
          double prop_y =  pose_msg_.pose.position.y + prop_y_aligned;
          // Create and publish the Prop message with the prop's local coordinates 
          perception_interfaces::msg::Prop prop_coords_msg;
          prop_coords_msg.label = prop.label;
          prop_coords_msg.point.x = prop_x;
          prop_coords_msg.point.y = prop_y;

          RCLCPP_DEBUG(this->get_logger(), "x robot = %f", pose_msg_.pose.position.y);
          RCLCPP_DEBUG(this->get_logger(), "y robot = %f", -pose_msg_.pose.position.x);
          RCLCPP_DEBUG(this->get_logger(), "x prop = %f", prop_x);
          RCLCPP_DEBUG(this->get_logger(), "y prop = %f", prop_y);

          prop_coords_pub_->publish(prop_coords_msg);
          new_prop_ = false;
      }
      else
      {
          RCLCPP_DEBUG(this->get_logger(), "No valid props");
      }
    }
  }

  bool CoordFinder::isValidLabel(std::string label)
  {
    std::vector<std::string> prop_labels = {"red_marker", "green_marker", "red_buoy", "green_buoy", "yellow_buoy", "blue_buoy", "black_buoy", "marker", "buoy"};
    auto it = std::find(prop_labels.begin(), prop_labels.end(), label);
    return it != prop_labels.end();
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::CoordFinder)