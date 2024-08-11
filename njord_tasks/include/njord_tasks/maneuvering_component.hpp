#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include "njord_tasks_interfaces/msg/start_task.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "yolov8_msgs/msg/detection_array.hpp"
#include <string>
#include <chrono>
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <Eigen/Dense>

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace njord_tasks
{

class Maneuvering : public rclcpp::Node
{
public:
    explicit Maneuvering(const rclcpp::NodeOptions & options);

private:
    void taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg);
    void localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    void timerCallback();
    void bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg);
    void sendFinishPnt();
    void wait();
    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg);
    std::vector<yolov8_msgs::msg::Detection> filterAndSortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array, const std::string& class_name);
    void getWPFromBuoys(geometry_msgs::msg::PoseStamped& wp);
    bool hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array);


    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<njord_tasks_interfaces::msg::StartTask>::SharedPtr task_to_execute_sub_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr task_completion_status_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr global_pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr local_pose_sub_;
    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr bbox_sub_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_wp_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_wp_pub_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_sub_;

    double p_distance_to_move_;
    double p_angle_from_buoys_;
    double p_wp_reached_radius_;
    int p_camera_res_x_;
    int p_camera_fov_;
    double p_wait_time_;
    int p_testing_angles_;
    double p_test_angle_;

    const std::string red_buoy_str_ = "red_buoy";
    const std::string green_buoy_str_ = "green_buoy";

    enum States {CHECK_FOR_BUOYS, HEAD_TO_FINISH, MANEUVER}; 
    States status_;

    sensor_msgs::msg::NavSatFix current_global_pose_;
    geometry_msgs::msg::PoseStamped current_local_pose_;
    geographic_msgs::msg::GeoPoint finish_pnt_;
    yolov8_msgs::msg::DetectionArray bboxes_;

    bool global_pose_updated_;
    bool local_pose_updated_;
    bool bboxes_updated_;
    bool start_task_;
    bool wp_reached_;

    template <typename T>
    void getParam(std::string param_name, T& param, T default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<T>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + std::to_string(param);
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

      return;
    }
};

} // namespace njord_tasks

#endif // maneuvering_HPP
