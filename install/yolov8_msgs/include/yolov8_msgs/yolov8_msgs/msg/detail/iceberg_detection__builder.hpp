// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/IcebergDetection.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/iceberg_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_IcebergDetection_bbox
{
public:
  explicit Init_IcebergDetection_bbox(::yolov8_msgs::msg::IcebergDetection & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::IcebergDetection bbox(::yolov8_msgs::msg::IcebergDetection::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetection msg_;
};

class Init_IcebergDetection_score
{
public:
  explicit Init_IcebergDetection_score(::yolov8_msgs::msg::IcebergDetection & msg)
  : msg_(msg)
  {}
  Init_IcebergDetection_bbox score(::yolov8_msgs::msg::IcebergDetection::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_IcebergDetection_bbox(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetection msg_;
};

class Init_IcebergDetection_class_name
{
public:
  explicit Init_IcebergDetection_class_name(::yolov8_msgs::msg::IcebergDetection & msg)
  : msg_(msg)
  {}
  Init_IcebergDetection_score class_name(::yolov8_msgs::msg::IcebergDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_IcebergDetection_score(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetection msg_;
};

class Init_IcebergDetection_class_id
{
public:
  Init_IcebergDetection_class_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IcebergDetection_class_name class_id(::yolov8_msgs::msg::IcebergDetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_IcebergDetection_class_name(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::IcebergDetection>()
{
  return yolov8_msgs::msg::builder::Init_IcebergDetection_class_id();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__BUILDER_HPP_
