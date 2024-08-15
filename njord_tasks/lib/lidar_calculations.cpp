#include "njord_tasks/lib/lidar_calculations.hpp"

namespace lidar_calculations
{

std::vector<double> extractXorYCoordsToVector(const std::vector<geometry_msgs::msg::Point>& points, std::string coords_to_extract)
{
  std::vector<double> x_or_y_coordinates;
  for (const auto& point : points) {
      coords_to_extract == "x" ? x_or_y_coordinates.push_back(point.x) : x_or_y_coordinates.push_back(point.y);
  }
  return x_or_y_coordinates;
}

bool arePointsValidDistanceAway(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist)
{
  for (const auto& point : points) {
    double distance = std::sqrt(point.x * point.x + point.y * point.y);
    if (distance < min_dist || distance > max_dist) 
    {
      RCLCPP_INFO(logger, "Point with distance: %f is not within lidar bounds of %f, to %f", distance, min_dist, max_dist);
      return false;
    }
  }
  return true;
}

bool segmentInFOV(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist, double fov)
{
  for (const auto& point : points) {
    double distance = std::sqrt(point.x * point.x + point.y * point.y);

    if (distance >= min_dist && distance <= max_dist && checkFOV(point, fov)) 
    {
      return true;
    }
  }
  return false;
}

double getSegmentLength(const std::vector<geometry_msgs::msg::Point>& points)
{
  geometry_msgs::msg::Point p1 = points.front();
  geometry_msgs::msg::Point p2 = points.back();pow (7.0, 3.0);
  double distance = std::sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
  RCLCPP_INFO(logger, "Segment length: %f", distance);
  return distance;
}

bool checkFOV(geometry_msgs::msg::Point point, double fov) // This whole function is stupid but I got too frustrated to figure out a better way, it works for now
{
  double x = -point.y; // TODO THIS IS ONLY FOR SIM
  double y = point.x; // TODO THIS IS ONLY FOR SIM

  double angle_from_straight;

  if ( x > 0 && y > 0) // Q1
  {
    angle_from_straight = (M_PI/2) - atan(-point.x / point.y);
  }

  if ( x < 0 && y > 0) // Q2
  {
    angle_from_straight = atan(-point.x / point.y) + (M_PI/2);
  }

  if ( x < 0 && y < 0) // Q3
  {
    angle_from_straight = atan(-point.x / point.y) + (M_PI/2);
  }

  if ( x > 0 && y < 0) // Q4
  {
    angle_from_straight = (M_PI/2) - atan(-point.x / point.y);
  }

  RCLCPP_DEBUG(logger, "Angle from straight %f", angle_from_straight);

  double fov_rad = fov*M_PI/180;
  if (angle_from_straight < fov_rad)
  {
    return true;
  }
  RCLCPP_DEBUG(logger, "Point %f rad from straight not within Lidar FOV of %f", angle_from_straight, fov_rad);
  return false;
}

bool hasEnoughPoints(int points_size, int min_points)
{
  if (!(points_size >= min_points))
  {
    RCLCPP_DEBUG(logger, "Not enough points in segment. Requires at least %i, but only got %i.", min_points, points_size);
    return false;
  }
  return true;
}
}