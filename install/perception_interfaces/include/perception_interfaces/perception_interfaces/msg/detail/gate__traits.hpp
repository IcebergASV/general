// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE__TRAITS_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "perception_interfaces/msg/detail/gate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'red_marker'
// Member 'green_marker'
#include "perception_interfaces/msg/detail/prop__traits.hpp"
// Member 'midpoint'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace perception_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gate & msg,
  std::ostream & out)
{
  out << "{";
  // member: red_marker
  {
    out << "red_marker: ";
    to_flow_style_yaml(msg.red_marker, out);
    out << ", ";
  }

  // member: green_marker
  {
    out << "green_marker: ";
    to_flow_style_yaml(msg.green_marker, out);
    out << ", ";
  }

  // member: midpoint
  {
    out << "midpoint: ";
    to_flow_style_yaml(msg.midpoint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red_marker
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_marker:\n";
    to_block_style_yaml(msg.red_marker, out, indentation + 2);
  }

  // member: green_marker
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "green_marker:\n";
    to_block_style_yaml(msg.green_marker, out, indentation + 2);
  }

  // member: midpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "midpoint:\n";
    to_block_style_yaml(msg.midpoint, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gate & msg, bool use_flow_style = false)
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
  const perception_interfaces::msg::Gate & msg,
  std::ostream & out, size_t indentation = 0)
{
  perception_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use perception_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const perception_interfaces::msg::Gate & msg)
{
  return perception_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<perception_interfaces::msg::Gate>()
{
  return "perception_interfaces::msg::Gate";
}

template<>
inline const char * name<perception_interfaces::msg::Gate>()
{
  return "perception_interfaces/msg/Gate";
}

template<>
struct has_fixed_size<perception_interfaces::msg::Gate>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<perception_interfaces::msg::Prop>::value> {};

template<>
struct has_bounded_size<perception_interfaces::msg::Gate>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<perception_interfaces::msg::Prop>::value> {};

template<>
struct is_message<perception_interfaces::msg::Gate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE__TRAITS_HPP_
