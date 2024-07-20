#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// #include "velocity_sender/velocity_sender_component.hpp"

namespace velocity_sender
{
  using std::placeholders::_1;
  
  class VelocitySender : public rclcpp::Node
  {
    public:
      VelocitySender()
        : Node("velocity_sender")
        {
          pixhawk_state_sub_ = this->create_subscription<mavros_msgs::msg::State>(
            "/mavros/state", 10, std::bind(&VelocitySender::pixhawkStateCallback, this, _1));
          pose_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/mavros/local_position/pose", rclcpp::SensorDataQoS(), std::bind(&VelocitySender::poseCallback, this, std::placeholders::_1));
          velocity_publisher = this->create_publisher<geometry_msgs::msg::Twist>("/mavros/setpoint_velocity/cmd_vel_unstamped", 10);

          this->declare_parameter<std::vector<double>>("velocities", std::vector<double>{});

          std::vector<double> flat_velocities;
          if (this->get_parameter("velocities", flat_velocities))
          {
            // Log retrieved values
            RCLCPP_INFO(this->get_logger(), "Received velocity parameter");
          }
          else
          {
            RCLCPP_WARN(this->get_logger(), "Failed to get 'velocities' parameter.");
          }

          // Convert flat_velocities to nested structure
          for (size_t i = 0; i < flat_velocities.size(); i += 2)
          {
              velocities.push_back({flat_velocities[i], flat_velocities[i+1]});
          }

          // Log the coordinates
          RCLCPP_INFO(this->get_logger(), "Loaded velocities:");
          for (const auto &vel : velocities)
          {
            RCLCPP_INFO(this->get_logger(), "[%f, %f]", vel[0], vel[1]);
          }

          // example_pub_ = this->create_publisher<std_msgs::msg::Float64>("velocity_sender/publishing_topic", 10);

          // VelocitySender::getParam<int>("multiplier", p_multiplier_, 0, "Multiplies number by this integer");
          // VelocitySender::getParam<double>("adder", p_adder_, 0, "Adds this double to a number");
          // on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&VelocitySender::param_callback, this, std::placeholders::_1));
          in_guided_ = false;
          previous_guided_state_ = false;
        }
    private:

      bool in_guided_;
      bool previous_guided_state_;
      geometry_msgs::msg::PoseStamped current_local_position_;

      std::vector<std::vector<double>> velocities;

      rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr pixhawk_state_sub_;
      rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;

      rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher;

      void pixhawkStateCallback(const mavros_msgs::msg::State::SharedPtr msg)
      {
        if (!previous_guided_state_ && msg->guided)
        {
          RCLCPP_INFO(this->get_logger(), "Guided mode: true");
          in_guided_ = true;
          velocitySender();
        }
        else
        {
          in_guided_ = msg->guided;
        }
        previous_guided_state_ = msg->guided;
      }
      
      void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
      {
        current_local_position_ = *msg;
      }

      void velocitySender()
      {
        for (const auto &vel : velocities)
        {
          // Create a Twist message
          geometry_msgs::msg::Twist velocity;
          velocity.linear.x = vel[0];
          velocity.linear.y = vel[1];
          velocity.linear.z = 0.0;  // Assuming no vertical movement
          velocity.angular.x = 0.0;
          velocity.angular.y = 0.0;
          velocity.angular.z = 0.0;  // Assuming no angular velocity

          RCLCPP_INFO(this->get_logger(), " Sending Velocity: [%f, %f]", vel[0], vel[1]);
          velocity_publisher->publish(velocity);
          wait();
        }
      }
      void wait()
      {
        rclcpp::Rate rate(0.2);
        rate.sleep();
      }

      geometry_msgs::msg::Twist calculateVelocityStraightAhead()
      {
        // Get current heading
        // tf2::Quaternion orientation;
        // tf2::fromMsg(current_local_position_.pose.orientation, orientation);

        // double roll, pitch, yaw;
        // tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

        // Define the velocity straight ahead
        // double linear_velocity = 1.0;  // Define the desired linear velocity

        // Calculate velocity components
        double velocity_x = 1.0;
        double velocity_y = 0.0;

        // Create a Twist message
        geometry_msgs::msg::Twist velocity;
        velocity.linear.x = velocity_x;
        velocity.linear.y = velocity_y;
        velocity.linear.z = 0.0;  // Assuming no vertical movement
        velocity.angular.x = 0.0;
        velocity.angular.y = 0.0;
        velocity.angular.z = 0.0;  // Assuming no angular velocity

        RCLCPP_INFO(this->get_logger(), "Velocity: linear.x=%f, linear.y=%f, linear.z=%f", velocity.linear.x, velocity.linear.y, velocity.linear.z);

        return velocity;
      }

      void publishStraightAheadVelocity()
      {
        //publish waypoint
        velocity_publisher->publish(calculateVelocityStraightAhead());
      }


  };

  // rcl_interfaces::msg::SetParametersResult VelocitySender::param_callback(const std::vector<rclcpp::Parameter> &params)
  // {
  //   rcl_interfaces::msg::SetParametersResult result;

  //   if (params[0].get_name() == "multiplier") { p_multiplier_ = params[0].as_int(); }
  //   else if (params[0].get_name() == "adder") { p_adder_ = params[0].as_double(); }
  //   else {
  //     RCLCPP_ERROR(this->get_logger(), "Invalid Param");
  //     result.successful = false;
  //     return result;
  //   }

  //   result.successful = true;
  //   return result;
  // }
}

int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<velocity_sender::VelocitySender>());
    rclcpp::shutdown();
    return 0;
  }
//#include "rclcpp_components/register_node_macro.hpp"

//RCLCPP_COMPONENTS_REGISTER_NODE(velocity_sender::VelocitySender)
