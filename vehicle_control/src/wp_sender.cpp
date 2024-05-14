#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>

using std::placeholders::_1;

class WaypointSender : public rclcpp::Node
{
  public:

    WaypointSender()
    : Node("waypoint_sender")
    {
        state_subscriber_ = this->create_subscription<mavros_msgs::msg::State>(
            "/mavros/state",
            10, std::bind(&WaypointSender::stateCallback, this, std::placeholders::_1));

        pose_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/mavros/local_position/pose", rclcpp::SensorDataQoS(), std::bind(&WaypointSender::poseCallback, this, std::placeholders::_1));


        // Publisher to publish the calculated waypoint
        waypoint_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);

        in_guided_ = false;
        previous_guided_state_ = false;

    }

  private:

    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
    {
      RCLCPP_INFO(this->get_logger(), "State Callback");
        if (!previous_guided_state_ && msg->guided)
        {
          RCLCPP_INFO(this->get_logger(), "Guided mode: true");
          in_guided_ = true;
          publishStraightAheadWaypoint();
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

    void publishStraightAheadWaypoint()
    {
      // Get current position and heading
      double x = current_local_position_.pose.position.x;
      double y = current_local_position_.pose.position.y;
      tf2::Quaternion orientation;
      tf2::fromMsg(current_local_position_.pose.orientation, orientation);

      double roll, pitch, yaw;
      tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

      // Calculate new position
      double new_x = x + 10.0 * cos(yaw);
      double new_y = y + 10.0 * sin(yaw);

      // Create a new waypoint
      geometry_msgs::msg::PoseStamped waypoint;
      waypoint.header = current_local_position_.header;
      waypoint.pose.position.x = new_x;
      waypoint.pose.position.y = new_y;
      waypoint.pose.orientation = tf2::toMsg(tf2::Quaternion(0, 0, yaw, 1));

      RCLCPP_INFO(this->get_logger(), "Current position: x=%f, y=%f, z=%f", current_local_position_.pose.position.x, current_local_position_.pose.position.y, current_local_position_.pose.position.z);
      RCLCPP_INFO(this->get_logger(), "Waypoint position: x=%f, y=%f, z=%f", waypoint.pose.position.x, waypoint.pose.position.y, waypoint.pose.position.z);

      //publish waypoint
      waypoint_publisher->publish(waypoint);
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr waypoint_publisher;
    bool in_guided_;
    bool previous_guided_state_;
    geometry_msgs::msg::PoseStamped current_local_position_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointSender>());
  rclcpp::shutdown();
  return 0;
}