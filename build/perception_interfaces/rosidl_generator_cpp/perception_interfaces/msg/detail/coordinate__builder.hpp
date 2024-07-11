// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coordinate_probability
{
public:
  explicit Init_Coordinate_probability(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::Coordinate probability(::perception_interfaces::msg::Coordinate::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_radius
{
public:
  explicit Init_Coordinate_radius(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_probability radius(::perception_interfaces::msg::Coordinate::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_Coordinate_probability(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_point
{
public:
  explicit Init_Coordinate_point(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_radius point(::perception_interfaces::msg::Coordinate::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_Coordinate_radius(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_label
{
public:
  explicit Init_Coordinate_label(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_point label(::perception_interfaces::msg::Coordinate::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Coordinate_point(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_id
{
public:
  Init_Coordinate_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_label id(::perception_interfaces::msg::Coordinate::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Coordinate_label(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::Coordinate>()
{
  return perception_interfaces::msg::builder::Init_Coordinate_id();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_
