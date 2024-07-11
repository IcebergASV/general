// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coordinates_coordinates
{
public:
  Init_Coordinates_coordinates()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::perception_interfaces::msg::Coordinates coordinates(::perception_interfaces::msg::Coordinates::_coordinates_type arg)
  {
    msg_.coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::Coordinates>()
{
  return perception_interfaces::msg::builder::Init_Coordinates_coordinates();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__BUILDER_HPP_
