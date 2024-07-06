#include "perception/lidar_camera_fuser_component.hpp"

#include "perception/lib/bbox_calculations.hpp"
#include "perception/lib/helpers.hpp"
namespace perception
{

  LidarCameraFuser::LidarCameraFuser(const rclcpp::NodeOptions & options)
  : Node("lidar_camera_fuser", options)
  {
    lidar_sub_ = this->create_subscription<perception_interfaces::msg::PropArray>("/perception/lidar_detected_props", 10, std::bind(&LidarCameraFuser::lidarBBoxCallback, this, _1));
    camera_sub_ = this->create_subscription<perception_interfaces::msg::BoundingBoxes>("/perception/mock_bboxes", 10, std::bind(&LidarCameraFuser::cameraBBoxCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::Gate>("perception/relative_gates", 10);

    LidarCameraFuser::getParam<double>("dist_between_markers", p_dist_between_markers_, 0.0, "Distance between markers in a gate");
    LidarCameraFuser::getParam<double>("dist_between_markers_err", p_dist_between_markers_err_, 0.0, "+/- for max and min distances between markers in a gate");
    LidarCameraFuser::getParam<double>("camera_res_x", p_camera_res_x_, 0.0, "Resolution width of camera");
    LidarCameraFuser::getParam<double>("camera_fov", p_dist_between_markers_err_, 0.0, "Camera field of view");
    LidarCameraFuser::getParam<double>("bbox_angle_err", p_bbox_angle_err_, 0.0, "+/- for angle of camera bounding boxes");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&LidarCameraFuser::param_callback, this, std::placeholders::_1));
  }
  rcl_interfaces::msg::SetParametersResult LidarCameraFuser::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "dist_between_markers") { p_dist_between_markers_ = params[0].as_double(); }
    else if (params[0].get_name() == "dist_between_markers_err") { p_dist_between_markers_err_ = params[0].as_double(); }
    else if (params[0].get_name() == "camera_res_x") { p_camera_res_x_ = params[0].as_double(); }
    else if (params[0].get_name() == "camera_fov") { p_camera_fov_ = params[0].as_double(); }
    else if (params[0].get_name() == "bbox_angle_err") { p_bbox_angle_err_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void LidarCameraFuser::lidarBBoxCallback(const perception_interfaces::msg::PropArray::SharedPtr msg)
  {
    if (msg->props.size() > 0)
    {
      if (haveDetectedGateWithCamera_)
      {
        perception_interfaces::msg::BoundingBox left_box;
        perception_interfaces::msg::BoundingBox right_box;
        bbox_calculations::getLargestRedAndGreenBoundingBox(bounding_boxes_, left_box, right_box);

        perception_interfaces::msg::Prop p1 = getClosestLidarPropWithinBBoxRange(left_box, msg->props);
        perception_interfaces::msg::Prop p2 = getClosestLidarPropWithinBBoxRange(right_box, msg->props);

        if (propsWithinBounds(p1, p2))
        {
          perception_interfaces::msg::Gate gate = helpers::createGate(p1, p2);
          pub_->publish(gate); 
        }
        haveDetectedGateWithCamera_ = false;
      }
      
    }
    else
    {
      RCLCPP_WARN(this->get_logger(), "No lidar detected props in message");
    }
  }
  
  void LidarCameraFuser::cameraBBoxCallback(const perception_interfaces::msg::BoundingBoxes::SharedPtr msg)
  {

    if (bbox_calculations::includesARedAndGreen(msg->bounding_boxes))
    {
      bounding_boxes_ = msg->bounding_boxes;
      haveDetectedGateWithCamera_ = true;
      RCLCPP_INFO(this->get_logger(), "Red and green markers detected");
    }
    else{
      RCLCPP_INFO(this->get_logger(), "Red AND green markers NOT detected");
    }
    return;
  }

  perception_interfaces::msg::Prop LidarCameraFuser::getClosestLidarPropWithinBBoxRange(perception_interfaces::msg::BoundingBox b_box, std::vector<perception_interfaces::msg::Prop> lidar_props)
  {
    double smaller_angle, larger_angle;
    bbox_calculations::getCamBBoxAngle(b_box, smaller_angle, larger_angle, p_camera_fov_, p_camera_res_x_);

    std::vector<perception_interfaces::msg::Prop> props_in_range;

    for (perception_interfaces::msg::Prop prop : lidar_props)
    {
      if (!propFallsWithinAngles(prop, smaller_angle, larger_angle))
      {
        props_in_range.push_back(prop);
      }
    }

    perception_interfaces::msg::Prop closest_prop_in_range = getClosestProp(props_in_range);

    return closest_prop_in_range;
  }

  bool LidarCameraFuser::propFallsWithinAngles(perception_interfaces::msg::Prop prop, double smaller_angle, double larger_angle)
  {
    double prop_angle = std::atan2(prop.point.y, prop.point.x);

    if ((smaller_angle - p_bbox_angle_err_ <= prop_angle) && (prop_angle <= larger_angle + p_bbox_angle_err_))
    {
      return true;
    }

    return false;
  }

  perception_interfaces::msg::Prop LidarCameraFuser::getClosestProp(std::vector<perception_interfaces::msg::Prop> props)
  {
    perception_interfaces::msg::Prop closest_prop;
    double dist = 1000; // a large number that should be bigger than the distance of all props
    for (perception_interfaces::msg::Prop prop : props)
    {
      double temp_dist = std::hypot(prop.point.x, prop.point.y);
      if (temp_dist < dist)
      {
        dist = temp_dist;
        closest_prop = prop;
      }
    }

    return closest_prop;
  }

  bool LidarCameraFuser::propsWithinBounds(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2)
  {
    double dist = helpers::distTwoPoints(p1.point.x,p1.point.y,p2.point.x,p2.point.y);
    double max_dist = p_dist_between_markers_ +  p_dist_between_markers_err_;
    double min_dist = p_dist_between_markers_ -  p_dist_between_markers_err_;
    if ((dist < max_dist) && (dist > min_dist))
    {
      RCLCPP_INFO(this->get_logger(), "Props detected within bounds");
      return true;
    }
    RCLCPP_INFO(this->get_logger(), "Props detected but NOT within bounds");
    return false;
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarCameraFuser)