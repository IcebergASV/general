// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/gate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_Gate_midpoint
{
public:
  explicit Init_Gate_midpoint(::perception_interfaces::msg::Gate & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::Gate midpoint(::perception_interfaces::msg::Gate::_midpoint_type arg)
  {
    msg_.midpoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::Gate msg_;
};

class Init_Gate_green_marker
{
public:
  explicit Init_Gate_green_marker(::perception_interfaces::msg::Gate & msg)
  : msg_(msg)
  {}
  Init_Gate_midpoint green_marker(::perception_interfaces::msg::Gate::_green_marker_type arg)
  {
    msg_.green_marker = std::move(arg);
    return Init_Gate_midpoint(msg_);
  }

private:
  ::perception_interfaces::msg::Gate msg_;
};

class Init_Gate_red_marker
{
public:
  Init_Gate_red_marker()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gate_green_marker red_marker(::perception_interfaces::msg::Gate::_red_marker_type arg)
  {
    msg_.red_marker = std::move(arg);
    return Init_Gate_green_marker(msg_);
  }

private:
  ::perception_interfaces::msg::Gate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::Gate>()
{
  return perception_interfaces::msg::builder::Init_Gate_red_marker();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE__BUILDER_HPP_
