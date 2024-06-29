#include "perception/lib/bbox_calculations.hpp"

namespace bbox_calculations
{
    void getLargestRedAndGreenBoundingBox(std::vector<perception_interfaces::msg::BoundingBox>& bounding_boxes_, perception_interfaces::msg::BoundingBox& left_box, perception_interfaces::msg::BoundingBox& right_box){
        perception_interfaces::msg::BoundingBox temp_red;
        temp_red.xmin = 0.0;
        temp_red.xmax = 0.0;
        temp_red.ymin = 0.0;
        temp_red.ymax = 0.0;
        perception_interfaces::msg::BoundingBox temp_green;
        temp_green.xmin = 0.0;
        temp_green.xmax = 0.0;
        temp_green.ymin = 0.0;
        temp_green.ymax = 0.0;
        for (perception_interfaces::msg::BoundingBox box : bounding_boxes_)
        {
            replaceIfLarger("red_marker", temp_red, box);
            replaceIfLarger("green_marker", temp_green, box);
        }
        if (getBoxCenter(temp_red).x > getBoxCenter(temp_green).x)
        {
            left_box = temp_green;
            right_box = temp_red;
        }
        else 
        {
            left_box = temp_red;
            right_box = temp_green;
        }
        return;
    }

    void replaceIfLarger(std::string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing)
    {
        if ((box_to_be_replaced.class_id == label) && (box_to_do_the_replacing.class_id == label))
        {
            if (getBoxArea(box_to_do_the_replacing) > getBoxArea(box_to_be_replaced))
            {
                box_to_be_replaced = box_to_do_the_replacing;
            }
        }
    }
  
    double getBoxArea(perception_interfaces::msg::BoundingBox b_box)
    {
        double width = b_box.xmax - b_box.xmin; 
        double height = b_box.ymax - b_box.ymin;
        return width * height; 
    }

    geometry_msgs::msg::Point getBoxCenter(perception_interfaces::msg::BoundingBox b_box)
    {
        geometry_msgs::msg::Point center;
        center.x = (b_box.xmax - b_box.xmin)/2 + b_box.xmin; 
        center.y = (b_box.ymax - b_box.ymin)/2 + b_box.ymin; 

        return center; 
    }
    void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle, double camera_fov, double camera_x_res)
    {
        double fov_end = (M_PI / 2) + (camera_fov / 2 );
        smaller_angle = fov_end - ((bbox.xmax / camera_x_res) * camera_fov); 
        larger_angle = fov_end - ((bbox.xmin / camera_x_res) * camera_fov);
        return;
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