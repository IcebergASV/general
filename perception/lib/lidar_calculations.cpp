#include "perception/lib/lidar_calculations.hpp"

std::vector<double> extractXorYCoordsToVector(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract)
{
  std::vector<double> x_or_y_coordinates;
  for (const auto& point : points) {
      coords_to_extract == "x" ? x_or_y_coordinates.push_back(point.x) : x_or_y_coordinates.push_back(point.y);
  }
  return x_or_y_coordinates;
}

// Best fit circle equation: (x − k)^2 + (y − m)^2 = r^2
// Where (k,m) is the center, and r is the radius
// Based off of https://goodcalculators.com/best-fit-circle-least-squares-calculator/
//
// circle is an output param
void calculateRadius(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::LidarDetectedProp& prop)
{
  std::vector<double> x_coords= extractXorYCoordsToVector(points, "x");
  std::vector<double> y_coords= extractXorYCoordsToVector(points, "y");

  if (!(x_coords.size() == y_coords.size()))
  {
    RCLCPP_WARN(logger, "Size of X and Y vectors don't match");
  }
  
  Eigen::Matrix<double, 3, 3> matrixA;
  double mA_11 = 0, mA_12 = 0, mA_13 = 0, mA_21 = 0, mA_22 = 0, mA_23 = 0, mA_31 = 0, mA_32 = 0, mA_33 = 0;
  for (size_t i = 0; i < x_coords.size(); i++) {
      mA_11 = mA_11 + pow(x_coords[i], 2);
      mA_12 = mA_12 + (x_coords[i]*y_coords[i]);
      mA_13 = mA_13 + x_coords[i];
      mA_22 = mA_22 + pow(y_coords[i], 2);
      mA_23 = mA_23 + y_coords[i];
  }

  mA_21 = mA_12;
  mA_31 = mA_13;
  mA_32 = mA_23;
  mA_33 = x_coords.size();
  matrixA << mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33;

  Eigen::Matrix<double, 3, 1> vectorX;
  double vX_1 = 0, vX_2 = 0, vX_3 = 0;
  for (size_t i = 0; i < x_coords.size(); i++) {
      vX_1 = vX_1 + x_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
      vX_2 = vX_2 + y_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
      vX_3 = vX_3 + (pow(x_coords[i], 2) + pow(y_coords[i], 2));
  }
  vectorX << vX_1, vX_2, vX_3;

  Eigen::Matrix<double, 3, 1> result = matrixA.colPivHouseholderQr().solve(vectorX.cast<double>());

  double a = result[0], b = result[1], c = result[2];
  double k = a / 2;
  double m = b / 2;
  prop.radius = (sqrt(4*c + pow(a, 2) + pow(b, 2))) / 2;
  prop.center.x = k;
  prop.center.y = m;

  return;
}

bool arePointsValidDistanceAway(std::vector<geometry_msgs::msg::Point> points, double min_dist, double max_dist)
{
  for (const auto& point : points) {
    double distance = std::sqrt(point.x * point.x + point.y * point.y);
    if (distance < min_dist || distance > max_dist) 
    {
      RCLCPP_ERROR(logger, "Points are not within lidar bounds of %f, to %f", min_dist, max_dist);
      return false;
    }
  }
  return true;
}

bool hasEnoughPoints(int points_size, int min_points)
{
  if (!(points_size >= min_points))
  {
    RCLCPP_ERROR(logger, "Not enough points in segment. Requires at least %i, but only got %i.", min_points, points_size);
    return false;
  }
  return true;
}