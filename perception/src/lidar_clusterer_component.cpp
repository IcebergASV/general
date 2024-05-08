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

    if (msg->segments.length > 0)
    {
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          // create lidar_bounding_radius msgs
          float radius = calculateRadius(segment.points);
          matchRadius(msg);
          publish;

        }
      }
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }

  bool LidarClusterer::isSegmentValid(Segment segment)
  {
    return hasEnoughPoints(segment.points) && arePointsValidDistanceAway(segment.points);
  }

  bool LidarClusterer::hasEnoughPoints(Point[] points)
  {
    int min_points = 5; //make a param later
    return segment.point.length > min_points;
    // TODO add debugging if false
  }

  bool arePointsValidDistanceAway(Points[] points)
  {
    //TODO - add debugging if false
    return true;
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)