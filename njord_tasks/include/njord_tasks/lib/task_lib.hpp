#ifndef TASKLIB_HPP
#define TASKLIB_HPP

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "mavros_msgs/msg/state.hpp"

namespace task_lib
{
    rclcpp::Logger logger = rclcpp::get_logger("task_lib_logger");

    bool inGuided(const mavros_msgs::msg::State& state);
}
#endif // TASKLIB_HPP