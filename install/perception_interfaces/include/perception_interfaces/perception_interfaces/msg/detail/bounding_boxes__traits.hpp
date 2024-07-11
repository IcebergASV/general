// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_interfaces:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "perception_interfaces/msg/detail/bounding_boxes__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'bounding_boxes'
#include "perception_interfaces/msg/detail/bounding_box__traits.hpp"

namespace perception_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoundingBoxes & msg,
  std::ostream & out)
{
  out << "{";
  // member: bounding_boxes
  {
    if (msg.bounding_boxes.size() == 0) {
      out << "bounding_boxes: []";
    } else {
      out << "bounding_boxes: [";
      size_t pending_items = msg.bounding_boxes.size();
      for (auto item : msg.bounding_boxes) {
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
  const BoundingBoxes & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bounding_boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bounding_boxes.size() == 0) {
      out << "bounding_boxes: []\n";
    } else {
      out << "bounding_boxes:\n";
      for (auto item : msg.bounding_boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoundingBoxes & msg, bool use_flow_style = false)
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
  const perception_interfaces::msg::BoundingBoxes & msg,
  std::ostream & out, size_t indentation = 0)
{
  perception_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use perception_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const perception_interfaces::msg::BoundingBoxes & msg)
{
  return perception_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<perception_interfaces::msg::BoundingBoxes>()
{
  return "perception_interfaces::msg::BoundingBoxes";
}

template<>
inline const char * name<perception_interfaces::msg::BoundingBoxes>()
{
  return "perception_interfaces/msg/BoundingBoxes";
}

template<>
struct has_fixed_size<perception_interfaces::msg::BoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<perception_interfaces::msg::BoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<perception_interfaces::msg::BoundingBoxes>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_
