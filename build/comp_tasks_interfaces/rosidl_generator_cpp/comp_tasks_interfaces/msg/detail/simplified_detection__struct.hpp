// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetection.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetection __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetection __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SimplifiedDetection_
{
  using Type = SimplifiedDetection_<ContainerAllocator>;

  explicit SimplifiedDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_name = "";
      this->score = 0.0;
      this->id = "";
      this->x = 0.0;
    }
  }

  explicit SimplifiedDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc),
    id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_name = "";
      this->score = 0.0;
      this->id = "";
      this->x = 0.0;
    }
  }

  // field types and members
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _score_type =
    double;
  _score_type score;
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _x_type =
    double;
  _x_type x;

  // setters for named parameter idiom
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__score(
    const double & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetection
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetection
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SimplifiedDetection_ & other) const
  {
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    return true;
  }
  bool operator!=(const SimplifiedDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SimplifiedDetection_

// alias to use template instance with default allocator
using SimplifiedDetection =
  comp_tasks_interfaces::msg::SimplifiedDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_HPP_
