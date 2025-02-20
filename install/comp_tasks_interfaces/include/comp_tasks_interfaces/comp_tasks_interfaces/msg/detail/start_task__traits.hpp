// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__TRAITS_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_tasks_interfaces/msg/detail/start_task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__traits.hpp"
// Member 'start_pnt'
// Member 'finish_pnt'
#include "geographic_msgs/msg/detail/geo_point__traits.hpp"

namespace comp_tasks_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StartTask & msg,
  std::ostream & out)
{
  out << "{";
  // member: task
  {
    out << "task: ";
    to_flow_style_yaml(msg.task, out);
    out << ", ";
  }

  // member: start_pnt
  {
    out << "start_pnt: ";
    to_flow_style_yaml(msg.start_pnt, out);
    out << ", ";
  }

  // member: finish_pnt
  {
    out << "finish_pnt: ";
    to_flow_style_yaml(msg.finish_pnt, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartTask & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task:\n";
    to_block_style_yaml(msg.task, out, indentation + 2);
  }

  // member: start_pnt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_pnt:\n";
    to_block_style_yaml(msg.start_pnt, out, indentation + 2);
  }

  // member: finish_pnt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finish_pnt:\n";
    to_block_style_yaml(msg.finish_pnt, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartTask & msg, bool use_flow_style = false)
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
  const comp_tasks_interfaces::msg::StartTask & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::msg::StartTask & msg)
{
  return comp_tasks_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::msg::StartTask>()
{
  return "comp_tasks_interfaces::msg::StartTask";
}

template<>
inline const char * name<comp_tasks_interfaces::msg::StartTask>()
{
  return "comp_tasks_interfaces/msg/StartTask";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::msg::StartTask>
  : std::integral_constant<bool, has_fixed_size<comp_tasks_interfaces::msg::Task>::value && has_fixed_size<geographic_msgs::msg::GeoPoint>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::msg::StartTask>
  : std::integral_constant<bool, has_bounded_size<comp_tasks_interfaces::msg::Task>::value && has_bounded_size<geographic_msgs::msg::GeoPoint>::value> {};

template<>
struct is_message<comp_tasks_interfaces::msg::StartTask>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__TRAITS_HPP_
