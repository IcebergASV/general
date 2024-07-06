#ifndef COMPOSITION__MOCK_COORD_PUB_HPP_
#define COMPOSITION__MOCK_COORD_PUB_HPP_

#include <yaml-cpp/yaml.h>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"

#include "perception_interfaces/msg/coordinates.hpp"
#include "perception_interfaces/msg/coordinates.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace perception
{

class MockCoordPub : public rclcpp::Node
{
public:
  explicit MockCoordPub(const rclcpp::NodeOptions & options);

protected:
  void timer_callback();

private:

  int p_xmin_;
  int p_xmax_;
  int p_ymin_;
  int p_ymax_;

  rclcpp::Publisher<perception_interfaces::msg::Coordinates>::SharedPtr pub_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
  rclcpp::TimerBase::SharedPtr timer_;

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

}  // namespace perception

#endif  // COMPOSITION__MOCK_COORDS_PUB_HPP_