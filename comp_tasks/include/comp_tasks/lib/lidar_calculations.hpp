#ifndef LIDARCALCULATIONS_H
#define LIDARCALCULATIONS_H

#include <vector>
#include <string>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include <eigen3/Eigen/Dense>

namespace lidar_calculations
{
    rclcpp::Logger logger = rclcpp::get_logger("lidar_calculations_logger");

    std::vector<double> extractXorYCoordsToVector(const std::vector<geometry_msgs::msg::Point>& points, std::string coords_to_extract);
    bool arePointsValidDistanceAway(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist);
    bool hasEnoughPoints(int points_size, int min_points);
    bool segmentInFOV(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist, double fov);
    bool checkFOV(geometry_msgs::msg::Point point, double fov);
    double getSegmentLength(const std::vector<geometry_msgs::msg::Point>& points);
}
#endif // LIDARCALCULATIONS_H