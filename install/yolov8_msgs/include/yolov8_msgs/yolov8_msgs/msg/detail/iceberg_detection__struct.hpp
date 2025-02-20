// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/IcebergDetection.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bbox'
#include "yolov8_msgs/msg/detail/iceberg_bounding_box2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__IcebergDetection __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__IcebergDetection __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IcebergDetection_
{
  using Type = IcebergDetection_<ContainerAllocator>;

  explicit IcebergDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->class_name = "";
      this->score = 0.0;
    }
  }

  explicit IcebergDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc),
    bbox(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->class_name = "";
      this->score = 0.0;
    }
  }

  // field types and members
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _score_type =
    double;
  _score_type score;
  using _bbox_type =
    yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator>;
  _bbox_type bbox;

  // setters for named parameter idiom
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__score(
    const double & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__bbox(
    const yolov8_msgs::msg::IcebergBoundingBox2D_<ContainerAllocator> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__IcebergDetection
    std::shared_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__IcebergDetection
    std::shared_ptr<yolov8_msgs::msg::IcebergDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IcebergDetection_ & other) const
  {
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    return true;
  }
  bool operator!=(const IcebergDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IcebergDetection_

// alias to use template instance with default allocator
using IcebergDetection =
  yolov8_msgs::msg::IcebergDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_HPP_
