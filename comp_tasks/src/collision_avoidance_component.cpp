#include "comp_tasks/collision_avoidance_component.hpp"
#include "comp_tasks/lib/task_lib.hpp"
#include "comp_tasks/lib/lidar_calculations.hpp"
#include "comp_tasks/lib/visualization.hpp"

void wait()
{
  rclcpp::Rate rate(1);
  rate.sleep();
}
namespace comp_tasks
{
  CollisionAvoidance::CollisionAvoidance(const rclcpp::NodeOptions & options)
  : Node("collision_avoidance", options)
  {
    CollisionAvoidance::getParam<double>("finish_lat", p_finish_lat_, 0.0, " " );
    CollisionAvoidance::getParam<double>("finish_lon", p_finish_lon_, 0.0, " ");
    CollisionAvoidance::getParam<double>("min_dist", p_min_dist_, 0.0, " ");
    CollisionAvoidance::getParam<double>("max_dist", p_max_dist_, 0.0, " ");
    CollisionAvoidance::getParam<double>("fov", p_fov_, 0, " ");
    CollisionAvoidance::getParam<double>("obstacle_length", p_obstacle_length_, 0.0, " ");
    CollisionAvoidance::getParam<double>("obstacle_length_range", p_obstacle_length_range_, 0.0, " ");
    CollisionAvoidance::getParam<int>("mode_when_obstacles", p_mode_when_obstacles_, 0, " ");
    
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&CollisionAvoidance::param_callback, this, std::placeholders::_1));

    task_to_execute_sub_ = this->create_subscription<comp_tasks_interfaces::msg::StartTask>("/comp_tasks/task_to_execute", 10, std::bind(&CollisionAvoidance::taskToExecuteCallback, this, _1));
    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);

    laser_segments_sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&CollisionAvoidance::laserSegmentCallback, this, _1));
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&CollisionAvoidance::stateCallback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&CollisionAvoidance::timerCallback, this));
    set_mode_client_ = this->create_client<mavros_msgs::srv::SetMode>("/mavros/set_mode");
    obstacle_viz_points_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("comp_tasks/obstacle_visualization", 10);
    start_task_ = false;
    obstacles_ = false;
    prev_in_loiter_ = false;

    status_ = States::SEND_FINISH_PNT;
  }

  rcl_interfaces::msg::SetParametersResult CollisionAvoidance::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "min_dist") { p_min_dist_ = params[0].as_double(); }
    else if (params[0].get_name() == "max_dist") { p_max_dist_ = params[0].as_double(); }
    else if (params[0].get_name() == "fov") { p_fov_ = params[0].as_double(); }
    else if (params[0].get_name() == "obstacle_length") { p_obstacle_length_ = params[0].as_double(); }
    else if (params[0].get_name() == "obstacle_length_range") { p_obstacle_length_range_ = params[0].as_double(); }
    else if (params[0].get_name() == "mode_when_obstacles") { p_mode_when_obstacles_ = params[0].as_int(); }


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

  std::string CollisionAvoidance::getModeString(int mode){
    if (mode == 0)
    {
      return "HOLD";
    }
    else if (mode == 1)
    {
      return "LOITER";
    }
    else if (mode ==2)
    {
      return "MANUAL";
    }
    RCLCPP_WARN(this->get_logger(), "Invalid mode, must be int between 0-2");
    return "ERROR";
  }

  void CollisionAvoidance::change_mode()
  {
    // Create a request
    auto request = std::make_shared<mavros_msgs::srv::SetMode::Request>();
    request->base_mode = 0; // Keep base mode unchanged
    
    request->custom_mode = getModeString(p_mode_when_obstacles_);

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

  void CollisionAvoidance::taskToExecuteCallback(const comp_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
    start_task_ = true;
    double just_doing_this_temporarily_to_avoid_build_warnings = msg->start_pnt.latitude;
    RCLCPP_DEBUG(this->get_logger(), "lol %f", just_doing_this_temporarily_to_avoid_build_warnings);
    RCLCPP_INFO(this->get_logger(), "Starting Collision Avoidance task");
 
  }

  void CollisionAvoidance::laserSegmentCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    int obstacle_cnt = 0;
    std::vector<slg_msgs::msg::Segment> obstacle_segments;
    if (msg->segments.size() > 0)
    {
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (lidar_calculations::segmentInFOV(segment.points, p_min_dist_, p_max_dist_, p_fov_))
        {
          double length = lidar_calculations::getSegmentLength(segment.points);
          if ((length >= (p_obstacle_length_ - p_obstacle_length_range_)) && (length <= p_obstacle_length_ + p_obstacle_length_range_))
          {
            RCLCPP_INFO(this->get_logger(), "OBSTACLE length: %f", length);
            obstacle_cnt++;
            obstacle_segments.push_back(segment);
          }
        }
      }
      if (obstacle_cnt > 0)
      {
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 10000, "Obstacles Detected: %u", obstacle_cnt);
        obstacles_ = true;
      }
      else
      {
        obstacles_ = false;
      }
      obstacle_viz_points_pub_->publish(visualization::create_segment_viz_points(obstacle_segments));
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }

  void CollisionAvoidance::sendFinishPnt()
  {
    geographic_msgs::msg::GeoPoseStamped finish_wp = task_lib::getGlobalWPMsg(p_finish_lat_, p_finish_lon_);
    global_wp_pub_->publish(finish_wp);
  }
  
  void CollisionAvoidance::timerCallback()
  { 
    if (start_task_)
    {
      RCLCPP_DEBUG(this->get_logger(), "timerCallback");
      switch (status_)
      {
        case States::CHECK_FOR_OBSTACLES:
        {
          RCLCPP_INFO(this->get_logger(), "Checking for obstacles");
          if (obstacles_)
          {
            if (prev_in_loiter_)
            {
              RCLCPP_INFO(this->get_logger(), "Obstacle(s) still detected, remaining in %s", getModeString(p_mode_when_obstacles_).c_str());
            }
            else {
              RCLCPP_INFO(this->get_logger(), "Obstacle(s) detected, changing mode to %s", getModeString(p_mode_when_obstacles_).c_str());
              change_mode();              
            }

            status_ = States::LOITER;
          }
          else
          {
            if (prev_in_loiter_)
            {
              RCLCPP_INFO(this->get_logger(), "No obstacles detected, setting mode to GUIDED and resending finish point");
              prev_in_loiter_ = false;
              change_mode("GUIDED");
              status_ = States::SEND_FINISH_PNT;
            }
            RCLCPP_INFO(this->get_logger(), "No obstacles detected, continue towards finish point");
            wait();
          }
          break;
        }
        case States::LOITER:
        {

          RCLCPP_INFO(this->get_logger(), "In %s", getModeString(p_mode_when_obstacles_).c_str()); // TODO check we are actually in the correct mode
          wait();
          prev_in_loiter_ = true;
          status_ = States::CHECK_FOR_OBSTACLES;
          break;
        }
        case States::SEND_FINISH_PNT:
        {
          if (in_guided_)
          {
            RCLCPP_INFO(this->get_logger(), "In GUIDED mode, sending finish point");
            sendFinishPnt();
            wait();
            status_ = States::CHECK_FOR_OBSTACLES;
          }
          break;
        }
      }
    }
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::CollisionAvoidance)
