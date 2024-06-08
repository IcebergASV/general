#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executor.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "mavros_msgs/msg/waypoint_list.hpp"
#include "mavros_msgs/srv/waypoint_push.hpp"
#include "mavros_msgs/msg/waypoint.hpp"
#include "mavros_msgs/msg/command_code.hpp"
#include "mavros_msgs/srv/waypoint_clear.hpp"
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

        wp_reached_subscriber = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&WaypointSender::wpReachedCallback, this, std::placeholders::_1));

        // Publisher to publish the calculated waypoint
        waypoint_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);
        waypoint_list_publisher = this->create_publisher<mavros_msgs::msg::WaypointList>("/mavros/mission/waypoints", 10);

        waypoint_push_client = this->create_client<mavros_msgs::srv::WaypointPush>("/mavros/mission/push");
        waypoint_clear = this->create_client<mavros_msgs::srv::WaypointClear>("/mavros/mission/clear");

        in_guided_ = false;
        previous_guided_state_ = false;

        wp_reached_counter = 0;
        // wp_reached_max_count = this->get_parameter("wp_max").as_int();
        wp_reached_max_count = 1;
    }

  private:

    void stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
    {
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

    void wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
    {
      RCLCPP_INFO(this->get_logger(), "Waypoint Reached #%i", wp_reached_counter);

      if (wp_reached_counter < wp_reached_max_count && msg.wp_seq == 0)
      {
        publishStraightAheadWaypoint();
        wp_reached_counter++;
      }
      else
      {
        RCLCPP_INFO(this->get_logger(), "Max waypoints reached. Max: %i", wp_reached_max_count);
      }
    }

    void createWaypointList(){
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
      mavros_msgs::msg::Waypoint waypoint_msg;
      // mavros_msgs::msg::WaypointList waypoint_list_msg;
      auto waypoint_list_msg = std::make_shared<mavros_msgs::srv::WaypointPush::Request>();

      waypoint_msg.frame = mavros_msgs::msg::Waypoint::FRAME_GLOBAL;// LOCAL_NED FRAME
      waypoint_msg.x_lat = 10;
      waypoint_msg.y_long =50;

      waypoint_list_msg->waypoints.push_back(waypoint_msg);
      waypoint_list_msg->start_index = 0;

      // return waypoint_list_msg;
      auto request = std::make_shared<mavros_msgs::srv::WaypointClear::Request>();

      // Send the request
      auto wp_clear_result = waypoint_clear->async_send_request(request);

      // if (rclcpp::spin_until_future_complete(this, wp_clear_result) ==
      //   rclcpp::FutureReturnCode::SUCCESS) {
      //     RCLCPP_INFO(this->get_logger(), "Waypoints cleared successfully.");
      //   }
      auto result = waypoint_push_client->async_send_request(waypoint_list_msg);
    }

    void publishWaypointList()
    {
      //publish waypoint
      // waypoint_list_publisher->publish(createWaypointList());
      createWaypointList();
    }

    geometry_msgs::msg::PoseStamped calculateWaypointStraightAhead()
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
      // mavros_msgs::msg::Waypoint waypoint_msg;
      // mavros_msgs::msg::WaypointList waypoint_list_msg;

      // waypoint_msg.frame = 3;// LOCAL_NED FRAME
      // waypoint_msg.x_lat = new_x;
      // waypoint_msg.y_long =new_y;

      // waypoint_list_msg.waypoints.push_back(waypoint_msg);


      waypoint.header = current_local_position_.header;
      waypoint.pose.position.x = new_x;
      waypoint.pose.position.y = new_y;
      waypoint.pose.orientation = tf2::toMsg(tf2::Quaternion(0, 0, yaw, 1));

      RCLCPP_INFO(this->get_logger(), "Current position: x=%f, y=%f, z=%f", current_local_position_.pose.position.x, current_local_position_.pose.position.y, current_local_position_.pose.position.z);
      RCLCPP_INFO(this->get_logger(), "Waypoint position: x=%f, y=%f, z=%f", waypoint.pose.position.x, waypoint.pose.position.y, waypoint.pose.position.z);

      return waypoint;
    }

    void publishStraightAheadWaypoint()
    {
      //publish waypoint
      waypoint_publisher->publish(calculateWaypointStraightAhead());
    }
    // Boat's current position (x0,y0)
    // Boats's heading yaw
    // desired position (x1,y1)
    std::vector<double> calculateWaypointLocal(double x0,double y0, double yaw, double x1, double y1)
    {
      RCLCPP_INFO(this->get_logger(), "current position: (%f,%f), yaw: %f",x0,y0,yaw);
      // get desired positon radius and angle
      double r = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2));
      double theta = std::atan2(y1, x1);
      RCLCPP_INFO(this->get_logger(), "radius, theta: %f,%f", r,theta);

      // get rotation angle
      double alpha = yaw - theta;
      RCLCPP_INFO(this->get_logger(), "alpha: %f", alpha);

      // calculate rotated points
      double x2 = r*std::cos(alpha);
      double y2 = r*std::sin(alpha);
      RCLCPP_INFO(this->get_logger(), "rotated points: (%f,%f)", x2,y2);

      // shift point
      x2 = x2 + x0;
      y2 = y2 + x0;

      RCLCPP_INFO(this->get_logger(), "final points: (%f,%f)", x2,y2);
      std::vector<double> new_cords(3);
      new_cords[0] = x2;
      new_cords[1] = y2;
      return new_cords;
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_subscriber;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr waypoint_publisher;
    rclcpp::Publisher<mavros_msgs::msg::WaypointList>::SharedPtr waypoint_list_publisher;
    rclcpp::Client<mavros_msgs::srv::WaypointPush>::SharedPtr waypoint_push_client;
    rclcpp::Client<mavros_msgs::srv::WaypointClear>::SharedPtr waypoint_clear;

    bool in_guided_;
    bool previous_guided_state_;
    int wp_reached_counter;
    int wp_reached_max_count;

    geometry_msgs::msg::PoseStamped current_local_position_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointSender>());
  rclcpp::shutdown();
  return 0;
}