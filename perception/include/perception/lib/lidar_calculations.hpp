#ifndef LIDARCALCULATIONS_H
#define LIDARCALCULATIONS_H

#include <vector>
#include <string>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/lidar_detected_prop.hpp"
#include <eigen3/Eigen/Dense>

namespace lidar_calculations
{
    rclcpp::Logger logger = rclcpp::get_logger("lidar_calculations_logger");

    std::vector<double> extractXorYCoordsToVector(const std::vector<geometry_msgs::msg::Point>& points, std::string coords_to_extract);
    void calculateRadius(const std::vector<geometry_msgs::msg::Point>& points, perception_interfaces::msg::LidarDetectedProp& prop);
    bool arePointsValidDistanceAway(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist);
    bool hasEnoughPoints(int points_size, int min_points);
    std::vector<geometry_msgs::msg::Point> getPointsWithinBounds(const std::vector<geometry_msgs::msg::Point>& points, double min_dist, double max_dist, double fov);
    bool checkFOV(geometry_msgs::msg::Point point, double fov);
}
#endif // LIDARCALCULATIONS_H