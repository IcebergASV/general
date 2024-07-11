// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_interfaces:msg/Prop.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__PROP__STRUCT_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__PROP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_interfaces__msg__Prop __attribute__((deprecated))
#else
# define DEPRECATED__perception_interfaces__msg__Prop __declspec(deprecated)
#endif

namespace perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Prop_
{
  using Type = Prop_<ContainerAllocator>;

  explicit Prop_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->label = "";
      this->radius = 0.0f;
      this->probability = 0.0f;
    }
  }

  explicit Prop_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc),
    point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->label = "";
      this->radius = 0.0f;
      this->probability = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;
  using _radius_type =
    float;
  _radius_type radius;
  using _probability_type =
    float;
  _probability_type probability;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__radius(
    const float & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__probability(
    const float & _arg)
  {
    this->probability = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_interfaces::msg::Prop_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_interfaces::msg::Prop_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_interfaces::msg::Prop_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_interfaces::msg::Prop_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::Prop_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::Prop_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_interfaces::msg::Prop_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_interfaces::msg::Prop_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_interfaces::msg::Prop_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_interfaces::msg::Prop_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_interfaces__msg__Prop
    std::shared_ptr<perception_interfaces::msg::Prop_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_interfaces__msg__Prop
    std::shared_ptr<perception_interfaces::msg::Prop_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Prop_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    if (this->probability != other.probability) {
      return false;
    }
    return true;
  }
  bool operator!=(const Prop_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Prop_

// alias to use template instance with default allocator
using Prop =
  perception_interfaces::msg::Prop_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__PROP__STRUCT_HPP_
