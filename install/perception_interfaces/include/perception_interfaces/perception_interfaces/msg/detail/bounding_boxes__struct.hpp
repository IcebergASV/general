// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_interfaces:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bounding_boxes'
#include "perception_interfaces/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_interfaces__msg__BoundingBoxes __attribute__((deprecated))
#else
# define DEPRECATED__perception_interfaces__msg__BoundingBoxes __declspec(deprecated)
#endif

namespace perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoundingBoxes_
{
  using Type = BoundingBoxes_<ContainerAllocator>;

  explicit BoundingBoxes_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit BoundingBoxes_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _bounding_boxes_type =
    std::vector<perception_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<perception_interfaces::msg::BoundingBox_<ContainerAllocator>>>;
  _bounding_boxes_type bounding_boxes;

  // setters for named parameter idiom
  Type & set__bounding_boxes(
    const std::vector<perception_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<perception_interfaces::msg::BoundingBox_<ContainerAllocator>>> & _arg)
  {
    this->bounding_boxes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_interfaces__msg__BoundingBoxes
    std::shared_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_interfaces__msg__BoundingBoxes
    std::shared_ptr<perception_interfaces::msg::BoundingBoxes_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoundingBoxes_ & other) const
  {
    if (this->bounding_boxes != other.bounding_boxes) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoundingBoxes_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoundingBoxes_

// alias to use template instance with default allocator
using BoundingBoxes =
  perception_interfaces::msg::BoundingBoxes_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_
