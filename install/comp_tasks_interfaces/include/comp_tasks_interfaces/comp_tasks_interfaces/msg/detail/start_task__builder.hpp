// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__BUILDER_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_tasks_interfaces/msg/detail/start_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_tasks_interfaces
{

namespace msg
{

namespace builder
{

class Init_StartTask_finish_pnt
{
public:
  explicit Init_StartTask_finish_pnt(::comp_tasks_interfaces::msg::StartTask & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::msg::StartTask finish_pnt(::comp_tasks_interfaces::msg::StartTask::_finish_pnt_type arg)
  {
    msg_.finish_pnt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::StartTask msg_;
};

class Init_StartTask_start_pnt
{
public:
  explicit Init_StartTask_start_pnt(::comp_tasks_interfaces::msg::StartTask & msg)
  : msg_(msg)
  {}
  Init_StartTask_finish_pnt start_pnt(::comp_tasks_interfaces::msg::StartTask::_start_pnt_type arg)
  {
    msg_.start_pnt = std::move(arg);
    return Init_StartTask_finish_pnt(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::StartTask msg_;
};

class Init_StartTask_task
{
public:
  Init_StartTask_task()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartTask_start_pnt task(::comp_tasks_interfaces::msg::StartTask::_task_type arg)
  {
    msg_.task = std::move(arg);
    return Init_StartTask_start_pnt(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::StartTask msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::msg::StartTask>()
{
  return comp_tasks_interfaces::msg::builder::Init_StartTask_task();
}

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__BUILDER_HPP_
