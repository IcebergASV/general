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
            "/mavros/local_position/pose", 10, std::bind(&WaypointSender::poseCallback, this, std::placeholders::_1));


        // Publisher to publish the calculated waypoint
        waypoint_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);

        in_guided_ = false;
        previous_guided_state_ = false;

    }

// TODO:
// - using current pose, send a cordinate x meters ahead
// - log the current position and the set position when switch to guided
// - maybe i should listen the the pixhawk topic?
// - when the first waypoint is reached (figure out what the indicator is) send another Waypoint
// - ad hoc variables to set the distance ahead and frequency of sending
// - constant publishing of the same position vs publish a few times and thats it (trying to determine what happens when the boat reaches a point. Does it loiter like auto mode)
// - what is the acceptable radius? can we set it?
// - update cmake lists

  private:

    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        if (!previous_guided_state_ && msg->guided)
        {
          RCLCPP_INFO(this->get_logger(), "Guided mode: true");
          in_guided_ = true;
          // calculateStraightAheadWaypoint();
        }
        else
        {
          in_guided_ = msg->guided;
        }
        previous_guided_state_ = msg->guided;
    }

    void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
      if (in_guided_)
      {
        // Get current position and heading
        double x = msg->pose.position.x;
        double y = msg->pose.position.y;
        tf2::Quaternion orientation;
        tf2::fromMsg(msg->pose.orientation, orientation);

        double roll, pitch, yaw;
        tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

        // Calculate new position
        double new_x = x + 10.0 * cos(yaw);
        double new_y = y + 10.0 * sin(yaw);

        // Create a new waypoint
        geometry_msgs::msg::PoseStamped waypoint;
        waypoint.header = msg->header; //prob needs to be updated
        waypoint.pose.position.x = new_x;
        waypoint.pose.position.y = new_y;
        waypoint.pose.orientation = tf2::toMsg(tf2::Quaternion(0, 0, yaw, 1));

        RCLCPP_INFO(this->get_logger(), "Current position: x=%f, y=%f, z=%f", current_local_position_.x, current_local_position_.y, current_local_position_.z);

        //publish waypoint
        waypoint_publisher->publish(waypoint);
      }

    }

    // void calculateStraightAheadWaypoint()
    // {
    //   RCLCPP_INFO(this->get_logger(), "Current position: x=%f, y=%f, z=%f", current_local_position_.x, current_local_position_.y, current_local_position_.z);
    // }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr waypoint_publisher;
    bool in_guided_;
    bool previous_guided_state_;
    geometry_msgs::msg::Point current_local_position_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointSender>());
  rclcpp::shutdown();
  return 0;
}