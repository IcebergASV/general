#include "comp_tasks/lib/bbox_calculations.hpp"

namespace bbox_calculations
{
  double pixelToAngle(double fov_in_degrees, int res, int pixel)
  {
      double angle_per_pixel = (fov_in_degrees*M_PI/180) / res;
      double fov_center = M_PI / 2;
      double dist_from_center = (res/2) - pixel;
      double angle = fov_center + (angle_per_pixel * dist_from_center);

      return angle;
  }

  double getAngleBetween2DiffTargets(const yolov8_msgs::msg::DetectionArray bboxes, std::string bbox_selection, std::string left_target_class_name1, std::string left_target_class_name2, std::string right_target_class_name1, std::string right_target_class_name2, double cam_fov, double cam_res_x, double angle_from_target)
  {

    std::vector<yolov8_msgs::msg::Detection> left_targets = filterAndSort(bboxes, bbox_selection, left_target_class_name1, left_target_class_name2);
    std::vector<yolov8_msgs::msg::Detection> right_targets = filterAndSort(bboxes, bbox_selection, right_target_class_name1, right_target_class_name2);

    if (left_targets.size() == 0 && right_targets.size() == 0)
    {
      RCLCPP_ERROR(logger, "2Diff Targets: No targets detected - wp will be empty"); //TODO THROW AN ERROR - should never get here
    }

    double angle;
    if ((left_targets.size() == 0) & (right_targets.size() > 0)) // move to left of left most green
    {
      RCLCPP_INFO(logger, "Detected only %s(s)", right_target_class_name1.c_str());
      angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, right_targets[0].bbox.center.position.x);
      RCLCPP_INFO(logger, "Left most %s detected at %f degrees", right_target_class_name1.c_str(), angle*180/M_PI);
      angle = angle + angle_from_target*M_PI/180;
      RCLCPP_INFO(logger, "Heading towards %f degrees", angle*180/M_PI);
    }
    else if ((right_targets.size() == 0) && (left_targets.size() > 0)) // move to the right of rightmost red
    {
      RCLCPP_INFO(logger, "Detected only %s(s)", left_target_class_name1.c_str());
      angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, left_targets[left_targets.size()-1].bbox.center.position.x);
      RCLCPP_INFO(logger, "Right most %s detected at %f degrees", left_target_class_name1.c_str(), angle*180/M_PI);
      angle = angle - angle_from_target*M_PI/180;
      RCLCPP_INFO(logger, "Heading towards %f degrees", angle*180/M_PI);
    }
    else if ((right_targets.size() > 0) && (left_targets.size() > 0))// move in between innermost red and green
    {
      
      double left_angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, left_targets[left_targets.size()-1].bbox.center.position.x);
      double right_angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, right_targets[0].bbox.center.position.x);
      if ((left_angle - right_angle) < 0)
      {
        RCLCPP_WARN(logger, "Expected %s on the left and %s on the right but detected the opposite, heading between them anyways",left_target_class_name1.c_str(), right_target_class_name1.c_str() ); // TODO get it to go to recovery if this happens or turn around
      }
      angle = (left_angle + right_angle)/2;
      RCLCPP_INFO(logger, "Detected %s at %f degrees and %s at %f degrees, heading towards %f degrees", left_target_class_name1.c_str(), left_angle*180/M_PI, right_target_class_name1.c_str(), right_angle*180/M_PI, angle*180/M_PI);
    }
    else 
    {
      RCLCPP_WARN(logger, "ERROR COUNTING BUOYS");
    }
    angle = angle - M_PI/2;
    return angle;
  }

  // Helper function to check if two bounding boxes overlap
  bool isOverlapping(const BoundingBox2D& a, const BoundingBox2D& b) {
      return (a.center.position.x - a.size.x / 2 < b.center.position.x + b.size.x / 2 &&
              a.center.position.x + a.size.x / 2 > b.center.position.x - b.size.x / 2 &&
              a.center.position.y - a.size.y / 2 < b.center.position.y + b.size.y / 2 &&
              a.center.position.y + a.size.y / 2 > b.center.position.y - b.size.y / 2);
  }

  // Function to merge two bounding boxes
  BoundingBox2D mergeBoundingBoxes(const BoundingBox2D& a, const BoundingBox2D& b) {
      double min_x = std::min(a.center.position.x - a.size.x / 2, b.center.position.x - b.size.x / 2);
      double max_x = std::max(a.center.position.x + a.size.x / 2, b.center.position.x + b.size.x / 2);
      double min_y = std::min(a.center.position.y - a.size.y / 2, b.center.position.y - b.size.y / 2);
      double max_y = std::max(a.center.position.y + a.size.y / 2, b.center.position.y + b.size.y / 2);
      
      BoundingBox2D merged;
      merged.center.position.x = (min_x + max_x) / 2;
      merged.center.position.y = (min_y + max_y) / 2;
      merged.size.x = max_x - min_x;
      merged.size.y = max_y - min_y;
      return merged;
  }

  std::vector<yolov8_msgs::msg::Detection> mergeOverlappingDetections(const std::vector<yolov8_msgs::msg::Detection>& bboxes) {
    std::vector<yolov8_msgs::msg::Detection> merged_bboxes;
    std::vector<bool> merged_flags(bboxes.size(), false);

    for (size_t i = 0; i < bboxes.size(); ++i) {
        if (merged_flags[i]) continue;
        yolov8_msgs::msg::Detection merged_detection = bboxes[i];
        bool has_overlap = false;

        for (size_t j = i + 1; j < bboxes.size(); ++j) {
            if (merged_flags[j]) continue;
            
            if (isOverlapping(merged_detection.bbox, bboxes[j].bbox)) {
                merged_detection.bbox = mergeBoundingBoxes(merged_detection.bbox, bboxes[j].bbox);
                merged_flags[j] = true; // Mark as merged
                has_overlap = true;
            }
        }
        
        merged_bboxes.push_back(merged_detection);
        merged_flags[i] = has_overlap; // Mark current box as merged only if it was combined
    }

    // Add remaining unmerged boxes
    for (size_t i = 0; i < bboxes.size(); ++i) {
        if (!merged_flags[i]) {
            merged_bboxes.push_back(bboxes[i]);
        }
    }
    
    return merged_bboxes;
  }

  double getAverageXCenter(const std::vector<yolov8_msgs::msg::Detection>& bboxes) {
    if (bboxes.empty()) {
        return 0.0;  // Return 0 if there are no detections
    }

    double sum_x_center = 0.0;
    for (const auto& box : bboxes) {
        double x_center = box.bbox.center.position.x;
        sum_x_center += x_center;
    }

    return sum_x_center / bboxes.size();
  }

  double getAngleBetween2SameTargets(const yolov8_msgs::msg::DetectionArray& bboxes, std::string target_class_name, double cam_fov, double cam_res_x)
  {
    std::vector<yolov8_msgs::msg::Detection> filtered_detections = extractTargetDetections(bboxes, target_class_name, target_class_name);
    RCLCPP_WARN(logger, "Black Detections: %ld", filtered_detections.size());

    std::vector<yolov8_msgs::msg::Detection> merged_bboxes = mergeOverlappingDetections(filtered_detections);
    RCLCPP_WARN(logger, "Merged Black Detections: %ld", merged_bboxes.size());

    if (merged_bboxes.size() == 0)
    {
      RCLCPP_ERROR(logger, "2SameTargets: No targets detected - wp will be empty"); //TODO THROW AN ERROR - should never get here
    }

    int average_pixel = getAverageXCenter(merged_bboxes);
    double angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, average_pixel);
    angle = angle - M_PI/2;
    return angle;
  }

  double getAngleToLargestTarget(const yolov8_msgs::msg::DetectionArray bboxes, std::string target_label, double cam_fov, double cam_res_x)
  {
    std::vector<yolov8_msgs::msg::Detection> targets = filterAndSort(bboxes, "LARGEST", target_label, target_label);
    if (targets.size() <= 0)
    {
      RCLCPP_ERROR(logger, "AngletoLargest: No targets detected - wp will be empty"); //TODO THROW AN ERROR - should never get here
    }
    double angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, targets[0].bbox.center.position.x);
    angle = angle - M_PI/2; // TODO Test
    return angle;
  }

  std::vector<yolov8_msgs::msg::Detection> extractTargetDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::string& class_name1, const std::string& class_name2)
  {
    std::vector<yolov8_msgs::msg::Detection> filtered_detections;

    for (const auto& detection : detection_array.detections) {
        RCLCPP_DEBUG(logger, "%s", detection.class_name.c_str());
        if (detection.class_name == class_name1 || detection.class_name == class_name2) {
            filtered_detections.push_back(detection);
        }
    }

    return filtered_detections;
  }

  std::vector<yolov8_msgs::msg::Detection> sortLeftToRight(std::vector<yolov8_msgs::msg::Detection> detection_array)
  {
    std::sort(detection_array.begin(), detection_array.end(),
        [](const yolov8_msgs::msg::Detection& a, const yolov8_msgs::msg::Detection& b) {
            double center_a_x = a.bbox.center.position.x;
            double center_b_x = b.bbox.center.position.x;
            return center_a_x < center_b_x;
        });

    return detection_array;
  }

  std::vector<yolov8_msgs::msg::Detection> getLargest(const std::vector<yolov8_msgs::msg::Detection>& detection_array)
  {
    double largest_bbox_area = 0.0;
    std::vector<yolov8_msgs::msg::Detection> largest_bbox; // This should never contain more than one bounding box!

    for (auto detection : detection_array)
    {
      double area = detection.bbox.size.x * detection.bbox.size.y;
      if (area > largest_bbox_area)
      {
        largest_bbox_area = area;
        largest_bbox.clear();
        largest_bbox.push_back(detection);
      }
    }
    
    double largest_area = largest_bbox[0].bbox.size.x * largest_bbox[0].bbox.size.y;
    RCLCPP_DEBUG(logger, "Largest %s buoy area: %f", largest_bbox[0].class_name.c_str(), largest_area);
    return largest_bbox;
  }

  std::vector<yolov8_msgs::msg::Detection> filterAndSort(const yolov8_msgs::msg::DetectionArray detection_array, std::string bbox_selection, std::string& class_name1, const std::string& class_name2)
  {
    std::vector<yolov8_msgs::msg::Detection> filtered_detections = extractTargetDetections(detection_array, class_name1, class_name2);

    if (filtered_detections.size() == 0)
    {
      return filtered_detections;
    }
    
    if (bbox_selection == "LARGEST")
    {
      filtered_detections = getLargest(filtered_detections);
    }
    else if (bbox_selection == "INNERMOST")
    {
      filtered_detections = sortLeftToRight(filtered_detections);
    }
    else
    {
      RCLCPP_ERROR(logger, "Invalid bounding box selection method: %s", bbox_selection.c_str());
    }

    return filtered_detections;
  }

bool hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array, const std::vector<std::reference_wrapper<std::string>>& desired_class_names)
{
    for (const auto& detection : detection_array.detections) {
        if (std::find_if(
                desired_class_names.begin(), desired_class_names.end(),
                [&detection](const std::reference_wrapper<std::string>& class_name_ref) {
                    return detection.class_name == class_name_ref.get();
                }
            ) != desired_class_names.end()) {
            return true;
        }
    }
    return false;
}

bool hasGate(const yolov8_msgs::msg::DetectionArray& detection_array, std::string left_marker_name1, std::string left_marker_name2, std::string right_marker_name1, std::string right_marker_name2)
{
  std::vector<yolov8_msgs::msg::Detection> left_targets = filterAndSort(detection_array, "LARGEST", left_marker_name1, left_marker_name2);
  std::vector<yolov8_msgs::msg::Detection> right_targets = filterAndSort(detection_array, "LARGEST", right_marker_name1, right_marker_name2);

  if (left_targets.size() == 0 && right_targets.size() == 0)
  {
    RCLCPP_ERROR(logger, "hasGate: No targets detected - wp will be empty"); //TODO THROW AN ERROR - should never get here
  }

  if ((right_targets.size() > 0) && (left_targets.size() > 0))// move in between innermost red and green
  {
    if ((right_targets[0].bbox.center.position.x - left_targets[left_targets.size()-1].bbox.center.position.x) < 0) // TODO test
    {
      RCLCPP_WARN(logger, "Expected %s on the left and %s on the right but detected the opposite",left_marker_name1.c_str(), right_marker_name1.c_str() ); // TODO get it to go to recovery if this happens or turn around
    }
    else 
    {
      // found gate
      RCLCPP_INFO(logger, "Detected a gate");
      return true;
    }
    

  }
  RCLCPP_INFO(logger, "No gate detected, left targets : %ld, right targets : %ld", left_targets.size(), right_targets.size());
  return false;
}

bool isLeft(const yolov8_msgs::msg::DetectionArray bboxes, std::string target_label, double cam_fov, double cam_res_x)
{
  double angle = getAngleToLargestTarget(bboxes, target_label, cam_fov, cam_res_x);
  
  if (angle > 0) // TODO test checking condition
  {
    return true;
  }
  else{
    return false;
  }

}

}

