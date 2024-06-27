#ifndef COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_H_
#define COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_H_

#include <yaml-cpp/yaml.h>
#include <string>
#include <eigen3/Eigen/Dense>

#include "rclcpp/rclcpp.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/lidar_detected_prop.hpp"
#include "perception_interfaces/msg/lidar_detected_prop_array.hpp"
#include "perception_interfaces/msg/gate.hpp"
#include "perception_interfaces/msg/bounding_box.hpp"
#include "perception_interfaces/msg/bounding_boxes.hpp"

using std::placeholders::_1;

namespace perception
{

class LidarCameraFuser : public rclcpp::Node
{
public:
  explicit LidarCameraFuser(const rclcpp::NodeOptions & options);

protected:
  void lidarBBoxCallback(const perception_interfaces::msg::LidarDetectedPropArray::SharedPtr msg);
  void cameraBBoxCallback(const perception_interfaces::msg::BoundingBoxes::SharedPtr msg);

private:
  double p_dist_between_markers_;
  double p_dist_between_markers_err_;
  bool haveDetectedGateWithCamera_;

  rclcpp::Subscription<perception_interfaces::msg::LidarDetectedPropArray>::SharedPtr lidar_sub_;
  rclcpp::Subscription<perception_interfaces::msg::BoundingBoxes>::SharedPtr camera_sub_;

  rclcpp::Publisher<perception_interfaces::msg::Gate>::SharedPtr pub_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
  
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

#endif  // COMPOSITION__LIDAR_CAMERA_FUSER_COMPONENT_H_