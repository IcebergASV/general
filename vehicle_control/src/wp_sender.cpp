#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geographic_msgs/msg/geo_pose_stamped.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <Eigen/Dense>
#include <sstream>

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

        wp_reached_subscriber = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&WaypointSender::wpReachedCallback, this, std::placeholders::_1));

        // Publisher to publish the calculated waypoint
        local_waypoint_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);
        global_waypoint_publisher = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("/mavros/setpoint_position/global", 10);

        this->declare_parameter<bool>("use_local_wp", true);

        if (this->get_parameter("use_local_wp", use_local_wp))
        {
          // Log retrieved values
          RCLCPP_INFO(this->get_logger(), "Using Local Waypoints: %s", use_local_wp ? "true" : "false");
        }
        else
        {
          RCLCPP_WARN(this->get_logger(), "Failed to get 'use_local_wp' parameter");
        }

        in_guided_ = false;
        previous_guided_state_ = false;

        wp_reached_counter = 0;
        wp_reached_max_count = 0;
    }

  private:

    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        if (!previous_guided_state_ && msg->guided)
        {
          RCLCPP_INFO(this->get_logger(), "Guided mode: true");
          in_guided_ = true;
          if (use_local_wp)
          {
            publish_local_waypoint();
          }
          else
          {
            //publish_global_waypoint();
          }
        }
        else
        {
          in_guided_ = msg->guided;
        }
        previous_guided_state_ = msg->guided;
    }

    void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
      local_position = *msg;
    }

    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
    {
      RCLCPP_INFO(this->get_logger(), "Waypoint Reached #%i", wp_reached_counter);

      if (wp_reached_counter < wp_reached_max_count && msg.wp_seq == 0)
      {
        publish_local_waypoint();
        //publish_global_waypoint();
        wp_reached_counter++;
      }
      else
      {
        RCLCPP_INFO(this->get_logger(), "Max waypoints reached. Max: %i", wp_reached_max_count);
      }
    }

    void publish_local_waypoint()
    {

      // Create a new waypoint
      geometry_msgs::msg::PoseStamped relative_position; 
      relative_position.header = local_position.header;
      double x = 0;
      double y = 10;
      relative_position.pose.position.x = y;
      relative_position.pose.position.y = -x;
      
      geometry_msgs::msg::PoseStamped waypoint = rel_to_local_cord_converter(relative_position, local_position );
      RCLCPP_INFO(this->get_logger(), "Current Local position: x=%f, y=%f, z=%f", local_position.pose.position.x, local_position.pose.position.y, local_position.pose.position.z);
      RCLCPP_INFO(this->get_logger(), "Waypoint position: x=%f, y=%f, z=%f", waypoint.pose.position.x, waypoint.pose.position.y, waypoint.pose.position.z);
      
      local_waypoint_publisher->publish(waypoint);
    }

    void publish_global_waypoint()
    {
      geographic_msgs::msg::GeoPoseStamped global_waypoint;
      global_waypoint.pose.position.latitude = -35.9632622;  // Example latitude
      global_waypoint.pose.position.longitude = 149.9652373;  // Example longitude
      global_waypoint_publisher->publish(global_waypoint);
    }

    geometry_msgs::msg::PoseStamped rel_to_local_cord_converter(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose)
    {
      // Convert relative coordinates to local coordinates
      tf2::Quaternion orientation;
      tf2::fromMsg(local_pose.pose.orientation, orientation);
      double roll, pitch, yaw;
      tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

      RCLCPP_INFO(this->get_logger(), "Robot yaw: %f", yaw);
      double rel_x, rel_y;
      rel_x = rel_pose.pose.position.x;
      rel_y = rel_pose.pose.position.y;
      double heading = yaw;
      double prop_x_aligned = rel_x*cos(heading) - rel_y*sin(heading);
      double prop_y_aligned = rel_x*sin(heading) + rel_y*cos(heading);
      double x_prime =  local_pose.pose.position.x + prop_x_aligned;
      double y_prime =  local_pose.pose.position.y + prop_y_aligned;
      RCLCPP_INFO(this->get_logger(), "rel x: %f, rel y: %f", rel_pose.pose.position.x, rel_pose.pose.position.y);
      RCLCPP_INFO(this->get_logger(), "x aligned: %f, y aligned: %f", prop_x_aligned, prop_y_aligned);
      RCLCPP_INFO(this->get_logger(), "boatx: %f, boaty: %f", local_pose.pose.position.x, local_pose.pose.position.y);
      RCLCPP_INFO(this->get_logger(), "xprime: %f, yprime: %f", x_prime, y_prime);

      geometry_msgs::msg::PoseStamped relative_position;
      relative_position.header.frame_id = "base_link";  // Frame of reference for the robot
      relative_position.pose.position.x = x_prime;
      relative_position.pose.position.y = y_prime;

      return relative_position;
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_subscriber;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_waypoint_publisher;
    rclcpp::Publisher<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_waypoint_publisher;

    bool in_guided_;
    bool previous_guided_state_;
    bool use_local_wp;
    int wp_reached_counter;
    int wp_reached_max_count;

    geometry_msgs::msg::PoseStamped local_position;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointSender>());
  rclcpp::shutdown();
  return 0;
}