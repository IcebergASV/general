// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__struct.hpp"
// Member 'start_pnt'
// Member 'finish_pnt'
#include "geographic_msgs/msg/detail/geo_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__msg__StartTask __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__msg__StartTask __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StartTask_
{
  using Type = StartTask_<ContainerAllocator>;

  explicit StartTask_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_init),
    start_pnt(_init),
    finish_pnt(_init)
  {
    (void)_init;
  }

  explicit StartTask_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_alloc, _init),
    start_pnt(_alloc, _init),
    finish_pnt(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _task_type =
    comp_tasks_interfaces::msg::Task_<ContainerAllocator>;
  _task_type task;
  using _start_pnt_type =
    geographic_msgs::msg::GeoPoint_<ContainerAllocator>;
  _start_pnt_type start_pnt;
  using _finish_pnt_type =
    geographic_msgs::msg::GeoPoint_<ContainerAllocator>;
  _finish_pnt_type finish_pnt;

  // setters for named parameter idiom
  Type & set__task(
    const comp_tasks_interfaces::msg::Task_<ContainerAllocator> & _arg)
  {
    this->task = _arg;
    return *this;
  }
  Type & set__start_pnt(
    const geographic_msgs::msg::GeoPoint_<ContainerAllocator> & _arg)
  {
    this->start_pnt = _arg;
    return *this;
  }
  Type & set__finish_pnt(
    const geographic_msgs::msg::GeoPoint_<ContainerAllocator> & _arg)
  {
    this->finish_pnt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__msg__StartTask
    std::shared_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__msg__StartTask
    std::shared_ptr<comp_tasks_interfaces::msg::StartTask_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartTask_ & other) const
  {
    if (this->task != other.task) {
      return false;
    }
    if (this->start_pnt != other.start_pnt) {
      return false;
    }
    if (this->finish_pnt != other.finish_pnt) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartTask_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartTask_

// alias to use template instance with default allocator
using StartTask =
  comp_tasks_interfaces::msg::StartTask_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_HPP_
