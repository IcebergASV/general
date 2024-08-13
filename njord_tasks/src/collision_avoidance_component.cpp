#include "njord_tasks/collision_avoidance_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"
#include "njord_tasks/lib/lidar_calculations.hpp"

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
    CollisionAvoidance::getParam<double>("min_dist", p_min_dist_, 0.0, " ");
    CollisionAvoidance::getParam<double>("max_dist", p_max_dist_, 0.0, " ");
    CollisionAvoidance::getParam<double>("fov", p_fov_, 0, " ");
    CollisionAvoidance::getParam<double>("obstacle_length", p_obstacle_length_, 0.0, " ");
    CollisionAvoidance::getParam<double>("obstacle_length_range", p_obstacle_length_range_, 0.0, " ");
    
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&CollisionAvoidance::param_callback, this, std::placeholders::_1));

    task_to_execute_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&CollisionAvoidance::taskToExecuteCallback, this, _1));
    global_wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("mavros/setpoint_position/global", 10);

    laser_segments_sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&CollisionAvoidance::laserSegmentCallback, this, _1));
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&CollisionAvoidance::stateCallback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&CollisionAvoidance::timerCallback, this));
    set_mode_client_ = this->create_client<mavros_msgs::srv::SetMode>("/mavros/set_mode");
    obstacle_viz_points_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("njord_tasks/obstacle_visualization", 10);
    start_task_ = false;
    obstacles_ = false;
    prev_in_hold_ = false;

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
          if ((length >= p_obstacle_length_ - p_obstacle_length_range_) && (length >= p_obstacle_length_ + p_obstacle_length_range_))
          {
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
      obstacle_viz_points_pub_->publish(create_segment_viz_points(obstacle_segments));
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
          RCLCPP_INFO(this->get_logger(), "Checking for obstacles");
          if (obstacles_)
          {
            if (prev_in_hold_)
            {
              RCLCPP_INFO(this->get_logger(), "Obstacle(s) still detected, remaining in HOLD");
            }
            else {
              RCLCPP_INFO(this->get_logger(), "Obstacle(s) detected, changing mode to HOLD");
              change_mode("HOLD");              
            }

            status_ = States::HOLD;
          }
          else
          {
            if (prev_in_hold_)
            {
              RCLCPP_INFO(this->get_logger(), "No obstacles detected, setting mode to GUIDED and resending finish point");
              prev_in_hold_ = false;
              change_mode("GUIDED");
              status_ = States::SEND_FINISH_PNT;
            }
            RCLCPP_INFO(this->get_logger(), "No obstacles detected, continue towards finish point");
            wait();
          }
          break;
        }
        case States::HOLD:
        {

          RCLCPP_INFO(this->get_logger(), "In hold"); // TODO check we are actually in hold
          wait();
          prev_in_hold_ = true;
          //change_mode("GUIDED");
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

visualization_msgs::msg::MarkerArray CollisionAvoidance::create_segment_viz_points(
  std::vector<slg_msgs::msg::Segment> segment_list)
{
  // Create the visualization message
  visualization_msgs::msg::MarkerArray viz_array;

  // Create a deletion marker to clear the previous points
  visualization_msgs::msg::Marker deletion_marker;
  deletion_marker.header.frame_id = "base_scan";
  deletion_marker.action = visualization_msgs::msg::Marker::DELETEALL;
  viz_array.markers.push_back(deletion_marker);

  // Create a marker point
  visualization_msgs::msg::Marker viz_points;
  viz_points.header.frame_id = "base_scan";
  viz_points.lifetime = rclcpp::Duration(0, 10);
  viz_points.ns = "segments";
  viz_points.type = visualization_msgs::msg::Marker::POINTS;
  viz_points.action = visualization_msgs::msg::Marker::ADD;
  viz_points.scale.x = viz_points.scale.y = 0.02;

  // Create a marker centroid
  visualization_msgs::msg::Marker viz_centroids;
  viz_centroids.header.frame_id = "base_scan";
  viz_centroids.lifetime = rclcpp::Duration(0, 10);
  viz_centroids.ns = "centroids";
  viz_centroids.type = visualization_msgs::msg::Marker::CUBE;
  viz_centroids.action = visualization_msgs::msg::Marker::ADD;
  viz_centroids.scale.x = viz_centroids.scale.y = viz_centroids.scale.z = 0.05;

  // Create a marker id text
  visualization_msgs::msg::Marker viz_text;
  viz_text.header.frame_id = "base_scan";
  viz_text.lifetime = rclcpp::Duration(0, 10);
  viz_text.ns = "id";
  viz_text.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
  viz_text.action = visualization_msgs::msg::Marker::ADD;
  viz_text.scale.z = 0.25;
  viz_text.color.r = 1.0;
  viz_text.color.g = 1.0;
  viz_text.color.b = 1.0;
  viz_text.color.a = 1.0;

  // Show the segments and the id
  for (std::vector<slg_msgs::msg::Segment>::size_type i = 0; i < segment_list.size(); i++) {
    viz_points.id = i;
    viz_text.id = i;
    viz_centroids.id = i;

    // Change the color of the segment
    std_msgs::msg::ColorRGBA color;
    color.r = 0.90; color.g = 0.8; color.b = 0.2; color.a = 1.0;
    viz_points.color = color;
    viz_centroids.color = color;

    // Iterate over the points of the segment
    slg_msgs::msg::Segment current_segment = segment_list[i];
    for (const auto & point : current_segment.points) {
      viz_points.points.push_back(point);
    }

    // Push to arrays
    viz_array.markers.push_back(viz_points);

    // Clear markers
    viz_points.points.clear();
  }
  return viz_array;
}
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::CollisionAvoidance)
