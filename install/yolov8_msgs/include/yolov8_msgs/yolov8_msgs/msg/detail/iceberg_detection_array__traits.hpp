// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/IcebergDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/iceberg_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'icebergdetections'
#include "yolov8_msgs/msg/detail/iceberg_detection__traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IcebergDetectionArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: icebergdetections
  {
    if (msg.icebergdetections.size() == 0) {
      out << "icebergdetections: []";
    } else {
      out << "icebergdetections: [";
      size_t pending_items = msg.icebergdetections.size();
      for (auto item : msg.icebergdetections) {
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
  const IcebergDetectionArray & msg,
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

  // member: icebergdetections
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.icebergdetections.size() == 0) {
      out << "icebergdetections: []\n";
    } else {
      out << "icebergdetections:\n";
      for (auto item : msg.icebergdetections) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IcebergDetectionArray & msg, bool use_flow_style = false)
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

}  // namespace yolov8_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yolov8_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolov8_msgs::msg::IcebergDetectionArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::IcebergDetectionArray & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::IcebergDetectionArray>()
{
  return "yolov8_msgs::msg::IcebergDetectionArray";
}

template<>
inline const char * name<yolov8_msgs::msg::IcebergDetectionArray>()
{
  return "yolov8_msgs/msg/IcebergDetectionArray";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::IcebergDetectionArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::IcebergDetectionArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yolov8_msgs::msg::IcebergDetectionArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__TRAITS_HPP_
