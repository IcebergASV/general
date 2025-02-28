#ifndef TASKLIB_HPP
#define TASKLIB_HPP

#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include "geometry_msgs/msg/point.hpp"
#include <fstream>
#include <vector>
namespace task_lib
{
    rclcpp::Logger logger = rclcpp::get_logger("task_lib_logger");
    std::string toStringWithTwoDecimals(double value);
    bool inGuided(const mavros_msgs::msg::State& state);
    bool inHold(const mavros_msgs::msg::State& state);
    bool inManual(const mavros_msgs::msg::State& state);
    bool isReached(double lat, double lon, const geographic_msgs::msg::GeoPoseStamped& global_pose, double max_dist);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    geometry_msgs::msg::PoseStamped relativePolarToLocalCoords(double radius, double angle, geometry_msgs::msg::PoseStamped local_pose);
    double quaternionToHeading(const geometry_msgs::msg::Quaternion q);
    geometry_msgs::msg::PoseStamped rel_to_local_cord_converter(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose);
    void writePointsToCSV(const std::vector<geometry_msgs::msg::Point>& points, const std::string& filename);
    geographic_msgs::msg::GeoPoseStamped getGlobalWPMsg(double lat, double lon);
    geometry_msgs::msg::PoseStamped getLocalWPMsg(double x, double y);
    geometry_msgs::msg::Point polarToCartesian(double radius, double angle);
    double distBetween2Pnts(geometry_msgs::msg::Point p1, geometry_msgs::msg::Point p2);
    std::vector<geometry_msgs::msg::Point> generateCirclePoints(const geometry_msgs::msg::Point& center, double radius, int num_points);
    std::vector<geometry_msgs::msg::Point> createSemicirce(const std::vector<geometry_msgs::msg::Point>& circle_points, const geometry_msgs::msg::Point& reference_point);
    std::vector<geometry_msgs::msg::Point> createQuarterCircle(const std::vector<geometry_msgs::msg::Point>& semicircle, double heading, bool left);
    std::vector<geometry_msgs::msg::Point> translateSemicircle(const std::vector<geometry_msgs::msg::Point>& semicircle, const geometry_msgs::msg::Point& reference_point, bool align_to_end);
    geometry_msgs::msg::Point computeCentroid(const std::vector<geometry_msgs::msg::Point>& points);
    double computeRelativeAngle(const geometry_msgs::msg::Point& point, const geometry_msgs::msg::Point& reference_point, const geometry_msgs::msg::Point& forward_point);
    void orderPointsRightToLeft(std::vector<geometry_msgs::msg::Point>& points, const geometry_msgs::msg::Point& reference_point);
}
#endif // TASKLIB_HPP