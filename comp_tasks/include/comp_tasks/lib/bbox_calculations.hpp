#ifndef BBOXCALCULATION_H
#define BBOXCALCULATIONS_H

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "yolov8_msgs/msg/detection_array.hpp"
//#include "perception_interfaces/msg/bounding_box.hpp"

namespace bbox_calculations
{
    rclcpp::Logger logger = rclcpp::get_logger("bbox_calculations_logger");

    //void getLargestRedAndGreenBoundingBox(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes, perception_interfaces::msg::BoundingBox& red_box, perception_interfaces::msg::BoundingBox& green_box);
    //void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing);
    //double getBoxArea(perception_interfaces::msg::BoundingBox bbox);
    //geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox bbox);
    //void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle, double camera_fov, double camera_x_res);
    //bool includesARedAndGreen(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes);
    double pixelToAngle(double fov_in_degrees, int res, int pixel);
    double getAngleBetween2DiffTargets(const yolov8_msgs::msg::DetectionArray bboxes, std::string bbox_selection, std::string left_target_class_name1, std::string left_target_class_name2, std::string right_target_class_name1, std::string right_target_class_name2, double cam_fov, double cam_res_x, double angle_from_target);
    bool hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::vector<std::reference_wrapper<std::string>>& desired_class_names);
    std::vector<yolov8_msgs::msg::Detection> extractTargetDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::string& class_name1, const std::string& class_name2);
    std::vector<yolov8_msgs::msg::Detection> filterAndSort(const yolov8_msgs::msg::DetectionArray detection_array, std::string bbox_selection, std::string& class_name1, const std::string& class_name2);
    std::vector<yolov8_msgs::msg::Detection> getLargest(const yolov8_msgs::msg::DetectionArray detection_array);
    std::vector<yolov8_msgs::msg::Detection> sortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array);

}
#endif // BBOXCALCULATIONS_H