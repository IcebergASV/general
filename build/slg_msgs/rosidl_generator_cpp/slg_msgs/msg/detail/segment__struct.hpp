// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'last_point_prior_segment'
// Member 'first_point_next_segment'
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slg_msgs__msg__Segment __attribute__((deprecated))
#else
# define DEPRECATED__slg_msgs__msg__Segment __declspec(deprecated)
#endif

namespace slg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Segment_
{
  using Type = Segment_<ContainerAllocator>;

  explicit Segment_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : last_point_prior_segment(_init),
    first_point_next_segment(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->id = 0ull;
      this->label = 0ul;
      this->angular_distance = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->id = 0ull;
      this->label = 0ul;
      this->angular_distance = 0.0;
    }
  }

  explicit Segment_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : last_point_prior_segment(_alloc, _init),
    first_point_next_segment(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->id = 0ull;
      this->label = 0ul;
      this->angular_distance = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->id = 0ull;
      this->label = 0ul;
      this->angular_distance = 0.0;
    }
  }

  // field types and members
  using _id_type =
    uint64_t;
  _id_type id;
  using _label_type =
    uint32_t;
  _label_type label;
  using _angular_distance_type =
    double;
  _angular_distance_type angular_distance;
  using _last_point_prior_segment_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _last_point_prior_segment_type last_point_prior_segment;
  using _first_point_next_segment_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _first_point_next_segment_type first_point_next_segment;
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__id(
    const uint64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__label(
    const uint32_t & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__angular_distance(
    const double & _arg)
  {
    this->angular_distance = _arg;
    return *this;
  }
  Type & set__last_point_prior_segment(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->last_point_prior_segment = _arg;
    return *this;
  }
  Type & set__first_point_next_segment(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->first_point_next_segment = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t BACKGROUND =
    0u;
  static constexpr uint32_t PERSON =
    1u;
  static constexpr uint32_t PERSON_CANE =
    2u;
  static constexpr uint32_t PERSON_WHEEL_CHAIR =
    3u;

  // pointer types
  using RawPtr =
    slg_msgs::msg::Segment_<ContainerAllocator> *;
  using ConstRawPtr =
    const slg_msgs::msg::Segment_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slg_msgs::msg::Segment_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slg_msgs::msg::Segment_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slg_msgs::msg::Segment_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slg_msgs::msg::Segment_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slg_msgs::msg::Segment_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slg_msgs::msg::Segment_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slg_msgs::msg::Segment_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slg_msgs::msg::Segment_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slg_msgs__msg__Segment
    std::shared_ptr<slg_msgs::msg::Segment_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slg_msgs__msg__Segment
    std::shared_ptr<slg_msgs::msg::Segment_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Segment_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->angular_distance != other.angular_distance) {
      return false;
    }
    if (this->last_point_prior_segment != other.last_point_prior_segment) {
      return false;
    }
    if (this->first_point_next_segment != other.first_point_next_segment) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Segment_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Segment_

// alias to use template instance with default allocator
using Segment =
  slg_msgs::msg::Segment_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Segment_<ContainerAllocator>::BACKGROUND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Segment_<ContainerAllocator>::PERSON;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Segment_<ContainerAllocator>::PERSON_CANE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Segment_<ContainerAllocator>::PERSON_WHEEL_CHAIR;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace slg_msgs

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_HPP_
