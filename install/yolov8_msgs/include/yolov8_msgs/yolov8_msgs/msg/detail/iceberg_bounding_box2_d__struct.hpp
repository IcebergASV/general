// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/IcebergBoundingBox2D.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__IcebergBoundingBox2D __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__IcebergBoundingBox2D __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IcebergBoundingBox2D_
{
  using Type = IcebergBoundingBox2D_<ContainerAllocator>;

  explicit IcebergBoundingBox2D_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->xmin = 0;
      this->ymin = 0;
      this->xmax = 0;
      this->ymax = 0;
    }
  }

  explicit IcebergBoundingBox2D_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->xmin = 0;
      this->ymin = 0;
      this->xmax = 0;
      this->ymax = 0;
    }
  }

  // field types and members
  using _xmin_type =
    uint16_t;
  _xmin_type xmin;
  using _ymin_type =
    uint16_t;
  _ymin_type ymin;
  using _xmax_type =
    uint16_t;
  _xmax_type xmax;
  using _ymax_type =
    uint16_t;
  _ymax_type ymax;

  // setters for named parameter idiom
  Type & set__xmin(
    const uint16_t & _arg)
  {
    this->xmin = _arg;
    return *this;
  }
  Type & set__ymin(
    const uint16_t & _arg)
  {
    this->ymin = _arg;
    return *this;
  }
  Type & set__xmax(
    const uint16_t & _arg)
  {
    this->xmax = _arg;
    return *this;
  }
  Type & set__ymax(
    const uint16_t & _arg)
  {
    this->ymax = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__IcebergBoundingBox2D
    std::shared_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__IcebergBoundingBox2D
    std::shared_ptr<yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IcebergBoundingBox2D_ & other) const
  {
    if (this->xmin != other.xmin) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->xmax != other.xmax) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    return true;
  }
  bool operator!=(const IcebergBoundingBox2D_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IcebergBoundingBox2D_

// alias to use template instance with default allocator
using IcebergBoundingBox2D =
  yolov8_msgs::msg::IcebergBoundingBox2D_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__STRUCT_HPP_
