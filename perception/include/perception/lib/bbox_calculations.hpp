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

    void getLargestRedAndGreenBoundingBox(std::vector<perception_interfaces::msg::BoundingBox>& bounding_boxes_, perception_interfaces::msg::BoundingBox& left_box, perception_interfaces::msg::BoundingBox& right_box);
    void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing);
    double getBoxArea(perception_interfaces::msg::BoundingBox b_box);
    geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox b_box);
    void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle);
    bool includesARedAndGreen(std::vector<perception_interfaces::msg::BoundingBox> bboxes);
}
#endif // BBOXCALCULATIONS_H