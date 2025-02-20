// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/IcebergBoundingBox2D.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/iceberg_bounding_box2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_IcebergBoundingBox2D_ymax
{
public:
  explicit Init_IcebergBoundingBox2D_ymax(::yolov8_msgs::msg::IcebergBoundingBox2D & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::IcebergBoundingBox2D ymax(::yolov8_msgs::msg::IcebergBoundingBox2D::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergBoundingBox2D msg_;
};

class Init_IcebergBoundingBox2D_xmax
{
public:
  explicit Init_IcebergBoundingBox2D_xmax(::yolov8_msgs::msg::IcebergBoundingBox2D & msg)
  : msg_(msg)
  {}
  Init_IcebergBoundingBox2D_ymax xmax(::yolov8_msgs::msg::IcebergBoundingBox2D::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_IcebergBoundingBox2D_ymax(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergBoundingBox2D msg_;
};

class Init_IcebergBoundingBox2D_ymin
{
public:
  explicit Init_IcebergBoundingBox2D_ymin(::yolov8_msgs::msg::IcebergBoundingBox2D & msg)
  : msg_(msg)
  {}
  Init_IcebergBoundingBox2D_xmax ymin(::yolov8_msgs::msg::IcebergBoundingBox2D::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_IcebergBoundingBox2D_xmax(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergBoundingBox2D msg_;
};

class Init_IcebergBoundingBox2D_xmin
{
public:
  Init_IcebergBoundingBox2D_xmin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IcebergBoundingBox2D_ymin xmin(::yolov8_msgs::msg::IcebergBoundingBox2D::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_IcebergBoundingBox2D_ymin(msg_);
  }

private:
  ::yolov8_msgs::msg::IcebergBoundingBox2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::IcebergBoundingBox2D>()
{
  return yolov8_msgs::msg::builder::Init_IcebergBoundingBox2D_xmin();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_BOUNDING_BOX2_D__BUILDER_HPP_
