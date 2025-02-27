#include "comp_tasks/buoy_counter_component.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

namespace comp_tasks
{
  BuoyCounter::BuoyCounter(const rclcpp::NodeOptions & options) : Node("buoy_counter", options)
  {
    declare_parameter<double>("exclusion_radius", 5.0);
    exclusion_radius_ = get_parameter("exclusion_radius").as_double();

    declare_parameter<std::string>("desired_class", "yellow_buoy");
    desired_class_ = get_parameter("desired_class").as_string();

    rclcpp::QoS qos(10);
    detection_sub_ = create_subscription<yolov8_msgs::msg::DetectionArray>(
        "/yolov8/detections", qos, std::bind(&BuoyCounter::detection_callback, this, std::placeholders::_1));
    global_pose_sub_ = create_subscription<sensor_msgs::msg::NavSatFix>(
        "/mavros/global_position/global", qos, std::bind(&BuoyCounter::globalPoseCallback, this, std::placeholders::_1));
    local_pose_sub_ = create_subscription<geometry_msgs::msg::PoseStamped>(
        "/mavros/local_position/pose", qos, std::bind(&BuoyCounter::localPoseCallback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult BuoyCounter::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    for (const auto &param : params) {
        if (param.get_name() == "exclusion_radius") {
            exclusion_radius_ = param.as_double();
        } else if (param.get_name() == "desired_class") {
            desired_class_ = param.as_string();
        }
    }
    return result;
  }

  void BuoyCounter::detection_callback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
  {
    if (msg->detections.empty()) {
        RCLCPP_DEBUG(this->get_logger(), "Received empty detections array");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Received %zu detections", msg->detections.size());
    for (const auto &detection : msg->detections) {
        RCLCPP_DEBUG(this->get_logger(), "Class ID: %s, Score: %.2f", detection.class_name.c_str(), detection.score);
        auto &bbox = detection.bbox;
        RCLCPP_DEBUG(this->get_logger(), 
            "BBox: [x: %.2f, y: %.2f, w: %.2f, h: %.2f]",
            bbox.center.position.x, bbox.center.position.y, bbox.size.x, bbox.size.y);

        if (detection.score > 0.5 && detection.class_name == desired_class_) {
            RCLCPP_INFO(this->get_logger(), "High confidence detection: %s (%.2f)",
                detection.class_name.c_str(), detection.score);

            float pix_width = bbox.size.x;
            float distance_m = 64 - pix_width / 10;

            geometry_msgs::msg::PoseStamped::SharedPtr local_pose;
            {
                std::lock_guard<std::mutex> lock(pose_mutex_);
                local_pose = current_local_pose_;
            }
            tf2::Quaternion o(
                local_pose->pose.orientation.x,
                local_pose->pose.orientation.y,
                local_pose->pose.orientation.z,
                local_pose->pose.orientation.w
            );

            tf2::Matrix3x3 rotation_mat(o);
            double cam_x = local_pose->pose.position.x;
            double cam_y = local_pose->pose.position.y;
            double cam_z = local_pose->pose.position.z;

            tf2::Vector3 obj_camera_frame(0, 0, distance_m);
            tf2::Vector3 obj_world_frame = rotation_mat * obj_camera_frame;

            const double world_x = cam_x + obj_world_frame.getX();
            const double world_y = cam_y + obj_world_frame.getY();
            const double world_z = cam_z + obj_world_frame.getZ();

            bool is_near_existing = false;

            {
                std::lock_guard<std::mutex> lock(buoy_mutex_);
                for (const auto &buoy : known_buoys_) {
                    const double dx = world_x - buoy.x;
                    const double dy = world_y - buoy.y;
                    const double dz = world_z - buoy.z;
                    const double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
                    if (distance < exclusion_radius_) {
                        is_near_existing = true;
                        break;
                    }
                }
            }

            if (!is_near_existing) {
                geometry_msgs::msg::Point new_buoy;
                new_buoy.x = world_x;
                new_buoy.y = world_y;
                new_buoy.z = world_z;
                {
                    std::lock_guard<std::mutex> lock(buoy_mutex_);
                    known_buoys_.push_back(new_buoy);
                }
                RCLCPP_INFO(this->get_logger(), 
                    "New buoy detected at: X: %.2fm, Y: %.2fm, Z: %.2fm (Distance: %.2fm)",
                    world_x, world_y, world_z, distance_m);
            }
            
            else {
                RCLCPP_DEBUG(this->get_logger(), 
                    "Ignored buoy in exclusion zone at: X: %.2fm, Y: %.2fm", world_x, world_y);
            }
        }
    }
  }

void BuoyCounter::globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(pose_mutex_);
    current_global_pose_ = *msg;
    RCLCPP_DEBUG(this->get_logger(), "Latitude: %f, Longitude: %f", 
        current_global_pose_.latitude, current_global_pose_.longitude);
}

void BuoyCounter::localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(pose_mutex_);
    current_local_pose_ = msg; // Assign SharedPtr directly
    RCLCPP_DEBUG(this->get_logger(), "Local Pose: x: %f, y: %f", 
        msg->pose.position.x, msg->pose.position.y);
}
} // namespace comp_tasks