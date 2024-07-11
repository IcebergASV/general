// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'red_marker'
// Member 'green_marker'
#include "perception_interfaces/msg/detail/prop__struct.hpp"
// Member 'midpoint'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_interfaces__msg__Gate __attribute__((deprecated))
#else
# define DEPRECATED__perception_interfaces__msg__Gate __declspec(deprecated)
#endif

namespace perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gate_
{
  using Type = Gate_<ContainerAllocator>;

  explicit Gate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : red_marker(_init),
    green_marker(_init),
    midpoint(_init)
  {
    (void)_init;
  }

  explicit Gate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : red_marker(_alloc, _init),
    green_marker(_alloc, _init),
    midpoint(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _red_marker_type =
    perception_interfaces::msg::Prop_<ContainerAllocator>;
  _red_marker_type red_marker;
  using _green_marker_type =
    perception_interfaces::msg::Prop_<ContainerAllocator>;
  _green_marker_type green_marker;
  using _midpoint_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _midpoint_type midpoint;

  // setters for named parameter idiom
  Type & set__red_marker(
    const perception_interfaces::msg::Prop_<ContainerAllocator> & _arg)
  {
    this->red_marker = _arg;
    return *this;
  }
  Type & set__green_marker(
    const perception_interfaces::msg::Prop_<ContainerAllocator> & _arg)
  {
    this->green_marker = _arg;
    return *this;
  }
  Type & set__midpoint(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->midpoint = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_interfaces::msg::Gate_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_interfaces::msg::Gate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_interfaces::msg::Gate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_interfaces::msg::Gate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::Gate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::Gate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::Gate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::Gate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_interfaces::msg::Gate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_interfaces::msg::Gate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_interfaces__msg__Gate
    std::shared_ptr<perception_interfaces::msg::Gate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_interfaces__msg__Gate
    std::shared_ptr<perception_interfaces::msg::Gate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gate_ & other) const
  {
    if (this->red_marker != other.red_marker) {
      return false;
    }
    if (this->green_marker != other.green_marker) {
      return false;
    }
    if (this->midpoint != other.midpoint) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gate_

// alias to use template instance with default allocator
using Gate =
  perception_interfaces::msg::Gate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_HPP_
