// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_interfaces__msg__LidarDetectedProp __attribute__((deprecated))
#else
# define DEPRECATED__perception_interfaces__msg__LidarDetectedProp __declspec(deprecated)
#endif

namespace perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarDetectedProp_
{
  using Type = LidarDetectedProp_<ContainerAllocator>;

  explicit LidarDetectedProp_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->radius = 0.0f;
      this->radius_diff = 0.0f;
    }
  }

  explicit LidarDetectedProp_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc),
    center(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->radius = 0.0f;
      this->radius_diff = 0.0f;
    }
  }

  // field types and members
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_type center;
  using _radius_type =
    float;
  _radius_type radius;
  using _radius_diff_type =
    float;
  _radius_diff_type radius_diff;

  // setters for named parameter idiom
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__radius(
    const float & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__radius_diff(
    const float & _arg)
  {
    this->radius_diff = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_interfaces__msg__LidarDetectedProp
    std::shared_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_interfaces__msg__LidarDetectedProp
    std::shared_ptr<perception_interfaces::msg::LidarDetectedProp_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarDetectedProp_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    if (this->radius_diff != other.radius_diff) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarDetectedProp_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarDetectedProp_

// alias to use template instance with default allocator
using LidarDetectedProp =
  perception_interfaces::msg::LidarDetectedProp_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_HPP_
