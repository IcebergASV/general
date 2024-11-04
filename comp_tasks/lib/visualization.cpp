#include "comp_tasks/lib/visualization.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
namespace visualization
{

visualization_msgs::msg::MarkerArray create_segment_viz_points(std::vector<slg_msgs::msg::Segment> segment_list)
{
  // Create the visualization message
  visualization_msgs::msg::MarkerArray viz_array;

  // Create a deletion marker to clear the previous points
  visualization_msgs::msg::Marker deletion_marker;
  deletion_marker.header.frame_id = "laser";
  deletion_marker.action = visualization_msgs::msg::Marker::DELETEALL;
  viz_array.markers.push_back(deletion_marker);

  // Create a marker point
  visualization_msgs::msg::Marker viz_points;
  viz_points.header.frame_id = "laser";
  viz_points.lifetime = rclcpp::Duration(0, 10);
  viz_points.ns = "segments";
  viz_points.type = visualization_msgs::msg::Marker::POINTS;
  viz_points.action = visualization_msgs::msg::Marker::ADD;
  viz_points.scale.x = viz_points.scale.y = 0.1;

  // Create a marker centroid
  visualization_msgs::msg::Marker viz_centroids;
  viz_centroids.header.frame_id = "laser";
  viz_centroids.lifetime = rclcpp::Duration(0, 10);
  viz_centroids.ns = "centroids";
  viz_centroids.type = visualization_msgs::msg::Marker::CUBE;
  viz_centroids.action = visualization_msgs::msg::Marker::ADD;
  viz_centroids.scale.x = viz_centroids.scale.y = viz_centroids.scale.z = 0.1;

  // Create a marker id text
  visualization_msgs::msg::Marker viz_text;
  viz_text.header.frame_id = "laser";
  viz_text.lifetime = rclcpp::Duration(0, 10);
  viz_text.ns = "id";
  viz_text.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
  viz_text.action = visualization_msgs::msg::Marker::ADD;
  viz_text.scale.z = 0.25;
  viz_text.color.r = 1.0;
  viz_text.color.g = 1.0;
  viz_text.color.b = 1.0;
  viz_text.color.a = 1.0;

  // Show the segments and the id
  for (std::vector<slg_msgs::msg::Segment>::size_type i = 0; i < segment_list.size(); i++) {
    viz_points.id = i;
    viz_text.id = i;
    viz_centroids.id = i;

    // Change the color of the segment
    std_msgs::msg::ColorRGBA color;
    color.r = 0.90; color.g = 0.8; color.b = 0.2; color.a = 1.0;
    viz_points.color = color;
    viz_centroids.color = color;

    // Iterate over the points of the segment
    slg_msgs::msg::Segment current_segment = segment_list[i];
    for (const auto & point : current_segment.points) {
      viz_points.points.push_back(point);
    }

    // Push to arrays
    viz_array.markers.push_back(viz_points);

    // Clear markers
    viz_points.points.clear();
  }
  return viz_array;
}
}
