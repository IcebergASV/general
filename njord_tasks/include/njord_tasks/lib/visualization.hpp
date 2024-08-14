#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "slg_msgs/segment2D.hpp"
#include "std_msgs/msg/color_rgba.hpp"
#include <rclcpp/rclcpp.hpp>

namespace visualization
{
    rclcpp::Logger logger = rclcpp::get_logger("visualization_logger");

    visualization_msgs::msg::MarkerArray create_segment_viz_points(std::vector<slg_msgs::msg::Segment> segment_list);
}
#endif // VISUALIZATION_HPP