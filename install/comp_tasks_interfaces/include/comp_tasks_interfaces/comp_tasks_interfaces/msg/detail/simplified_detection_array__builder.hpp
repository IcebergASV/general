// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__BUILDER_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_tasks_interfaces
{

namespace msg
{

namespace builder
{

class Init_SimplifiedDetectionArray_detections
{
public:
  Init_SimplifiedDetectionArray_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::msg::SimplifiedDetectionArray detections(::comp_tasks_interfaces::msg::SimplifiedDetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::SimplifiedDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::msg::SimplifiedDetectionArray>()
{
  return comp_tasks_interfaces::msg::builder::Init_SimplifiedDetectionArray_detections();
}

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__BUILDER_HPP_
