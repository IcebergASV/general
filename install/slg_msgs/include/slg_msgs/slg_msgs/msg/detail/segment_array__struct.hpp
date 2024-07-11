// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'segments'
#include "slg_msgs/msg/detail/segment__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slg_msgs__msg__SegmentArray __attribute__((deprecated))
#else
# define DEPRECATED__slg_msgs__msg__SegmentArray __declspec(deprecated)
#endif

namespace slg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SegmentArray_
{
  using Type = SegmentArray_<ContainerAllocator>;

  explicit SegmentArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit SegmentArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _segments_type =
    std::vector<slg_msgs::msg::Segment_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<slg_msgs::msg::Segment_<ContainerAllocator>>>;
  _segments_type segments;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__segments(
    const std::vector<slg_msgs::msg::Segment_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<slg_msgs::msg::Segment_<ContainerAllocator>>> & _arg)
  {
    this->segments = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slg_msgs::msg::SegmentArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const slg_msgs::msg::SegmentArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slg_msgs::msg::SegmentArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slg_msgs::msg::SegmentArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slg_msgs__msg__SegmentArray
    std::shared_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slg_msgs__msg__SegmentArray
    std::shared_ptr<slg_msgs::msg::SegmentArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SegmentArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->segments != other.segments) {
      return false;
    }
    return true;
  }
  bool operator!=(const SegmentArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SegmentArray_

// alias to use template instance with default allocator
using SegmentArray =
  slg_msgs::msg::SegmentArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace slg_msgs

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_HPP_
