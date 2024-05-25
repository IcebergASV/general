#include "perception/lib/lidar_calculations.hpp"

bool testFunction()
{
  return true;
}

std::vector<double> LidarClusterer::extractXorYCoordsToVector(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract)
{
  std::vector<double> x_or_y_coordinates;
  for (const auto& point : points) {
      coords_to_extract == "x" ? x_or_y_coordinates.push_back(point.x) : x_or_y_coordinates.push_back(point.y);
  }
  return x_or_y_coordinates;
}