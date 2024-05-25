#include "perception/lidar_clusterer_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
#include <yaml-cpp/yaml.h>

#include "rclcpp/rclcpp.hpp"

#include "perception/lib/lidar_calculations.hpp"
#include "perception/lib/helpers.hpp"
#include <string>
#include <sstream>

using namespace std::chrono_literals;

namespace perception
{


  bool LidarClusterer::arePointsValidDistanceAway(std::vector<geometry_msgs::msg::Point> points)
  {
    for (const auto& point : points) {
      double distance = std::sqrt(point.x * point.x + point.y * point.y);
      if (distance < p_min_lidar_dist_ || distance > p_max_lidar_dist_) 
      {
        RCLCPP_ERROR(this->get_logger(), "Points are not within lidar bounds of %f, to %f", p_min_lidar_dist_, p_max_lidar_dist_);
        return false;
      }
    }
    return true;
  }

  bool LidarClusterer::hasEnoughPoints(std::vector<geometry_msgs::msg::Point> points)
  {
    if (!(static_cast<int>(points.size()) >= p_min_points_in_segment_))
    {
      RCLCPP_ERROR(this->get_logger(), "Not enough points in segment. Requires at least %i, but only got %li.", p_min_points_in_segment_, points.size());
      return false;
    }
    return true;
  }
  bool LidarClusterer::isSegmentValid(slg_msgs::msg::Segment segment)
  {
    return hasEnoughPoints(segment.points) && this->arePointsValidDistanceAway(segment.points);
  }
  void LidarClusterer::findClosestMatch(perception_interfaces::msg::BoundingCircle& circle)
  {
    double abs_closest_match_diff = std::numeric_limits<double>::max();
    double closest_match_diff = 0;
    std::string closest_match = "";
    for (const auto& pair : this->p_prop_radii_) {
        double diff = std::abs(circle.radius - pair.second);
        if (diff < abs_closest_match_diff){
            abs_closest_match_diff = diff;
            closest_match_diff = circle.radius - pair.second;
            closest_match = pair.first;
        }
    }
    circle.label = closest_match;
    circle.radius_diff = closest_match_diff;
    return;
  }

  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {

    RCLCPP_ERROR(this->get_logger(), "ERROR message");
    RCLCPP_WARN(this->get_logger(), "WARN message");
    RCLCPP_INFO(this->get_logger(), "INFO message");
    RCLCPP_DEBUG(this->get_logger(), "DEBUG message");

    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    // Declare and get the parameter as a string
    this->declare_parameter<double>("max_lidar_dist", 0.0);
    this->get_parameter("max_lidar_dist", p_max_lidar_dist_);
    RCLCPP_INFO(this->get_logger(), "max_lidar_dist: %f", p_max_lidar_dist_); 

    this->declare_parameter<double>("min_lidar_dist", 0.0);
    this->get_parameter("min_lidar_dist", p_min_lidar_dist_);
    RCLCPP_INFO(this->get_logger(), "min_lidar_dist: %f", p_min_lidar_dist_); 

    this->declare_parameter<int>("min_points_in_segment", 0);
    this->get_parameter("min_points_in_segment", p_min_points_in_segment_);
    RCLCPP_INFO(this->get_logger(), "min_points_in_segment: %i", p_min_points_in_segment_); 
    
    this->declare_parameter<double>("max_radius_diff", 0.0);
    this->get_parameter("max_radius_diff", p_max_radius_diff_);
    RCLCPP_INFO(this->get_logger(), "max_radius_diff: %f", p_max_radius_diff_); 

    this->declare_parameter<std::string>("props_radii", "{}");
    std::string map_string;
    this->get_parameter("props_radii", map_string);

        // Parse the YAML string into a std::map
    try
    {
      YAML::Node yaml_node = YAML::Load(map_string);
      for (YAML::const_iterator it = yaml_node.begin(); it != yaml_node.end(); ++it)
      {
        p_prop_radii_[it->first.as<std::string>()] = it->second.as<double>();
      }

      // Print the map to verify
      for (const auto &pair : p_prop_radii_)
      {
        RCLCPP_INFO(this->get_logger(), "Key: %s, Value: %f", pair.first.c_str(), pair.second);
      }
    }
    catch (const YAML::ParserException &e)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to parse YAML: %s", e.what());
    }
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);

    if (msg->segments.size() > 0 && testFunction())
    {
      perception_interfaces::msg::BoundingCircleArray bounding_circle_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          perception_interfaces::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
          if (bounding_circle.radius_diff < p_max_radius_diff_)
          {
            bounding_circle_array.bounding_circles.push_back(bounding_circle);
          }
          else
          {
            RCLCPP_ERROR(this->get_logger(), "Calculated radius diff of %f is too large, should be less than %f to be considered a prop", bounding_circle.radius_diff, p_max_radius_diff_);
          }
        }
      }
      if (bounding_circle_array.bounding_circles.size() > 0)
      {
        pub_->publish(bounding_circle_array);
      }
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }



  perception_interfaces::msg::BoundingCircle LidarClusterer::createBoundingCircle(std::vector<geometry_msgs::msg::Point> points)
  {
    perception_interfaces::msg::BoundingCircle circle;
    calculateRadius(points, circle);
    this->findClosestMatch(circle);
    return circle;
  }





}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)