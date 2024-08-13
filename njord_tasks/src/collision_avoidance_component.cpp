#include "njord_tasks/collision_avoidance_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"

void wait()
{
  rclcpp::Rate rate(1);
  rate.sleep();
}
namespace njord_tasks
{
  CollisionAvoidance::CollisionAvoidance(const rclcpp::NodeOptions & options)
  : Node("collision_avoidance", options)
  {
    CollisionAvoidance::getParam<double>("finish_lat", p_finish_lat_, 0.0, " " );
    CollisionAvoidance::getParam<double>("finish_lon", p_finish_lon_, 0.0, " ");
    
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&CollisionAvoidance::param_callback, this, std::placeholders::_1));

    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&CollisionAvoidance::taskToExecuteCallback, this, _1));
    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);

    laser_segments_sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&CollisionAvoidance::laserSegmentCallback, this, _1));
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&CollisionAvoidance::stateCallback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&CollisionAvoidance::timerCallback, this));
    set_mode_client_ = this->create_client<mavros_msgs::srv::SetMode>("/mavros/set_mode");
  
    start_task_ = false;
    obstacles_ = false;
    prev_in_hold_ = false;
  }

  rcl_interfaces::msg::SetParametersResult CollisionAvoidance::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void CollisionAvoidance::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    in_guided_ = task_lib::inGuided(current_state);
    return;
  }

  void CollisionAvoidance::change_mode(const std::string &mode)
  {
    // Create a request
    auto request = std::make_shared<mavros_msgs::srv::SetMode::Request>();
    request->base_mode = 0; // Keep base mode unchanged
    request->custom_mode = mode;

    // Asynchronously send the request and handle the response
    auto future = set_mode_client_->async_send_request(request, 
      [this](rclcpp::Client<mavros_msgs::srv::SetMode>::SharedFuture future) {
          auto response = future.get();
          if (response->mode_sent) {
              RCLCPP_INFO(this->get_logger(), "Mode Changed: %i", response->mode_sent);
          } else {
              RCLCPP_ERROR(this->get_logger(), "Failed to change mode");
          }
      });
  }

  void CollisionAvoidance::taskToExecuteCallback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
    start_task_ = true;
    RCLCPP_INFO(this->get_logger(), "Starting CollisionAvoidance task");
 
  }

  void CollisionAvoidance::laserSegmentCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    if (msg->segments.size() > 0)
    {
      // perception_interfaces::msg::PropArray lidar_detected_prop_array;
      // for (slg_msgs::msg::Segment segment : msg->segments)
      // {
      //   std::vector<geometry_msgs::msg::Point> filtered_points = lidar_calculations::getPointsWithinBounds(segment.points, p_min_lidar_dist_, p_max_lidar_dist_, p_lidar_fov_);

      //   if (lidar_calculations::hasEnoughPoints(filtered_points.size(), p_min_points_in_segment_))
      //   {
      //     attemptToCreateAndAddLidarDetectedProp(filtered_points, lidar_detected_prop_array);
      //   }
      // }
      // if (lidar_detected_prop_array.props.size() > 0)
      // {
      //   pub_->publish(lidar_detected_prop_array);
      // }
    }
    else
    {
      RCLCPP_WARN(this->get_logger(), "No segments in message");
    }
  }

  void CollisionAvoidance::sendFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(p_finish_lat_, p_finish_lon_);
    global_wp_pub_->publish(finish_wp);
  }
  
  // need to start by sending finish pnt
  void CollisionAvoidance::timerCallback()
  { 
    if (start_task_)
    {
      RCLCPP_DEBUG(this->get_logger(), "timerCallback");
      switch (status_)
      {
        case States::CHECK_FOR_OBSTACLES:
        {
          if (obstacles_)
          {
            change_mode("HOLD");
            status_ = States::HOLD;
          }
          else
          {
            if (prev_in_hold_)
            {
              prev_in_hold_ = false;
              change_mode("GUIDED");
              status_ = States::SEND_FINISH_PNT;
            }
            // else - continue
          }
          break;
        }
        case States::HOLD:
        {
          wait();
          prev_in_hold_ = true;
          //change_mode("GUIDED");
          status_ = States::CHECK_FOR_OBSTACLES;
        }
        case States::SEND_FINISH_PNT:
        {
          if (in_guided_)
          {
            RCLCPP_INFO(this->get_logger(), "In GUIDED mode");
            sendFinishPnt();
            status_ = States::CHECK_FOR_OBSTACLES;
          }
          break;
        }
      }
    }
  }

  // void CollisionAvoidance::callback(const std_msgs::msg::Int32::SharedPtr msg)
  // {
  //   std_msgs::msg::Float64 new_value;
  //   new_value.data = msg->data *p_multiplier_ + p_adder_;

  //   //example_pub_->publish(new_value);
  // }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::CollisionAvoidance)
