// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetection.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__BUILDER_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_tasks_interfaces/msg/detail/simplified_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_tasks_interfaces
{

namespace msg
{

namespace builder
{

class Init_SimplifiedDetection_x
{
public:
  explicit Init_SimplifiedDetection_x(::comp_tasks_interfaces::msg::SimplifiedDetection & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::msg::SimplifiedDetection x(::comp_tasks_interfaces::msg::SimplifiedDetection::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::SimplifiedDetection msg_;
};

class Init_SimplifiedDetection_id
{
public:
  explicit Init_SimplifiedDetection_id(::comp_tasks_interfaces::msg::SimplifiedDetection & msg)
  : msg_(msg)
  {}
  Init_SimplifiedDetection_x id(::comp_tasks_interfaces::msg::SimplifiedDetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SimplifiedDetection_x(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::SimplifiedDetection msg_;
};

class Init_SimplifiedDetection_score
{
public:
  explicit Init_SimplifiedDetection_score(::comp_tasks_interfaces::msg::SimplifiedDetection & msg)
  : msg_(msg)
  {}
  Init_SimplifiedDetection_id score(::comp_tasks_interfaces::msg::SimplifiedDetection::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_SimplifiedDetection_id(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::SimplifiedDetection msg_;
};

class Init_SimplifiedDetection_class_name
{
public:
  Init_SimplifiedDetection_class_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimplifiedDetection_score class_name(::comp_tasks_interfaces::msg::SimplifiedDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_SimplifiedDetection_score(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::SimplifiedDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::msg::SimplifiedDetection>()
{
  return comp_tasks_interfaces::msg::builder::Init_SimplifiedDetection_class_name();
}

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__BUILDER_HPP_
