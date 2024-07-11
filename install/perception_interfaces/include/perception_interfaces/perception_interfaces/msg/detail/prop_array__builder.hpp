// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/PropArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/prop_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_PropArray_props
{
public:
  Init_PropArray_props()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::perception_interfaces::msg::PropArray props(::perception_interfaces::msg::PropArray::_props_type arg)
  {
    msg_.props = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::PropArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::PropArray>()
{
  return perception_interfaces::msg::builder::Init_PropArray_props();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__BUILDER_HPP_
