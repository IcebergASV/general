#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "mavros_msgs/msg/waypoint_reached.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
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
        waypoint_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);

        in_guided_ = false;
        previous_guided_state_ = false;

        wp_reached_counter = 0;
        wp_reached_max_count = 2;
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

    void calculateWaypointStraightAhead()
    {

        // Create a new waypoint
        geometry_msgs::msg::PoseStamped local_position; 
        local_position.header = current_local_position_.header;
        local_position.pose.position.x = 1;
        local_position.pose.position.y = 2;

        tf2::Quaternion orientation;
        tf2::fromMsg(current_local_position_.pose.orientation, orientation);
        double roll, pitch, yaw;
        tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

        local_position.pose.orientation = tf2::toMsg(tf2::Quaternion(0, 0, yaw, 1));
        local_to_relative_grace(local_position, current_local_position_ );
        //geometry_msgs::msg::PoseStamped waypoint = local_to_relative(local_position, current_local_position_);
      //RCLCPP_INFO(this->get_logger(), "Current position: x=%f, y=%f, z=%f", current_local_position_.pose.position.x, current_local_position_.pose.position.y, current_local_position_.pose.position.z);
      //RCLCPP_INFO(this->get_logger(), "Waypoint position: x=%f, y=%f, z=%f", waypoint.pose.position.x, waypoint.pose.position.y, waypoint.pose.position.z);

      //return waypoint;
    }

    void publishStraightAheadWaypoint()
    {
      //publish waypoint
      //waypoint_publisher->publish(calculateWaypointStraightAhead());
      calculateWaypointStraightAhead();
    }

    geometry_msgs::msg::PoseStamped local_to_relative(
        const geometry_msgs::msg::PoseStamped &local_position,
        const geometry_msgs::msg::PoseStamped &robot_pose)
    {
        // Extract the robot's position and orientation
        const auto &robot_position = robot_pose.pose.position;
        const auto &robot_orientation = robot_pose.pose.orientation;

        // Convert the robot's quaternion to a rotation matrix
        tf2::Quaternion quat(robot_orientation.x, robot_orientation.y, robot_orientation.z, robot_orientation.w);
        tf2::Matrix3x3 rotation_matrix;
        quat.normalize();
        rotation_matrix.setRotation(quat);

        // Convert rotation matrix to Eigen matrix for easier manipulation
        Eigen::Matrix3d eigen_rotation_matrix;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                eigen_rotation_matrix(i, j) = rotation_matrix[i][j];
        
        RCLCPP_INFO(this->get_logger(), "Rotation Matrix");
        printMatrix(eigen_rotation_matrix);

        // Convert local position to Eigen vector
        Eigen::Vector3d local_position_vec(
            local_position.pose.position.x,
            local_position.pose.position.y,
            local_position.pose.position.z);

        RCLCPP_INFO(this->get_logger(), "local position vec position: %f, y=%f, z=%f", local_position_vec.x(), local_position_vec.y(), local_position_vec.z());

        // Convert robot position to Eigen vector
        Eigen::Vector3d robot_position_vec(
            robot_position.x,
            robot_position.y,
            robot_position.z);

         RCLCPP_INFO(this->get_logger(), "robot position vec position: x=%f, y=%f, z=%f", robot_position_vec.x(), robot_position_vec.y(), robot_position_vec.z());

        // Compute the relative position
        Eigen::Vector3d relative_position_vec = eigen_rotation_matrix.transpose() * (local_position_vec - robot_position_vec);

        // Create PoseStamped message for the relative position
        geometry_msgs::msg::PoseStamped relative_position;
        relative_position.header.frame_id = "base_link";  // Frame of reference for the robot
        relative_position.pose.position.x = relative_position_vec.x();
        relative_position.pose.position.y = relative_position_vec.y();
        relative_position.pose.position.z = relative_position_vec.z();
        relative_position.pose.orientation = robot_pose.pose.orientation;  // Orientation remains unchanged

        return relative_position;
    }

    void local_to_relative_grace(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose)
    {
      // radius = std::sqrt(rel_pose.pose.position.y * rel_pose.pose.position.y + rel_pose.pose.position.x * rel_pose.pose.position.x);
      //double angle = std::atan2(rel_pose.pose.position.y, rel_pose.pose.position.x);
      //RCLCPP_INFO(this->get_logger(), "radius: %f, angle: %f", radius, angle);

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
    }

    void printMatrix(const Eigen::Matrix3d &matrix)
    {
        std::ostringstream oss;
        oss << "Rotation Matrix:\n" 
            << matrix(0, 0) << " " << matrix(0, 1) << " " << matrix(0, 2) << "\n"
            << matrix(1, 0) << " " << matrix(1, 1) << " " << matrix(1, 2) << "\n"
            << matrix(2, 0) << " " << matrix(2, 1) << " " << matrix(2, 2) << "\n";

        RCLCPP_INFO(this->get_logger(), "%s", oss.str().c_str());
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Subscription<mavros_msgs::msg::WaypointReached>::SharedPtr wp_reached_subscriber;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr waypoint_publisher;

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