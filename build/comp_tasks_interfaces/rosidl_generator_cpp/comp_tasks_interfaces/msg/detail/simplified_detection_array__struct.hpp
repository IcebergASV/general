// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_HPP_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'detections'
#include "comp_tasks_interfaces/msg/detail/simplified_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetectionArray __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetectionArray __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SimplifiedDetectionArray_
{
  using Type = SimplifiedDetectionArray_<ContainerAllocator>;

  explicit SimplifiedDetectionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SimplifiedDetectionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _detections_type =
    std::vector<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const std::vector<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<comp_tasks_interfaces::msg::SimplifiedDetection_<ContainerAllocator>>> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetectionArray
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__msg__SimplifiedDetectionArray
    std::shared_ptr<comp_tasks_interfaces::msg::SimplifiedDetectionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SimplifiedDetectionArray_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const SimplifiedDetectionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SimplifiedDetectionArray_

// alias to use template instance with default allocator
using SimplifiedDetectionArray =
  comp_tasks_interfaces::msg::SimplifiedDetectionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_HPP_
