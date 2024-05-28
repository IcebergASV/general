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
  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {
    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    LidarClusterer::getParam<double>("max_lidar_dist", p_max_lidar_dist_, 0.0, "Maximum accepted range of lidar readings in m");
    LidarClusterer::getParam<double>("min_lidar_dist", p_min_lidar_dist_, 0.0, "Minimum accepted range of lidar readings in m");
    LidarClusterer::getParam<int>("min_points_in_segment", p_min_points_in_segment_, 0, "Minimum accepted points in a laser_segment");
    LidarClusterer::getParam<double>("max_radius_diff", p_max_radius_diff_, 0.0, "Maximum difference between measured and expected prop radii to consider a laser_segment a prop, in m");
    LidarClusterer::getStringParamConvertToMap<double>("props_radii", p_prop_radii_, "{}", "List of prop radii in m");
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    if (msg->segments.size() > 0)
    {
      perception_interfaces::msg::BoundingCircleArray bounding_circle_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          perception_interfaces::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
          if (measuredRadiusIsCloseToExpected(bounding_circle.radius_diff))
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

  bool LidarClusterer::isSegmentValid(slg_msgs::msg::Segment segment)
  {
    return hasEnoughPoints(segment.points.size(), p_min_points_in_segment_) && arePointsValidDistanceAway(segment.points, p_min_lidar_dist_, p_max_lidar_dist_);
  }

  bool LidarClusterer::measuredRadiusIsCloseToExpected(double radius_diff)
  {
    return radius_diff < p_max_radius_diff_;
  }

  perception_interfaces::msg::BoundingCircle LidarClusterer::createBoundingCircle(std::vector<geometry_msgs::msg::Point> points)
  {
    perception_interfaces::msg::BoundingCircle circle;
    calculateRadius(points, circle);
    this->findClosestMatchAndSetRadiusDiff(circle);
    return circle;
  }

  void LidarClusterer::findClosestMatchAndSetRadiusDiff(perception_interfaces::msg::BoundingCircle& circle)
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
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)