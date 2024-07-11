// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/lidar_detected_prop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_LidarDetectedProp_radius_diff
{
public:
  explicit Init_LidarDetectedProp_radius_diff(::perception_interfaces::msg::LidarDetectedProp & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::LidarDetectedProp radius_diff(::perception_interfaces::msg::LidarDetectedProp::_radius_diff_type arg)
  {
    msg_.radius_diff = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::LidarDetectedProp msg_;
};

class Init_LidarDetectedProp_radius
{
public:
  explicit Init_LidarDetectedProp_radius(::perception_interfaces::msg::LidarDetectedProp & msg)
  : msg_(msg)
  {}
  Init_LidarDetectedProp_radius_diff radius(::perception_interfaces::msg::LidarDetectedProp::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_LidarDetectedProp_radius_diff(msg_);
  }

private:
  ::perception_interfaces::msg::LidarDetectedProp msg_;
};

class Init_LidarDetectedProp_center
{
public:
  explicit Init_LidarDetectedProp_center(::perception_interfaces::msg::LidarDetectedProp & msg)
  : msg_(msg)
  {}
  Init_LidarDetectedProp_radius center(::perception_interfaces::msg::LidarDetectedProp::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_LidarDetectedProp_radius(msg_);
  }

private:
  ::perception_interfaces::msg::LidarDetectedProp msg_;
};

class Init_LidarDetectedProp_label
{
public:
  Init_LidarDetectedProp_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarDetectedProp_center label(::perception_interfaces::msg::LidarDetectedProp::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_LidarDetectedProp_center(msg_);
  }

private:
  ::perception_interfaces::msg::LidarDetectedProp msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::LidarDetectedProp>()
{
  return perception_interfaces::msg::builder::Init_LidarDetectedProp_label();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__BUILDER_HPP_
