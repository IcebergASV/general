// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/GateArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/gate_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_GateArray_gates
{
public:
  Init_GateArray_gates()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::perception_interfaces::msg::GateArray gates(::perception_interfaces::msg::GateArray::_gates_type arg)
  {
    msg_.gates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::GateArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::GateArray>()
{
  return perception_interfaces::msg::builder::Init_GateArray_gates();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__BUILDER_HPP_
