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

namespace task_lib
{
    rclcpp::Logger logger = rclcpp::get_logger("task_lib_logger");

    bool inGuided(const mavros_msgs::msg::State& state);
    bool inHold(const mavros_msgs::msg::State& state);
    bool inManual(const mavros_msgs::msg::State& state);
    bool isReached(double lat, double lon, const geographic_msgs::msg::GeoPoseStamped& global_pose, double max_dist);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    geometry_msgs::msg::PoseStamped relativePolarToLocalCoords(double radius, double angle, geometry_msgs::msg::PoseStamped local_pose);
    double quaternionToHeading(const geometry_msgs::msg::Quaternion q);
    geometry_msgs::msg::PoseStamped rel_to_local_cord_converter(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose);

    geographic_msgs::msg::GeoPoseStamped getGlobalWPMsg(double lat, double lon);
    geometry_msgs::msg::PoseStamped getLocalWPMsg(double x, double y);
    geometry_msgs::msg::Point polarToCartesian(double radius, double angle);
    double distBetween2Pnts(geometry_msgs::msg::Point p1, geometry_msgs::msg::Point p2);
}
#endif // TASKLIB_HPP