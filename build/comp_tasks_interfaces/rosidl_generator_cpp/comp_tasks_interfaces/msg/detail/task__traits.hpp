// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_tasks_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace comp_tasks_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Task & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_task
  {
    out << "current_task: ";
    rosidl_generator_traits::value_to_yaml(msg.current_task, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_task: ";
    rosidl_generator_traits::value_to_yaml(msg.current_task, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task & msg, bool use_flow_style = false)
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
  const comp_tasks_interfaces::msg::Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::msg::Task & msg)
{
  return comp_tasks_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::msg::Task>()
{
  return "comp_tasks_interfaces::msg::Task";
}

template<>
inline const char * name<comp_tasks_interfaces::msg::Task>()
{
  return "comp_tasks_interfaces/msg/Task";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::msg::Task>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::msg::Task>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<comp_tasks_interfaces::msg::Task>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
