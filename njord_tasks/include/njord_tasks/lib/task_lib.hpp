#ifndef TASKLIB_HPP
#define TASKLIB_HPP

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"

namespace task_lib
{
    rclcpp::Logger logger = rclcpp::get_logger("task_lib_logger");

    bool inGuided(const mavros_msgs::msg::State& state);
    bool isReached(double lat, double lon, const sensor_msgs::msg::NavSatFix& global_pose);
}
#endif // TASKLIB_HPP