#ifndef TASKLIB_HPP
#define TASKLIB_HPP

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

namespace task_lib
{
    rclcpp::Logger logger = rclcpp::get_logger("task_lib_logger");

    bool inGuided(const mavros_msgs::msg::State& state);
    bool isReached(double lat, double lon, const geographic_msgs::msg::GeoPoseStamped& global_pose, double max_dist);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    geometry_msgs::msg::Point relativePolarToLocalCoords(double radius, double angle);
    double quaternionToHeading(const geometry_msgs::msg::Quaternion q);

    geographic_msgs::msg::GeoPoseStamped getGlobalWPMsg(double lat, double lon);
    geometry_msgs::msg::PoseStamped getRelativeWPMsg(double x, double y);
    //void sendLocalWP(double x, double y);
    geometry_msgs::msg::Point polarToCartesian(double radius, double angle);
}
#endif // TASKLIB_HPP