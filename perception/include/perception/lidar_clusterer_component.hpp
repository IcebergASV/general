#ifndef COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using std::placeholders::_1;

namespace perception
{

class LidarClusterer : public rclcpp::Node
{
public:
  explicit LidarClusterer(const rclcpp::NodeOptions & options);

protected:
  void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);

private:
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_;
};

}  // namespace composition

#endif  // COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_