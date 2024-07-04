#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "vehicle_control_interfaces/action/WaypointSend.hpp"

class WaypointSender : public rclcpp::Node
{
    public:

    using WPSendActionInterface = vehicle_control_interfaces::action::WaypointSend;
    using GoalHandleWPSend = rclcpp_action::ServerGoalHandle<WPSendActionInterface>

    explicit WaypointSender(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
    : Node("waypoint_sender", options)
    {
        using namespace std::placeholders;

        this->action_server_ = rclcpp_action::create_server<WPSendActionInterface>(
            this,
            "WPSendActionInterface",
            std::bind(&WaypointSender::handle_goal, this, _1, _2),
            std::bind(&WaypointSender::handle_cancel, this, _1),
            std::bind(&WaypointSender::handle_accepted, this, _1));
    }

    private:

    rclcpp_action::Server<WPSendActionInterface>::SharedPtr action_server_;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const WPSendActionInterface::Goal> goal)
    {
        RCLCPP_INFO(this->get_logger(), "Received goal request with order %d", goal->order);
        // Prevent compiler warning for unused var. In ROS Tutorial.
        (void)uuid; 
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleWPSend> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
        // Prevent compiler warning for unused var. In ROS Tutorial.
        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleWPSend> goal_handle)
    {
        return;
    }

    void send_waypoints(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Sending waypoints");

        const auto goal = goal_handle->get_goal();

        auto feedback = std::make_shared<WPSendActionInterface::Feedback>();
        auto result = std::make_shared<WPSendActionInterface::Result>();

        auto & next_wp = feedback->next_wp;
        feedback = 10;
        
        // simulating something happening
        for (int i = 1; (i < 5) && rclcpp::ok(); ++i)
        {
           goal_handle->publish_feedback(feedback); 
        }
        
        if (rclcpp::ok()) 
        {
            result->sequence = sequence;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }
    }

}