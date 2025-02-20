// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__TRAITS_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'detections'
#include "comp_tasks_interfaces/msg/detail/simplified_detection__traits.hpp"

namespace comp_tasks_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SimplifiedDetectionArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: detections
  {
    if (msg.detections.size() == 0) {
      out << "detections: []";
    } else {
      out << "detections: [";
      size_t pending_items = msg.detections.size();
      for (auto item : msg.detections) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SimplifiedDetectionArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detections
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.detections.size() == 0) {
      out << "detections: []\n";
    } else {
      out << "detections:\n";
      for (auto item : msg.detections) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SimplifiedDetectionArray & msg, bool use_flow_style = false)
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
  const comp_tasks_interfaces::msg::SimplifiedDetectionArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::msg::SimplifiedDetectionArray & msg)
{
  return comp_tasks_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::msg::SimplifiedDetectionArray>()
{
  return "comp_tasks_interfaces::msg::SimplifiedDetectionArray";
}

template<>
inline const char * name<comp_tasks_interfaces::msg::SimplifiedDetectionArray>()
{
  return "comp_tasks_interfaces/msg/SimplifiedDetectionArray";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::msg::SimplifiedDetectionArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::msg::SimplifiedDetectionArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<comp_tasks_interfaces::msg::SimplifiedDetectionArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__TRAITS_HPP_
