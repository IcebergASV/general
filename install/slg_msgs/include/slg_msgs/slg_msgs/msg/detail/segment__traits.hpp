// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT__TRAITS_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slg_msgs/msg/detail/segment__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'last_point_prior_segment'
// Member 'first_point_next_segment'
// Member 'points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace slg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Segment & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: angular_distance
  {
    out << "angular_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_distance, out);
    out << ", ";
  }

  // member: last_point_prior_segment
  {
    out << "last_point_prior_segment: ";
    to_flow_style_yaml(msg.last_point_prior_segment, out);
    out << ", ";
  }

  // member: first_point_next_segment
  {
    out << "first_point_next_segment: ";
    to_flow_style_yaml(msg.first_point_next_segment, out);
    out << ", ";
  }

  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
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
  const Segment & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }

  // member: angular_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_distance, out);
    out << "\n";
  }

  // member: last_point_prior_segment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_point_prior_segment:\n";
    to_block_style_yaml(msg.last_point_prior_segment, out, indentation + 2);
  }

  // member: first_point_next_segment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "first_point_next_segment:\n";
    to_block_style_yaml(msg.first_point_next_segment, out, indentation + 2);
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Segment & msg, bool use_flow_style = false)
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
  const slg_msgs::msg::Segment & msg,
  std::ostream & out, size_t indentation = 0)
{
  slg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const slg_msgs::msg::Segment & msg)
{
  return slg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<slg_msgs::msg::Segment>()
{
  return "slg_msgs::msg::Segment";
}

template<>
inline const char * name<slg_msgs::msg::Segment>()
{
  return "slg_msgs/msg/Segment";
}

template<>
struct has_fixed_size<slg_msgs::msg::Segment>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slg_msgs::msg::Segment>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slg_msgs::msg::Segment>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT__TRAITS_HPP_
