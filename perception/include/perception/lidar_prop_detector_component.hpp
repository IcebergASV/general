#ifndef COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_
#define COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_

#include <yaml-cpp/yaml.h>
#include <string>
#include <eigen3/Eigen/Dense>

#include "rclcpp/rclcpp.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "perception_interfaces/msg/lidar_detected_prop.hpp"
#include "perception_interfaces/msg/lidar_detected_prop_array.hpp"

using std::placeholders::_1;

namespace perception
{

class LidarPropDetector : public rclcpp::Node
{
public:
  explicit LidarPropDetector(const rclcpp::NodeOptions & options);

protected:
  void scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg);

private:
  std::map<std::string, double> p_prop_radii_;
  double p_max_lidar_dist_;
  double p_min_lidar_dist_;
  int p_min_points_in_segment_;
  double p_max_radius_diff_;
  rclcpp::Subscription<slg_msgs::msg::SegmentArray>::SharedPtr sub_;
  rclcpp::Publisher<perception_interfaces::msg::LidarDetectedPropArray>::SharedPtr pub_;
  
  std::vector<double> extractCoordinates(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract);
  void attemptToCreateAndAddLidarDetectedProp(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::LidarDetectedPropArray& prop_array);
  bool isSegmentValid(slg_msgs::msg::Segment segment);
  perception_interfaces::msg::LidarDetectedProp createLidarDetectedProp(std::vector<geometry_msgs::msg::Point> points);
  void findClosestMatchAndSetRadiusDiff(perception_interfaces::msg::LidarDetectedProp& circle);
  bool measuredRadiusIsCloseToExpected(double radius_diff);



  // TODO - figure out how to move this to a library and pass in a reference to the node calling it or make a subclass of rclcpp
  template <typename T>
  void getParam(std::string param_str, T& param, T default_value, std::string desc)
  {
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = desc;
    this->declare_parameter<T>(param_str, default_value, param_desc);
    this->get_parameter(param_str, param);

    std::string param_log_output = param_str + ": " + std::to_string(param);
    RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

    return;
  }

  // TODO - figure out how to move this to a library and pass in a reference to the node calling it or make a subclass of rclcpp
  template <typename T>
  void getStringParamConvertToMap(std::string param_str, std::map<std::string, T>& param, std::string default_value, std::string desc)
  {
    std::string map_string;
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = desc;
    this->declare_parameter<std::string>(param_str, default_value, param_desc);
    this->get_parameter(param_str, map_string);

    try
    {
      YAML::Node yaml_node = YAML::Load(map_string);
      for (YAML::const_iterator it = yaml_node.begin(); it != yaml_node.end(); ++it)
      {
        param[it->first.as<std::string>()] = it->second.as<double>();
      }

      for (const auto &pair : param)
      {
        RCLCPP_INFO(this->get_logger(), "Prop: %s, Expected Radius: %f", pair.first.c_str(), pair.second);
      }
    }
    catch (const YAML::ParserException &e)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to parse YAML: %s", e.what());
    }
  }
};

}  // namespace composition

#endif  // COMPOSITION__LIDAR_CLUSTER_COMPONENT_HPP_