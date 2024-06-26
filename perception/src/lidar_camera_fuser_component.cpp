#include "perception/lidar_camera_fuser_component.h"

namespace perception
{

  LidarCameraFuser::LidarCameraFuser(const rclcpp::NodeOptions & options)
  : Node("lidar_camera_fuser", options)
  {
    lidar_sub_ = this->create_subscription<perception_interfaces::msg::LidarDetectedPropArray>("/perception/lidar_detected_props", 10, std::bind(&LidarCameraFuser::lidarBBoxCallback, this, _1));
    camera_sub_ = this->create_subscription<perception_interfaces::msg::BoundingBoxes>("/perception/fake_cam_bboxes", 10, std::bind(&LidarCameraFuser::cameraBBoxCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::Gate>("perception/relative_gates", 10);

    LidarCameraFuser::getParam<double>("dist_between_markers", p_dist_between_markers_, 0.0, "Distance between markers in a gate");
    LidarCameraFuser::getParam<double>("dist_between_markers_err", p_dist_between_markers_err_, 0.0, "+/- for max and min distances between markers in a gate");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&LidarCameraFuser::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult LidarCameraFuser::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "dist_between_markers") { p_dist_between_markers_ = params[0].as_double(); }
    else if (params[0].get_name() == "dist_between_markers_err") { p_dist_between_markers_err_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void LidarCameraFuser::lidarBBoxCallback(const perception_interfaces::msg::LidarDetectedPropArray::SharedPtr msg)
  {
    //if (msg->segments.size() > 0)
    //{
    //  perception_interfaces::msg::LidarDetectedPropArray lidar_detected_prop_array;
    //  for (slg_msgs::msg::Segment segment : msg->segments)
    //  {
    //    std::vector<geometry_msgs::msg::Point> filtered_points;// = lidar_calculations::getPointsWithinBounds(segment.points, p_min_lidar_dist_, p_max_lidar_dist_, p_lidar_fov_);
//
    //    if (true)
    //    {
    //      attemptToCreateAndAddLidarDetectedProp(filtered_points, lidar_detected_prop_array);
    //    }
    //  }
    //  if (lidar_detected_prop_array.lidar_detected_props.size() > 0)
    //  {
    //    pub_->publish(lidar_detected_prop_array);
    //  }
    //}
    //else
    //{
    //  RCLCPP_WARN(this->get_logger(), "No segments in message");
    //}
  }
  
  void LidarCameraFuser::cameraBBoxCallback(const perception_interfaces::msg::BoundingBoxes::SharedPtr msg)
  {
    return;
  }


}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarCameraFuser)