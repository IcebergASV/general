// #ifndef velocity_sender_HPP
// #define velocity_sender_HPP

// #include "rclcpp/rclcpp.hpp"
// #include "mavros_msgs/msg/state.hpp"
// #include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
// #include <tf2/LinearMath/Quaternion.h>

// using std::placeholders::_1;

// namespace velocity_sender
// {

// class VelocitySender : public rclcpp::Node
// {
// public:
//     explicit VelocitySender(const rclcpp::NodeOptions & options);

// private:
//     void pixhawkStateCallback(const mavros_msgs::msg::State::SharedPtr msg);
//     // rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

//     rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr pixhawk_state_sub_;
//     // rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr example_pub_;
//     // rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

//     bool in_guided_;
//     bool previous_guided_state_;

//     // template <typename T>
//     // void getParam(std::string param_name, T& param, T default_value, std::string desc)
//     // {
//     //   auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
//     //   param_desc.description = desc;
//     //   this->declare_parameter<T>(param_name, default_value, param_desc);
//     //   this->get_parameter(param_name, param);
//     //   std::string param_log_output = param_name + ": " + std::to_string(param);
//     //   RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

//     //   return;
//     // }
// };

// } // namespace velocity_sender

// #endif // velocity_sender_HPP
