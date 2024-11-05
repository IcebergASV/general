#ifndef maneuvering_HPP
#define maneuvering_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include "comp_tasks_interfaces/msg/start_task.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "yolov8_msgs/msg/detection_array.hpp"
#include <string>
#include <chrono>
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "mavros_msgs/msg/state.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace comp_tasks
{

class Maneuvering : public rclcpp::Node
{
public:
    explicit Maneuvering(const rclcpp::NodeOptions & options);

private:
    void taskToExecuteCallback(const comp_tasks_interfaces::msg::StartTask::SharedPtr msg);
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg);
    void localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    void timerCallback();
    void bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg);
    void sendFinishPnt();
    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg);
    std::vector<yolov8_msgs::msg::Detection> filterAndSortLeftToRight(const yolov8_msgs::msg::DetectionArray detection_array, const std::string& class_name1, const std::string& class_name2);
    bool hasDesiredDetections(const yolov8_msgs::msg::DetectionArray& detection_array);
    void setTimerDuration(double duration);
    void onTimerExpired();
    void publishBehaviourStatus(std::string str_msg);
    void publishSearchStatus(std::string str_msg);
    void executeRecoveryBehaviour();
    void publishWPTowardsDetections(const yolov8_msgs::msg::DetectionArray& detections);
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections);

    rclcpp::Subscription<comp_tasks_interfaces::msg::StartTask>::SharedPtr task_to_execute_sub_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr task_completion_status_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr global_pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr local_pose_sub_;
    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr bbox_sub_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_wp_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_wp_pub_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_logger_pub_;
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;

    rclcpp::TimerBase::SharedPtr timer_;


    double p_distance_to_move_;
    double p_angle_from_target_;
    int p_camera_res_x_;
    int p_camera_fov_;
    double p_finish_lat_;
    double p_finish_lon_;
    std::string p_recovery_behaviour_;
    std::string p_bbox_selection_;
    std::string p_red_buoy_str_;
    std::string p_green_buoy_str_;
    std::string p_second_red_buoy_str_;
    std::string p_second_green_buoy_str_;
    double p_time_to_stop_before_recovery_;
    double p_time_to_pause_search_;
    double p_time_between_recovery_actions_;
    int p_frame_stack_size_;

    std::vector<std::reference_wrapper<std::string>> target_class_names_;

    enum States {STOPPED, RECOVERING, HEADING_TO_TARGET }; 
    States status_;

    sensor_msgs::msg::NavSatFix current_global_pose_;
    geometry_msgs::msg::PoseStamped current_local_pose_;
    geographic_msgs::msg::GeoPoint finish_pnt_;
    yolov8_msgs::msg::DetectionArray stacked_detections_;

    bool global_pose_updated_;
    bool local_pose_updated_;
    bool bboxes_updated_;
    bool start_task_;
    bool wp_reached_;
    bool timer_expired_;
    int wp_cnt_;
    int detection_frame_cnt_;
    bool in_guided_;

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

    void getStringParam(std::string param_name, std::string& param, std::string default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<std::string>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + param;
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 
      return;
    }

};

} // namespace comp_tasks

#endif // maneuvering_HPP
