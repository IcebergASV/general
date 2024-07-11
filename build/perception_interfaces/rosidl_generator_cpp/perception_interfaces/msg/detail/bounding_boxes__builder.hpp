// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/bounding_boxes__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxes_bounding_boxes
{
public:
  Init_BoundingBoxes_bounding_boxes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::perception_interfaces::msg::BoundingBoxes bounding_boxes(::perception_interfaces::msg::BoundingBoxes::_bounding_boxes_type arg)
  {
    msg_.bounding_boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBoxes msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::BoundingBoxes>()
{
  return perception_interfaces::msg::builder::Init_BoundingBoxes_bounding_boxes();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
