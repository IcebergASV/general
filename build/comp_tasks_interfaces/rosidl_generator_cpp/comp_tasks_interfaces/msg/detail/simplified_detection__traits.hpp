// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetection.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__TRAITS_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_tasks_interfaces/msg/detail/simplified_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace comp_tasks_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SimplifiedDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: score
  {
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SimplifiedDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: class_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << "\n";
  }

  // member: score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SimplifiedDetection & msg, bool use_flow_style = false)
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

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::msg::SimplifiedDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::msg::SimplifiedDetection & msg)
{
  return comp_tasks_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::msg::SimplifiedDetection>()
{
  return "comp_tasks_interfaces::msg::SimplifiedDetection";
}

template<>
inline const char * name<comp_tasks_interfaces::msg::SimplifiedDetection>()
{
  return "comp_tasks_interfaces/msg/SimplifiedDetection";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::msg::SimplifiedDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::msg::SimplifiedDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<comp_tasks_interfaces::msg::SimplifiedDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__TRAITS_HPP_
