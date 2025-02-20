// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__msg__Task __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__msg__Task __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Task_
{
  using Type = Task_<ContainerAllocator>;

  explicit Task_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_task = 0;
    }
  }

  explicit Task_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_task = 0;
    }
  }

  // field types and members
  using _current_task_type =
    uint8_t;
  _current_task_type current_task;

  // setters for named parameter idiom
  Type & set__current_task(
    const uint8_t & _arg)
  {
    this->current_task = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TASK_NOT_SET =
    0u;
  static constexpr uint8_t MANEUVERING =
    1u;
  static constexpr uint8_t NAVIGATION =
    2u;
  static constexpr uint8_t COLLISION_AVOIDANCE =
    3u;
  static constexpr uint8_t DOCKING =
    4u;

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::msg::Task_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::msg::Task_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::Task_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::Task_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__msg__Task
    std::shared_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__msg__Task
    std::shared_ptr<comp_tasks_interfaces::msg::Task_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_ & other) const
  {
    if (this->current_task != other.current_task) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_

// alias to use template instance with default allocator
using Task =
  comp_tasks_interfaces::msg::Task_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Task_<ContainerAllocator>::TASK_NOT_SET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Task_<ContainerAllocator>::MANEUVERING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Task_<ContainerAllocator>::NAVIGATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Task_<ContainerAllocator>::COLLISION_AVOIDANCE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Task_<ContainerAllocator>::DOCKING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
