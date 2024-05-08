#ifndef COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "geometry_msgs/msgs/Point"

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
};

}  // namespace composition

#endif  // COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_