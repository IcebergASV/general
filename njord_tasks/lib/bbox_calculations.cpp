#include "njord_tasks/lib/bbox_calculations.hpp"

namespace bbox_calculations
{
    // void getLargestRedAndGreenBoundingBox(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes, perception_interfaces::msg::BoundingBox& red_box, perception_interfaces::msg::BoundingBox& green_box){
    //     perception_interfaces::msg::BoundingBox temp_red;
    //     temp_red.xmin = 0.0;
    //     temp_red.xmax = 0.0;
    //     temp_red.ymin = 0.0;
    //     temp_red.ymax = 0.0;
    //     temp_red.class_id = "red_marker";
    //     perception_interfaces::msg::BoundingBox temp_green;
    //     temp_green.xmin = 0.0;
    //     temp_green.xmax = 0.0;
    //     temp_green.ymin = 0.0;
    //     temp_green.ymax = 0.0;
    //     temp_green.class_id = "green_marker";

    //     for (perception_interfaces::msg::BoundingBox box : bboxes)
    //     {
    //         replaceIfLarger("red_marker", temp_red, box);
    //         replaceIfLarger("green_marker", temp_green, box);
    //     }
    //     RCLCPP_DEBUG(logger, "Largest red box x's (%d, %d), largest green box x's (%d, %d)", temp_red.xmin, temp_red.xmax, temp_green.xmin, temp_green.xmax);
    //     red_box = temp_red;
    //     green_box = temp_green;
    //     return;
    // }

    // void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing)
    // {
    //     RCLCPP_DEBUG(logger, "Checking box with coords (%d, %d, %d, %d)", box_to_do_the_replacing.xmin, box_to_do_the_replacing.xmax, box_to_do_the_replacing.ymin, box_to_do_the_replacing.ymax);
    //     if ((box_to_be_replaced.class_id == label) && (box_to_do_the_replacing.class_id == label))
    //     {
    //         RCLCPP_DEBUG(logger, "Labels match");
    //         RCLCPP_DEBUG(logger, "Area of existing box %f, area of potentially bigger box: %f", getBoxArea(box_to_be_replaced), getBoxArea(box_to_do_the_replacing));
    //         if (getBoxArea(box_to_do_the_replacing) > getBoxArea(box_to_be_replaced))
    //         {

    //             box_to_be_replaced = box_to_do_the_replacing;
    //         }
    //     }
    //     else {
    //         RCLCPP_DEBUG(logger, "Labels %s and %s do not match target label %s", box_to_be_replaced.class_id.c_str(), box_to_do_the_replacing.class_id.c_str(), label.c_str());
    //     }
    // }
  
    // double getBoxArea(perception_interfaces::msg::BoundingBox bbox)
    // {
    //     double width = bbox.xmax - bbox.xmin; 
    //     double height = bbox.ymax - bbox.ymin;
    //     return width * height; 
    // }

    // geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox bbox)
    // {
    //     geometry_msgs::msg::Point center;
    //     center.x = (bbox.xmax - bbox.xmin)/2 + bbox.xmin; 
    //     center.y = (bbox.ymax - bbox.ymin)/2 + bbox.ymin; 

    //     return center; 
    // }

    // void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle, double camera_fov, double camera_x_res)
    // {
    //     smaller_angle = pixelToAngle(camera_fov, camera_x_res, bbox.xmax);
    //     larger_angle = pixelToAngle(camera_fov, camera_x_res, bbox.xmin);
    //     return;
    // }

    double pixelToAngle(double fov_in_degrees, int res, int pixel)
    {
        double angle_per_pixel = (fov_in_degrees*M_PI/180) / res;
        double fov_center = M_PI / 2;
        double dist_from_center = (res/2) - pixel;
        double angle = fov_center + (angle_per_pixel * dist_from_center);

        return angle;
    }

    // bool includesARedAndGreen(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes)
    // {
    //     bool includes_red = false;
    //     bool includes_green = false;

    //     for (perception_interfaces::msg::BoundingBox bbox : bboxes)
    //     {
    //         if (bbox.class_id == "red_marker")
    //         {
    //             includes_red = true;
    //         }
    //         if (bbox.class_id == "green_marker")
    //         {
    //             includes_green = true;
    //         }            
    //     }

    //     return includes_red && includes_green;
    // }
  double getAngleBetween2DiffTargets(const yolov8_msgs::msg::DetectionArray bboxes, std::string bbox_selection, std::string left_target_class_name1, std::string left_target_class_name2, std::string right_target_class_name1, std::string right_target_class_name2, double cam_fov, double cam_res_x, double angle_from_target)
  {

    std::vector<yolov8_msgs::msg::Detection> left_targets = filterAndSort(bboxes, bbox_selection, left_target_class_name1, left_target_class_name2);
    std::vector<yolov8_msgs::msg::Detection> right_targets = filterAndSort(bboxes, bbox_selection, right_target_class_name1, right_target_class_name2);

    if (left_targets.size() == 0 && right_targets.size() == 0)
    {
      RCLCPP_ERROR(logger, "No targets detected - wp will be empty"); //TODO THROW AN ERROR - should never get here
    }

    double angle;
    if ((left_targets.size() == 0) & (right_targets.size() > 0)) // move to left of left most green
    {
      RCLCPP_INFO(logger, "Detected only %s(s)", right_target_class_name1.c_str());
      angle = bbox_calculations::pixelToAngle(cam_fov, cam_res_x, right_targets[0].bbox.center.position.x);
      RCLCPP_INFO(logger, "Left most %s detected at %f degrees", right_target_class_name1.c_str(), angle*180/M_PI);
      angle = angle - angle_from_target*M_PI/180;
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
    RCLCPP_INFO(logger, "Largest %s buoy area: %f", largest_bbox[0].class_name.c_str(), largest_area);
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
}
