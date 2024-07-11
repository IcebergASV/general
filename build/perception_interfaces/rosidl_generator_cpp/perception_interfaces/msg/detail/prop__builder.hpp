// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/Prop.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__PROP__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__PROP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/prop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_Prop_probability
{
public:
  explicit Init_Prop_probability(::perception_interfaces::msg::Prop & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::Prop probability(::perception_interfaces::msg::Prop::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::Prop msg_;
};

class Init_Prop_radius
{
public:
  explicit Init_Prop_radius(::perception_interfaces::msg::Prop & msg)
  : msg_(msg)
  {}
  Init_Prop_probability radius(::perception_interfaces::msg::Prop::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_Prop_probability(msg_);
  }

private:
  ::perception_interfaces::msg::Prop msg_;
};

class Init_Prop_point
{
public:
  explicit Init_Prop_point(::perception_interfaces::msg::Prop & msg)
  : msg_(msg)
  {}
  Init_Prop_radius point(::perception_interfaces::msg::Prop::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_Prop_radius(msg_);
  }

private:
  ::perception_interfaces::msg::Prop msg_;
};

class Init_Prop_label
{
public:
  explicit Init_Prop_label(::perception_interfaces::msg::Prop & msg)
  : msg_(msg)
  {}
  Init_Prop_point label(::perception_interfaces::msg::Prop::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Prop_point(msg_);
  }

private:
  ::perception_interfaces::msg::Prop msg_;
};

class Init_Prop_id
{
public:
  Init_Prop_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Prop_label id(::perception_interfaces::msg::Prop::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Prop_label(msg_);
  }

private:
  ::perception_interfaces::msg::Prop msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::Prop>()
{
  return perception_interfaces::msg::builder::Init_Prop_id();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__PROP__BUILDER_HPP_
