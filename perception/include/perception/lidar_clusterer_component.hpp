#ifndef COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/bounding_circle.hpp"
#include "perception_interfaces/msg/bounding_circle_array.hpp"
#include <eigen3/Eigen/Dense>

using std::placeholders::_1;

namespace perception
{

class LidarClusterer : public rclcpp::Node
{
public:
  explicit LidarClusterer(const rclcpp::NodeOptions & options);

protected:
  void scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg);

private:
  rclcpp::Subscription<slg_msgs::msg::SegmentArray>::SharedPtr sub_;
  rclcpp::Publisher<perception_interfaces::msg::BoundingCircleArray>::SharedPtr pub_;
  std::vector<double> extractCoordinates(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract);
  bool arePointsValidDistanceAway(std::vector<geometry_msgs::msg::Point> points);
  bool isSegmentValid(slg_msgs::msg::Segment segment);
  perception_interfaces::msg::BoundingCircle createBoundingCircle(std::vector<geometry_msgs::msg::Point> points);
  void findClosestMatch(perception_interfaces::msg::BoundingCircle& circle);
  void calculateRadius(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::BoundingCircle& circle);
  std::map<std::string, double> prop_radii_;
};

}  // namespace composition

#endif  // COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_