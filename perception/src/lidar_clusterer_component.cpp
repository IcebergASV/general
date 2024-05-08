#include "perception/lidar_clusterer_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"


using namespace std::chrono_literals;

namespace perception
{
  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {

    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));

  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)