#include "perception/lidar_camera_fuser_component.hpp"

#include "perception/lib/bbox_calculations.hpp"
#include "perception/lib/helpers.hpp"
namespace perception
{

  LidarCameraFuser::LidarCameraFuser(const rclcpp::NodeOptions & options)
  : Node("lidar_camera_fuser", options)
  {
    lidar_sub_ = this->create_subscription<perception_interfaces::msg::PropArray>("/perception/lidar_detected_props", 10, std::bind(&LidarCameraFuser::lidarBBoxCallback, this, _1));
    camera_sub_ = this->create_subscription<perception_interfaces::msg::BoundingBoxes>("/perception/fake_cam_bboxes", 10, std::bind(&LidarCameraFuser::cameraBBoxCallback, this, _1));
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
    if (msg->lidar_detected_props.size() > 0)
    {
      if (haveDetectedGateWithCamera_)
      {
        perception_interfaces::msg::BoundingBox left_box;
        perception_interfaces::msg::BoundingBox right_box;
        bbox_calculations::getLargestRedAndGreenBoundingBox(bounding_boxes, left_box, right_box);

        p1 = getClosestLidarPropWithinRange(left_box, msg->lidar_detected_props);
        p2 = getClosestLidarPropWithinRange(right_box, msg->lidar_detected_props);

        if (propsWithinBounds(p1, p2))
        {
          perception_interfaces::msg::Gate gate = helpers::createGate(p1, p2)
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

    if (bbox_calculations::includesARedAndGreen(msg))
    {
      bounding_boxes_ = msg->bounding_boxes;
      haveDetectedGateWithCamera_ = true;
    }
    return;
  }

  //void LidarCameraFuser::getLargestRedAndGreenBoundingBox(vector<perception_interfaces::msg::BoundingBox>& bounding_boxes_, perception_interfaces::msg::BoundingBox& left_box, perception_interfaces::msg::BoundingBox& right_box){
  //  perception_interfaces::msg::BoundingBox temp_red;
  //  temp_red.xmin = 0.0;
  //  temp_red.xmax = 0.0;
  //  temp_red.ymin = 0.0;
  //  temp_red.ymax = 0.0;
  //  perception_interfaces::msg::BoundingBox temp_green;
  //  temp_green.xmin = 0.0;
  //  temp_green.xmax = 0.0;
  //  temp_green.ymin = 0.0;
  //  temp_green.ymax = 0.0;
//
  //  for (perception_interfaces::msg::BoundingBox box : bounding_boxes_)
  //  {
  //    replaceIfLarger("red_marker", temp_red, box);
  //    replaceIfLarger("green_marker", temp_green, box);
  //  }
//
  //  if (getBoxCenter(temp_red) > getBoxCenter(temp_green))
  //  {
  //    left_box = temp_green;
  //    right_box = temp_red;
  //  }
  //  else 
  //  {
  //    left_box = temp_red;
  //    right_box = temp_green;
  //  }
//
  //  return;
  //}

  //void replaceIfLarger(string label, perception_interfaces::msg::BoundingBox& box_to_be_replaced, perception_interfaces::msg::BoundingBox box_to_do_the_replacing)
  //{
  //    if (box.class_id == label)
  //    {
  //      if (getBoxArea(box_to_do_the_replacing) > getBoxArea(box_to_be_replaced))
  //      {
  //        box_to_be_replaced = box_to_do_the_replacing;
  //      }
  //    }
  //}
//
  //double LidarCameraFuser::getBoxArea(perception_interfaces::msg::BoundingBox b_box)
  //{
  //  double width = b_box.x_max - b_box.x_min; 
  //  double height = b_box.y_max - b_box.y_min;
  //  return width * height; 
  //}
//
  //geometry_msgs::msg::Point LidarCameraFuser::getBoxCenter(perception_interfaces::msg::BoundingBox b_box)
  //{
  //  geometry_msgs::msg::Point center;
  //  center.x = (b_box.x_max - b_box.x_min)/2 + x_min; 
  //  center.y = (b_box.y_max - b_box.y_min)/2 + y_min; 
//
  //  return center; 
  //}
//
  //void getCamBBoxAngle(perception_interfaces::msg::BoundingBox bbox, double& smaller_angle, double& larger_angle)
  //{
  //  fov_end = (M_PI / 2) + (p_camera_fov_ / 2 );
  //  double smaller_angle = fov_end - ((bbox.x_max / p_camera_res_x_) * p_camera_fov_); 
  //  double larger_angle = fov_end - ((bbox.x_min / p_camera_res_x_) * p_camera_fov_);
  //  return;
  //}

  perception_interfaces::msg::Prop LidarCameraFuser::getClosestLidarPropWithinBBoxRange(perception_interfaces::msg::BoundingBox b_box, vector<perception_interfaces::msg::Prop> lidar_props)
  {
    double smaller_angle, larger_angle;
    bbox_calculations::getCamBBoxAngle(b_box, smaller_angle, larger_angle, p_camera_fov_, p_camera_res_x_);

    vector<perception_interfaces::msg::Prop> props_in_range;

    for (perception_interfaces::msg::Prop prop : props)
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
    double prop_angle = std::atan2(prop.y, prop.x);

    if ((smaller_angle - p_bbox_angle_err_ <= prop_angle) && (prop_angle <= larger_angle + p_bbox_angle_err_))
    {
      return true;
    }

    return false;
  }

  perception_interfaces::msg::Prop LidarCameraFuser::getClosestProp(vector<perception_interfaces::msg::Prop> props)
  {
    perception_interfaces::msg::Prop closest_prop;
    double dist = 1000; // a large number that should be bigger than the distance of all props
    for (perception_interfaces::msg::Prop prop : props)
    {
      if (hypot(prop) < dist)
      {
        dist = hypot(prop);
        closest_prop = prop;
      }
    }

    return closest_prop;
  }

  bool LidarCameraFuser::propsWithinBounds(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2)
  {
    double dist = distTwoPoints(p1.x,p1.y,p2.x,p2.y);
    double max_dist = p_dist_between_markers_ +  p_dist_between_markers_err_;
    double min_dist = p_dist_between_markers_ -  p_dist_between_markers_err_;
    if ((dist < max_dist) && (dist > min_dist))
    {
      return true;
    }
    return false;
  }

  //perception_interfaces::msg::Gate createGate(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2)
  //{
  //  perception_interfaces::msg::Gate gate;
  //  if (p1.label = "red_marker")
  //  {
  //    gate.red_marker = p1;
  //    gate.green_marker = p2;
  //  } 
  //  else 
  //  {
  //    gate.red_marker = p2;
  //    gate.green_marker = p3;
  //  }
  //  return gate;
  //}
  
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarCameraFuser)