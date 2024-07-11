#ifndef BBOXCALCULATION_H
#define BBOXCALCULATIONS_H

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/bounding_box.hpp"

namespace bbox_calculations
{
    rclcpp::Logger logger = rclcpp::get_logger("bbox_calculations_logger");

    void getLargestRedAndGreenBoundingBox(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes, perception_interfaces::msg::BoundingBox& red_box, perception_interfaces::msg::BoundingBox& green_box);
    void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing);
    double getBoxArea(perception_interfaces::msg::BoundingBox bbox);
    geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox bbox);
    void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle, double camera_fov, double camera_x_res);
    bool includesARedAndGreen(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes);
    double pixelToAngle(double fov_in_degrees, int res, int pixel);
}
#endif // BBOXCALCULATIONS_H