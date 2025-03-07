#ifndef BBOXCALCULATION_H
#define BBOXCALCULATIONS_H

#include <vector>
#include <string>
#include <cmath>
#include <rclcpp/logging.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"
#include "yolov8_msgs/msg/bounding_box2_d.hpp"

using yolov8_msgs::msg::DetectionArray;
using yolov8_msgs::msg::Detection;
using yolov8_msgs::msg::BoundingBox2D;
namespace bbox_calculations
{
    rclcpp::Logger logger = rclcpp::get_logger("bbox_calculations_logger");

    double pixelToAngle(double fov_in_degrees, int res, int pixel);
    double getAngleBetween2DiffTargets(const yolov8_msgs::msg::DetectionArray bboxes, std::string bbox_selection, std::string left_target_class_name1, std::string left_target_class_name2, std::string right_target_class_name1, std::string right_target_class_name2, double cam_fov, double cam_res_x, double angle_from_target);
    double getAngleToLargestTarget(const yolov8_msgs::msg::DetectionArray bboxes, std::string target_label, double cam_fov, double cam_res_x);
    bool hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::vector<std::reference_wrapper<std::string>>& desired_class_names);
    bool hasGate(const yolov8_msgs::msg::DetectionArray& detection_array, std::string left_marker_name1, std::string left_marker_name2, std::string right_marker_name1, std::string right_marker_name2);
    std::vector<yolov8_msgs::msg::Detection> extractTargetDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::string& class_name1, const std::string& class_name2);
    std::vector<yolov8_msgs::msg::Detection> filterAndSort(const yolov8_msgs::msg::DetectionArray detection_array, std::string bbox_selection, std::string& class_name1, const std::string& class_name2);
    std::vector<yolov8_msgs::msg::Detection> getLargest(const yolov8_msgs::msg::DetectionArray detection_array);
    std::vector<yolov8_msgs::msg::Detection> sortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array);
    bool isLeft(const yolov8_msgs::msg::DetectionArray bboxes, std::string target_label, double cam_fov, double cam_res_x);
    BoundingBox2D mergeBoundingBoxes(const BoundingBox2D& a, const BoundingBox2D& b);
    DetectionArray mergeOverlappingDetections(const DetectionArray& bboxes);
    double getAverageXCenter(const yolov8_msgs::msg::DetectionArray& bboxes);
    double getAngleBetween2SameTargets(const yolov8_msgs::msg::DetectionArray& bboxes, std::string target_class_name, double cam_fov, double cam_res_x);
}
#endif // BBOXCALCULATIONS_H