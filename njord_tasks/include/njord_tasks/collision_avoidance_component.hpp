#ifndef collision_avoidance_HPP
#define collision_avoidance_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "mavros_msgs/srv/set_mode.hpp"
#include <mavros_msgs/msg/state.hpp>
#include <chrono>
#include <string>
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "njord_tasks_interfaces/msg/start_task.hpp"
#include "slg_msgs/msg/segment_array.hpp"
#include "slg_msgs/msg/segment.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "slg_msgs/segment2D.hpp"
#include "std_msgs/msg/color_rgba.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace njord_tasks
{

class CollisionAvoidance : public rclcpp::Node
{
public:
    explicit CollisionAvoidance(const rclcpp::NodeOptions & options);

private:
    void taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);
    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg);
    void sendFinishPnt();
    void laserSegmentCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg);
    rclcpp::Subscription<slg_msgs::msg::SegmentArray>::SharedPtr laser_segments_sub_;
    rclcpp::Subscription<njord_tasks_interfaces::msg::StartTask>::SharedPtr task_to_execute_sub_;
    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    rclcpp::Client<mavros_msgs::srv::SetMode>::SharedPtr set_mode_client_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_wp_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr obstacle_viz_points_pub_;

    double p_finish_lat_;
    double p_finish_lon_;
    double p_min_dist_;
    double p_max_dist_;
    double p_fov_;
    double p_obstacle_length_;
    double p_obstacle_length_range_;
    int p_mode_when_obstacles_;

    bool in_guided_;
    bool start_task_;
    bool obstacles_;
    bool prev_in_loiter_;

    enum States {CHECK_FOR_OBSTACLES, LOITER, SEND_FINISH_PNT}; 
    States status_;

    void change_mode();
    void change_mode(const std::string &mode);
    void timerCallback();
    std::string getModeString(int mode);

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

#endif // collision_avoidance_HPP
