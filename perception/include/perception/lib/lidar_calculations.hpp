#ifndef LIDARCALCULATIONS_H
#define LIDARCALCULATIONS_H

#include <vector>
#include <string>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/bounding_circle.hpp"
#include <eigen3/Eigen/Dense>

rclcpp::Logger logger = rclcpp::get_logger("lidar_calculations_logger");

bool testFunction();

std::vector<double> extractXorYCoordsToVector(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract);
void calculateRadius(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::BoundingCircle& circle);

#endif // LIDARCALCULATIONS_H