#ifndef COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_HPP_

#include <yaml-cpp/yaml.h>
#include <string>
#include <eigen3/Eigen/Dense>

#include "rclcpp/rclcpp.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/gate.hpp"
#include "perception_interfaces/msg/bounding_box.hpp"
#include "perception_interfaces/msg/bounding_boxes.hpp"
#include "perception_interfaces/msg/prop.hpp"
#include "perception_interfaces/msg/prop_array.hpp"

using std::placeholders::_1;

namespace perception
{

class LidarCameraFuser : public rclcpp::Node
{
public:
  explicit LidarCameraFuser(const rclcpp::NodeOptions & options);

protected:
  void lidarBBoxCallback(const perception_interfaces::msg::PropArray::SharedPtr msg);
  void cameraBBoxCallback(const perception_interfaces::msg::BoundingBoxes::SharedPtr msg);

private:
  double p_dist_between_markers_;
  double p_dist_between_markers_err_;
  int p_camera_res_x_;
  int p_camera_fov_;
  double p_bbox_angle_err_;
  
  bool haveDetectedGateWithCamera_;


  std::vector<perception_interfaces::msg::BoundingBox> bounding_boxes_;

  rclcpp::Subscription<perception_interfaces::msg::PropArray>::SharedPtr lidar_sub_;
  rclcpp::Subscription<perception_interfaces::msg::BoundingBoxes>::SharedPtr camera_sub_;

  rclcpp::Publisher<perception_interfaces::msg::Gate>::SharedPtr pub_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

  bool getClosestLidarPropWithinBBoxRange(perception_interfaces::msg::BoundingBox b_box, std::vector<perception_interfaces::msg::Prop> lidar_props, perception_interfaces::msg::Prop& closest_prop);
  bool propFallsWithinAngles(perception_interfaces::msg::Prop prop, double smaller_angle, double larger_angle);
  perception_interfaces::msg::Prop getClosestProp(std::vector<perception_interfaces::msg::Prop> props);
  bool propsWithinBounds(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2);

  rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

  // TODO - figure out how to move this to a library and pass in a reference to the node calling it or make a subclass of rclcpp
  template <typename T>
  void getParam(std::string param_name, T& param, T default_value, std::string desc)
  {
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = desc;
    this->declare_parameter<T>(param_name, default_value, param_desc);
    this->get_parameter(param_name, param);
    std::string param_log_output = param_name + ": " + std::to_string(param);
    RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

    return;
  }
};

}  // namespace perception

#endif  // COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_HPP_