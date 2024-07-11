// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__TRAITS_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "perception_interfaces/msg/detail/lidar_detected_prop__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace perception_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LidarDetectedProp & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: center
  {
    out << "center: ";
    to_flow_style_yaml(msg.center, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: radius_diff
  {
    out << "radius_diff: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_diff, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LidarDetectedProp & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }

  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center:\n";
    to_block_style_yaml(msg.center, out, indentation + 2);
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: radius_diff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius_diff: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_diff, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LidarDetectedProp & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace perception_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use perception_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const perception_interfaces::msg::LidarDetectedProp & msg,
  std::ostream & out, size_t indentation = 0)
{
  perception_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use perception_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const perception_interfaces::msg::LidarDetectedProp & msg)
{
  return perception_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<perception_interfaces::msg::LidarDetectedProp>()
{
  return "perception_interfaces::msg::LidarDetectedProp";
}

template<>
inline const char * name<perception_interfaces::msg::LidarDetectedProp>()
{
  return "perception_interfaces/msg/LidarDetectedProp";
}

template<>
struct has_fixed_size<perception_interfaces::msg::LidarDetectedProp>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<perception_interfaces::msg::LidarDetectedProp>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<perception_interfaces::msg::LidarDetectedProp>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__TRAITS_HPP_
