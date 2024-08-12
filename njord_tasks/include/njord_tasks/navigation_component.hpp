#ifndef navigation_HPP
#define navigation_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <chrono>
#include "njord_tasks_interfaces/action/task_signal.hpp"
#include "njord_tasks_interfaces/msg/start_task.hpp"
#include "njord_tasks_interfaces/msg/task.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
namespace njord_tasks
{

class navigation : public rclcpp::Node
{
public:
    explicit navigation(const rclcpp::NodeOptions & options);

private:
    void callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg);
    void timerCallback();
    void wpReachedCallback(const std_msgs::msg::Int32::SharedPtr msg);

    rclcpp::TimerBase::SharedPtr timer_;
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    rclcpp::Subscription<njord_tasks_interfaces::msg::StartTask>::SharedPtr example_sub_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr wp_reached_sub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    bool wp_reached_;

    enum States {WAIT_FOR_START, START_TASK, GOING_TO_WAYPOINT, REACHED_WAYPOINT, GOING_TO_FINISH, COMPLETE}; 
    States status_ = States::WAIT_FOR_START;

    double start_lat;
    double start_lon;

    double finish_lat;
    double finish_lon;

    geographic_msgs::msg::GeoPoseStamped current_point;
    std::vector<double> point_list_1D;
    std::vector<std::vector<double>> point_list_2D;

    int32_t number_of_points;
    int32_t index_of_current_point;

    template <typename T>
    void getParam(std::string param_name, T& param, T default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<T>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      // std::string param_log_output = param_name + ": " + std::to_string(param);
      //RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

      return;
    }

    std::vector<std::vector<double>> convertTo2DList(const std::vector<double>& input_list) {
      std::vector<std::vector<double>> output_list;

      // Check if the input list has an even number of elements
      if (input_list.size() % 2 != 0) {
          throw std::invalid_argument("Input list must contain an even number of elements.");
      }

      for (size_t i = 0; i < input_list.size(); i += 2) {
          output_list.push_back({input_list[i], input_list[i + 1]});
      }

    return output_list;
    }

};

} // namespace njord_tasks

#endif // navigation_HPP
