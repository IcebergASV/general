// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__TRAITS_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slg_msgs/msg/detail/segment_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'segments'
#include "slg_msgs/msg/detail/segment__traits.hpp"

namespace slg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SegmentArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: segments
  {
    if (msg.segments.size() == 0) {
      out << "segments: []";
    } else {
      out << "segments: [";
      size_t pending_items = msg.segments.size();
      for (auto item : msg.segments) {
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
  const SegmentArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: segments
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.segments.size() == 0) {
      out << "segments: []\n";
    } else {
      out << "segments:\n";
      for (auto item : msg.segments) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SegmentArray & msg, bool use_flow_style = false)
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

}  // namespace slg_msgs

namespace rosidl_generator_traits
{

[[deprecated("use slg_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const slg_msgs::msg::SegmentArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  slg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const slg_msgs::msg::SegmentArray & msg)
{
  return slg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<slg_msgs::msg::SegmentArray>()
{
  return "slg_msgs::msg::SegmentArray";
}

template<>
inline const char * name<slg_msgs::msg::SegmentArray>()
{
  return "slg_msgs/msg/SegmentArray";
}

template<>
struct has_fixed_size<slg_msgs::msg::SegmentArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slg_msgs::msg::SegmentArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slg_msgs::msg::SegmentArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__TRAITS_HPP_
