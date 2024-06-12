#ifndef COMPOSITION__COORD_FINDER_COMPONENT_HPP_
#define COMPOSITION__COORD_FINDER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/lidar_detected_prop.hpp"
#include "perception_interfaces/msg/lidar_detected_prop_array.hpp"

using std::placeholders::_1;

namespace perception
{

class CoordFinder : public rclcpp::Node
{
public:
  explicit CoordFinder(const rclcpp::NodeOptions & options);

protected:
  void scanCallback(const perception_interfaces::msg::LidarDetectedPropArray::SharedPtr msg);

private:
  std::map<std::string, double> p_prop_radii_;
  double p_max_lidar_dist_;
  double p_min_lidar_dist_;
  int p_min_points_in_segment_;
  double p_max_radius_diff_;
  double p_lidar_fov_;
  rclcpp::Subscription<perception_interfaces::msg::LidarDetectedPropArray>::SharedPtr sub_;
  //rclcpp::Publisher<perception_interfaces::msg::Prop>::SharedPtr pub_;
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

#endif  // COMPOSITION__LIDAR_PROP_DETECTOR_COMPONENT_HPP_