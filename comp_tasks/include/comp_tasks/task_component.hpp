#ifndef task_HPP
#define task_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/bool.hpp>
#include "comp_tasks_interfaces/msg/start_task.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "yolov8_msgs/msg/detection_array.hpp"
#include <string>
#include <chrono>
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include <fstream>
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <lifecycle_msgs/msg/state.hpp>
#include "comp_tasks_interfaces/msg/label_int.hpp"
#include "comp_tasks_interfaces/msg/wp_info.hpp"
#include "comp_tasks_interfaces/msg/global_wp_info.hpp"
#include "comp_tasks_interfaces/msg/wp_group_info.hpp"
#include "comp_tasks_interfaces/msg/named_local_wp.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace comp_tasks
{

class Task : public rclcpp_lifecycle::LifecycleNode
{
public:
    explicit Task(const rclcpp::NodeOptions & options, std::string node_name = "task");

protected:
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);
    virtual rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void globalPoseCallback(const sensor_msgs::msg::NavSatFix::SharedPtr msg);
    void localPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    void timerCallback();
    void bboxCallback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg);
    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg);
    void publishFinishPoint();
    void publishRecoveryPoint();
    void publishStartPoint();
    void publishBehaviourStatus(std::string str_msg);
    void publishSearchStatus(std::string str_msg);
    void publishStateStatus(std::string str_msg);
    geometry_msgs::msg::Point publishWPTowardsBlackBuoyGate(const yolov8_msgs::msg::DetectionArray& detections);
    geometry_msgs::msg::Point publishWPTowardsGate(const yolov8_msgs::msg::DetectionArray& detections);
    geometry_msgs::msg::PoseStamped publishWPTowardsLargestTarget(const yolov8_msgs::msg::DetectionArray& detections, std::string target_label, double angle);
    geometry_msgs::msg::PoseStamped getWPTowardsLargestTarget(const yolov8_msgs::msg::DetectionArray& detections, std::string target_label, double offset_angle, double dist);
    void publishGlobalWP(double lat, double lon, std::string type = "");
    void publishLocalWP(double x, double y);
    void setTimerDuration(double duration, std::string timer_name);
    void onTimerExpired();
    bool isActive();
    virtual void executeRecoveryBehaviour();
    void signalTaskFinish(); // TODO
    void setReturnToHomePnt();

    void updateYamlParamForDiffNode(const std::string &paramName, double newValue, std::string node_name, std::string filename);
    virtual void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) = 0;
    virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State &);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State &);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State &);
    void publishDynamicWPInfo(double x, double y, const yolov8_msgs::msg::DetectionArray& detections);
    void publishGlobalWPInfo(double lat, double lon, std::string wp_type);
    void publishWpGroupInfo(std::vector<geometry_msgs::msg::Point> wps,const yolov8_msgs::msg::DetectionArray& detections, std::string group_name);
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr global_pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr local_pose_sub_;
    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr bbox_sub_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_wp_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_wp_pub_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_logger_pub_;
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr task_complete_pub_;
    rclcpp::Publisher<comp_tasks_interfaces::msg::LabelInt>::SharedPtr timer_cntdwn_pub_;
    rclcpp::Publisher<comp_tasks_interfaces::msg::WpInfo>::SharedPtr wp_info_pub_;
    rclcpp::Publisher<comp_tasks_interfaces::msg::GlobalWpInfo>::SharedPtr global_wp_info_pub_;
    rclcpp::Publisher<comp_tasks_interfaces::msg::WpGroupInfo>::SharedPtr wp_group_info_pub_;
  
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr countdown_timer_;

    double p_distance_to_move_;
    double p_angle_from_target_;
    int p_camera_res_x_;
    int p_camera_fov_;
    double p_finish_lat_;
    double p_finish_lon_;
    double p_recovery_lat_;
    double p_recovery_lon_;
    double p_start_lat_;
    double p_start_lon_; 
    std::string p_recovery_behaviour_;
    std::string p_bbox_selection_;
    std::string p_red_buoy_str_;
    std::string p_green_buoy_str_;
    std::string p_blue_buoy_str_;
    std::string p_second_blue_buoy_str_;
    std::string p_second_red_buoy_str_;
    std::string p_second_green_buoy_str_;
    std::string p_black_buoy_str_;
    int p_frame_stack_size_;
    double p_time_to_pause_search_;
    double p_target_offset_;

    std::vector<std::reference_wrapper<std::string>> target_class_names_;

    sensor_msgs::msg::NavSatFix current_global_pose_;
    geometry_msgs::msg::PoseStamped current_local_pose_;
    yolov8_msgs::msg::DetectionArray stacked_detections_;

    bool bboxes_updated_;
    bool wp_reached_;
    bool timer_expired_;
    int wp_cnt_;
    int detection_frame_cnt_;
    bool in_guided_;
    bool in_hold_;
    bool in_manual_;
    bool activated_;
    std::string timer_name_;
    std::string node_state_;

    int remaining_time_;

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

    template <typename T>
    void updateYamlParam(const std::string &paramName, T newValue) {
      if (isActive()){
        try {
            std::string nodeName = "/" + std::string(this->get_name());
            std::filesystem::path current_file(__FILE__); 
            std::filesystem::path package_path = current_file.parent_path().parent_path().parent_path();

            std::string file_path = package_path.string() + "/config/params.yaml";

            // Load the YAML file
            YAML::Node config = YAML::LoadFile(file_path);
      
            // Check if the node and parameter exist
            if (!config[nodeName]) {
                std::cerr << "Error: Node " << nodeName << " not found in YAML file." << std::endl;
                return;
            }

            // Check if the node and parameter exist
            if (!config[nodeName] || !config[nodeName]["ros__parameters"] || !config[nodeName]["ros__parameters"][paramName]) {
                std::cerr << "Error: Parameter " << paramName << " not found in YAML file." << std::endl;
                return;
            }
      
              // Update the parameter value
            if constexpr (std::is_same_v<T, double>) {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(3) << newValue;
                config[nodeName]["ros__parameters"][paramName] = oss.str();
            } else {
                config[nodeName]["ros__parameters"][paramName] = newValue;
            }
      
            // Write back to file
            std::ofstream outFile(file_path);
            if (!outFile) {
                std::cerr << "Error: Unable to open file for writing." << std::endl;
                return;
            }
            outFile << config;
            outFile.close();
      
            std::cout << "Successfully updated " << paramName << " to "<< newValue << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
      }
    }

};

} // namespace comp_tasks

#endif // task_HPP
