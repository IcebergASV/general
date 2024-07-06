#include "perception/lib/bbox_calculations.hpp"

namespace bbox_calculations
{
    void getLargestRedAndGreenBoundingBox(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes, perception_interfaces::msg::BoundingBox& red_box, perception_interfaces::msg::BoundingBox& green_box){
        perception_interfaces::msg::BoundingBox temp_red;
        temp_red.xmin = 0.0;
        temp_red.xmax = 0.0;
        temp_red.ymin = 0.0;
        temp_red.ymax = 0.0;
        temp_red.class_id = "red_marker";
        perception_interfaces::msg::BoundingBox temp_green;
        temp_green.xmin = 0.0;
        temp_green.xmax = 0.0;
        temp_green.ymin = 0.0;
        temp_green.ymax = 0.0;
        temp_green.class_id = "green_marker";

        for (perception_interfaces::msg::BoundingBox box : bboxes)
        {
            replaceIfLarger("red_marker", temp_red, box);
            replaceIfLarger("green_marker", temp_green, box);
        }
        RCLCPP_DEBUG(logger, "Largest red box x's (%d, %d), largest green box x's (%d, %d)", temp_red.xmin, temp_red.xmax, temp_green.xmin, temp_green.xmax);
        red_box = temp_red;
        green_box = temp_green;
        return;
    }

    void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing)
    {
        RCLCPP_DEBUG(logger, "Checking box with coords (%d, %d, %d, %d)", box_to_do_the_replacing.xmin, box_to_do_the_replacing.xmax, box_to_do_the_replacing.ymin, box_to_do_the_replacing.ymax);
        if ((box_to_be_replaced.class_id == label) && (box_to_do_the_replacing.class_id == label))
        {
            RCLCPP_DEBUG(logger, "Labels match");
            RCLCPP_DEBUG(logger, "Area of existing box %f, area of potentially bigger box: %f", getBoxArea(box_to_be_replaced), getBoxArea(box_to_do_the_replacing));
            if (getBoxArea(box_to_do_the_replacing) > getBoxArea(box_to_be_replaced))
            {

                box_to_be_replaced = box_to_do_the_replacing;
            }
        }
        else {
            RCLCPP_DEBUG(logger, "Labels %s and %s do not match target label %s", box_to_be_replaced.class_id.c_str(), box_to_do_the_replacing.class_id.c_str(), label.c_str());
        }
    }
  
    double getBoxArea(perception_interfaces::msg::BoundingBox bbox)
    {
        double width = bbox.xmax - bbox.xmin; 
        double height = bbox.ymax - bbox.ymin;
        return width * height; 
    }

    geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox bbox)
    {
        geometry_msgs::msg::Point center;
        center.x = (bbox.xmax - bbox.xmin)/2 + bbox.xmin; 
        center.y = (bbox.ymax - bbox.ymin)/2 + bbox.ymin; 

        return center; 
    }

    void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle, double camera_fov, double camera_x_res)
    {
        smaller_angle = pixelToAngle(camera_fov, camera_x_res, bbox.xmax);
        larger_angle = pixelToAngle(camera_fov, camera_x_res, bbox.xmin);
        return;
    }

    double pixelToAngle(double fov_in_degrees, int res, int pixel)
    {
        double angle_per_pixel = (fov_in_degrees*M_PI/180) / res;
        double fov_center = M_PI / 2;
        double dist_from_center = (res/2) - pixel;
        double angle = fov_center + (angle_per_pixel * dist_from_center);

        return angle;
    }

    bool includesARedAndGreen(const std::vector<perception_interfaces::msg::BoundingBox>& bboxes)
    {
        bool includes_red = false;
        bool includes_green = false;

        for (perception_interfaces::msg::BoundingBox bbox : bboxes)
        {
            if (bbox.class_id == "red_marker")
            {
                includes_red = true;
            }
            if (bbox.class_id == "green_marker")
            {
                includes_green = true;
            }            
        }

        return includes_red && includes_green;
    }
}