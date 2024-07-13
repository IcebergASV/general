#ifndef COMPOSITION__COORD_FINDER_COMPONENT_HPP_
#define COMPOSITION__COORD_FINDER_COMPONENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "perception_interfaces/msg/prop.hpp"
#include "perception_interfaces/msg/prop.hpp"
#include "perception_interfaces/msg/prop_array.hpp"

using std::placeholders::_1;

namespace perception
{

class CoordFinder : public rclcpp::Node
{
public:
  explicit CoordFinder(const rclcpp::NodeOptions & options);

protected:
  void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
  void propCallback(const perception_interfaces::msg::PropArray::SharedPtr msg);

private:
  geometry_msgs::msg::PoseStamped pose_msg_;
  perception_interfaces::msg::PropArray prop_msg_;

  rclcpp::Subscription<perception_interfaces::msg::PropArray>::SharedPtr prop_sub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;
  
  rclcpp::Publisher<perception_interfaces::msg::Prop>::SharedPtr prop_coords_pub_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

  bool new_prop_;
  
  bool isValidLabel(std::string label);
  
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