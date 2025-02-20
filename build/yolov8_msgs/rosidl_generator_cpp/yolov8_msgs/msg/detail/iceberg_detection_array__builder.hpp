// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/IcebergDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/iceberg_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_IcebergDetectionArray_icebergdetections
{
public:
  explicit Init_IcebergDetectionArray_icebergdetections(::yolov8_msgs::msg::IcebergDetectionArray & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::IcebergDetectionArray icebergdetections(::yolov8_msgs::msg::IcebergDetectionArray::_icebergdetections_type arg)
  {
    msg_.icebergdetections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetectionArray msg_;
};

class Init_IcebergDetectionArray_header
{
public:
  Init_IcebergDetectionArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IcebergDetectionArray_icebergdetections header(::yolov8_msgs::msg::IcebergDetectionArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IcebergDetectionArray_icebergdetections(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::IcebergDetectionArray>()
{
  return yolov8_msgs::msg::builder::Init_IcebergDetectionArray_header();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__BUILDER_HPP_
