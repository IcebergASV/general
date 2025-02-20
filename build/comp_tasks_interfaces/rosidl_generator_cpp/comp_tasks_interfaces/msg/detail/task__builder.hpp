// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_tasks_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_tasks_interfaces
{

namespace msg
{

namespace builder
{

class Init_Task_current_task
{
public:
  Init_Task_current_task()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::msg::Task current_task(::comp_tasks_interfaces::msg::Task::_current_task_type arg)
  {
    msg_.current_task = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::msg::Task>()
{
  return comp_tasks_interfaces::msg::builder::Init_Task_current_task();
}

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
