// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/IcebergDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_HPP_

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
// Member 'icebergdetections'
#include "yolov8_msgs/msg/detail/iceberg_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__IcebergDetectionArray __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__IcebergDetectionArray __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IcebergDetectionArray_
{
  using Type = IcebergDetectionArray_<ContainerAllocator>;

  explicit IcebergDetectionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit IcebergDetectionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _icebergdetections_type =
    std::vector<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>>;
  _icebergdetections_type icebergdetections;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__icebergdetections(
    const std::vector<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>> & _arg)
  {
    this->icebergdetections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__IcebergDetectionArray
    std::shared_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__IcebergDetectionArray
    std::shared_ptr<yolov8_msgs::msg::IcebergDetectionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IcebergDetectionArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->icebergdetections != other.icebergdetections) {
      return false;
    }
    return true;
  }
  bool operator!=(const IcebergDetectionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IcebergDetectionArray_

// alias to use template instance with default allocator
using IcebergDetectionArray =
  yolov8_msgs::msg::IcebergDetectionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_HPP_
