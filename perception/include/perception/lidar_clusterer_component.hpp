#ifndef COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

namespace perception
{

class LidarClusterer : public rclcpp::Node
{
public:
  explicit LidarClusterer(const rclcpp::NodeOptions & options);

protected:
  void on_timer();

private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}  // namespace composition

#endif  // COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_