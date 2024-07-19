#include "njord_maneuvering/maneuvering_node.h"

namespace njord_maneuvering
{
    ManeuveringNode::ManeuveringNode(const rclcpp::NodeOptions & options)
    : Node("maneuvering_node", options)
    {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
        
        pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("/mavros/local_position/pose", qos, std::bind(&ManeuveringNode::position_callback, this, _1));
        state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&ManeuveringNode::state_callback, this, _1));
        wp_reached_sub_ = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&ManeuveringNode::wp_reached_callback, this, _1));
        bbox_sub_ = this->create_subscription<perception_interfaces::msg::BoundingBoxes>("perception/mock_bboxes", 10, std::bind(&ManeuveringNode::bbox_callback, this, _1));

        waypoint_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/mavros/setpoint_position/local", 10);
        vector_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/mavros/setpoint_velocity/cmd_vel_unstamped", 10);

        ManeuveringNode::getParam<double>("wp1_x", p_wp1_x_, -3.0, "X-coordinate of the first provided GPS waypoint.");
        ManeuveringNode::getParam<double>("wp1_y", p_wp1_y_, 5.0, "Y-coordinate of the first provided GPS waypoint.");
        ManeuveringNode::getParam<double>("wp2_x", p_wp2_x_, 5.0, "X-coordinate of the second provided GPS waypoint.");
        ManeuveringNode::getParam<double>("wp2_y", p_wp2_y_, 5.0, "Y-coordinate of the second provided GPS waypoint.");
        ManeuveringNode::getParam<double>("turn_angle", p_turn_angle_, 1.0, "Amount to turn boat when performing velocity adjustments.");
        on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&ManeuveringNode::param_callback, this, std::placeholders::_1));
    }

    rcl_interfaces::msg::SetParametersResult ManeuveringNode::param_callback(const std::vector<rclcpp::Parameter> &params)
    {
        rcl_interfaces::msg::SetParametersResult result;

        if (params[0].get_name() == "wp1_x") { p_wp1_x_ = params[0].as_double(); }
        else if (params[0].get_name() == "wp1_y") { p_wp1_y_ = params[0].as_double(); }
        else if (params[0].get_name() == "wp2_x") { p_wp2_x_ = params[0].as_double(); }
        else if (params[0].get_name() == "wp2_y") { p_wp2_y_ = params[0].as_double(); }
        else if (params[0].get_name() == "turn_angle") { p_turn_angle_ = params[0].as_double(); }
        else {
            RCLCPP_ERROR(this->get_logger(), "Invalid Param");
            result.successful = false;
            return result;
        }

        result.successful = true;
        return result;
    }

    void ManeuveringNode::position_callback(const geometry_msgs::msg::PoseStamped msg)
    {
        local_pose_ = msg;
        // put in velo mode here?
        if (velocity_mode_)
        {
            ManeuveringNode::adjustVelocity();
        }
    }

    void ManeuveringNode::state_callback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        if (!previous_guided_state_ && msg->guided)
        {
            RCLCPP_INFO(this->get_logger(), "Guided mode: True");
            in_guided_ = true;
            // can do stuff here
            if (state_ == 0)
            {
                // go to wp1
                RCLCPP_INFO(this->get_logger(), "Heading to waypoint 1...");
                geometry_msgs::msg::PoseStamped wp1;
                // calculate vector from wp2 and wp1, get yaw from arctan(y/x)
                tf2::Vector3 wp_vector;
                wp_vector.setValue((p_wp2_x_-p_wp1_x_),(p_wp2_y_-p_wp1_y_),0);

                wp1.pose.position.x = p_wp1_x_;
                wp1.pose.position.y = p_wp1_y_;
                wp1.pose.orientation = tf2::toMsg(tf2::Quaternion(0, 0, atan(wp_vector.getY()/wp_vector.getX()), 1));
                // ^ should set heading toward wp2, doesnt seem to do this in sim

                waypoint_pub_->publish(wp1);
            }
        }
        else
        {
            in_guided_ = msg->guided;
        }
        previous_guided_state_ = msg->guided;
    }

    void ManeuveringNode::wp_reached_callback(const mavros_msgs::msg::WaypointReached msg)
    {
        RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
        mavros_msgs::msg::WaypointReached wpr = msg;

        if (state_ == 0)
        {
            // giving veloctiy as a vector
            RCLCPP_INFO(this->get_logger(), "Giving velocity as vector");
            velocity_mode_ = true;
            state_++;
        }
        else if (state_ == 1)
        {
            // reached wp2, end

        }
    }

    void ManeuveringNode::bbox_callback(const perception_interfaces::msg::BoundingBoxes msg)
    {
        bbox_ = msg;
        RCLCPP_INFO(this->get_logger(), "bbox callback");
    }

    void ManeuveringNode::adjustVelocity()
    {
        perception_interfaces::msg::BoundingBox bb1 = bbox_.bounding_boxes[0];
        perception_interfaces::msg::BoundingBox bb2 = bbox_.bounding_boxes[1];
        double smaller_angle, larger_angle;
        bbox_calculations::getCamBBoxAngle(bb1, smaller_angle, larger_angle, p_camera_fov, p_camera_res_x_);

        // double angle = p_turn_angle_;
        // if (leftPropCloser()) {
        //     angle = -p_turn_angle_;
        // }
        // geometry_msgs::msg::Twist dir;
        // dir.linear.x = 2.0;         // distance
        // dir.linear.y = 0.0;     //
        // dir.linear.z = 0.0;     // not
        // dir.angular.x = 0.0;    // relevant
        // dir.angular.y = 0.0;    //
        // dir.angular.z = angle;      // angle
        // vector_pub_->publish(dir);
    }

    bool ManeuveringNode::leftPropCloser()
    {
        return true;
    }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_maneuvering::ManeuveringNode)