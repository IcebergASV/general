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
  : Node("coord_finder", options)
  {
    prop_sub_ = this->create_subscription<perception_interfaces::msg::LidarDetectedProp>("segments", 10, std::bind(&CoordFinder::propCallback, this, _1));
    pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", 10, std::bind(&CoordFinder::poseCallback, this, _1));
   // pub_ = this->create_publisher<perception_interfaces::msg::LidarDetectedPropArray>("perception/lidar_detected_props", 10);

    //on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&CoordFinder::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult CoordFinder::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    //if (params[0].get_name() == "min_lidar_dist") { p_min_lidar_dist_ = params[0].as_double(); }
    //else if (params[0].get_name() == "max_lidar_dist") { p_max_lidar_dist_ = params[0].as_double(); }
    //else if (params[0].get_name() == "min_points_in_segment") { p_min_points_in_segment_ = params[0].as_int(); }
    //else if (params[0].get_name() == "max_radius_diff") { p_max_radius_diff_ = params[0].as_double(); }
    //else if (params[0].get_name() == "lidar_fov") { p_lidar_fov_ = params[0].as_double(); }
    //else {
    //  RCLCPP_ERROR(this->get_logger(), "Invalid Param");
    //  result.successful = false;
    //  return result;
    //}
//
    result.successful = true;
    return result;
  }

  void CoordFinder::propCallback(const perception_interfaces::msg::LidarDetectedProp::SharedPtr msg)
  {
    prop_msg_ = *msg;
  }

  void CoordFinder::poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
  {
    // check that the prop msg has been set before publishing a prop
    if (isValidLabel(prop_msg_.label))
    {
        pose_msg_ = *msg;
        RCLCPP_DEBUG(this->get_logger(), "heading: %f", getGazeboHeading(pose_msg_.pose.orientation)*(180/M_PI));
        double radius = std::sqrt(prop_msg_.center.y * prop_msg_.center.y + prop_msg_.center.x * prop_msg_.center.x);
        double angle = std::atan2(prop_msg_.center.y, prop_msg_.center.x);
        // Convert relative polar coordinates to local coordinates 
        double heading = getGazeboHeading(pose_msg_.pose.orientation);
        double prop_x_aligned = radius*cos(angle-((M_PI/2)-heading));
        double prop_y_aligned = radius*sin(angle-((M_PI/2)-heading));
        double prop_x =  pose_msg_.pose.position.x + prop_x_aligned;
        double prop_y =  pose_msg_.pose.position.y + prop_y_aligned;
        // Create and publish the Prop message with the prop's local coordinates 
        //auto local_prop_msg = std::make_shared<prop_mapper::msg::Prop>();
        //local_prop_msg->prop_label = prop_msg_.label;
        //local_prop_msg->point.x = prop_x;
        //local_prop_msg->point.y = prop_y;
        //RCLCPP_DEBUG(this->get_logger(), "x robot = %f", pose_msg_.pose.position.y);
        //RCLCPP_DEBUG(this->get_logger(), "y robot = %f", -pose_msg_.pose.position.x);
        //RCLCPP_DEBUG(this->get_logger(), "x prop = %f", prop_x);
        //RCLCPP_DEBUG(this->get_logger(), "y prop = %f", prop_y);
        //pub_prop_coords_->publish(*local_prop_msg);
    }
    else
    {
        RCLCPP_DEBUG(this->get_logger(), "No valid props");
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