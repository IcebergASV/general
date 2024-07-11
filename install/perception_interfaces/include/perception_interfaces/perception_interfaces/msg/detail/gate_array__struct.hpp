// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_interfaces:msg/GateArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gates'
#include "perception_interfaces/msg/detail/gate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_interfaces__msg__GateArray __attribute__((deprecated))
#else
# define DEPRECATED__perception_interfaces__msg__GateArray __declspec(deprecated)
#endif

namespace perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GateArray_
{
  using Type = GateArray_<ContainerAllocator>;

  explicit GateArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GateArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _gates_type =
    std::vector<perception_interfaces::msg::Gate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<perception_interfaces::msg::Gate_<ContainerAllocator>>>;
  _gates_type gates;

  // setters for named parameter idiom
  Type & set__gates(
    const std::vector<perception_interfaces::msg::Gate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<perception_interfaces::msg::Gate_<ContainerAllocator>>> & _arg)
  {
    this->gates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_interfaces::msg::GateArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_interfaces::msg::GateArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::GateArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::GateArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_interfaces__msg__GateArray
    std::shared_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_interfaces__msg__GateArray
    std::shared_ptr<perception_interfaces::msg::GateArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GateArray_ & other) const
  {
    if (this->gates != other.gates) {
      return false;
    }
    return true;
  }
  bool operator!=(const GateArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GateArray_

// alias to use template instance with default allocator
using GateArray =
  perception_interfaces::msg::GateArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_HPP_
