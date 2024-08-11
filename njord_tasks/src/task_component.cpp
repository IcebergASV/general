#include "njord_tasks/task_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"
namespace njord_tasks
{
  Task::Task(const rclcpp::NodeOptions & options)
  : Node("task", options)
  {
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&Task::stateCallback, this, _1));
    pose_sub_ = this->create_subscription<geographic_msgs::msg::GeoPoseStamped>("/mavros/global_position/pose", qos, std::bind(&Task::poseCallback, this, _1));
    wp_reached_sub_ = this->create_subscription<mavros_msgs::msg::WaypointReached>("/mavros/mission/reached", 10, std::bind(&Task::wpReachedCallback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&Task::timerCallback, this));
    wp_pub_ = this->create_publisher<geographic_msgs::msg::GeoPoseStamped>("/mavros/setpoint_position/global", 10);
    start_task_pub_ = this->create_publisher<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10);
    task_complete_sub_ = this->create_subscription<std_msgs::msg::Int32>("/njord_tasks/task_completion_status", 10, std::bind(&Task::taskStatusCallback, this, _1));
    Task::getParam<int>("wait_time", p_wait_time_, 0, "Time to wait in miliseconds");
    Task::getParam<double>("global_wp_reached_rad", p_global_wp_reached_rad_, 0.0, "Global waypoint reached radius in meters");
    Task::getParam<double>("start_lat", p_start_lat_, 0.0, "Starting latitude");
    Task::getParam<double>("start_lon", p_start_lon_, 0.0, "Starting longitude");
    Task::getParam<double>("finish_lat", p_finish_lat_, 0.0, "Finish latitude");
    Task::getParam<double>("finish_lon", p_finish_lon_, 0.0, "Finish longitude");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Task::param_callback, this, std::placeholders::_1));

    in_guided_ = false;
    wp_reached_ = false;
    task_complete_ = false;
  }

  void Task::wait()
  {
    rclcpp::Rate rate(1);
    rate.sleep();
  }

  rcl_interfaces::msg::SetParametersResult Task::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "wait_time") { p_wait_time_ = params[0].as_int(); }
    else if (params[0].get_name() == "global_wp_reached_rad") { p_global_wp_reached_rad_ = params[0].as_double(); }
    else if (params[0].get_name() == "start_lat") { p_start_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "start_lon") { p_start_lon_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lat") { p_finish_lat_ = params[0].as_double(); }
    else if (params[0].get_name() == "finish_lon") { p_finish_lon_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void Task::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    in_guided_ = task_lib::inGuided(current_state);
    if (in_guided_)
    {
      RCLCPP_INFO_ONCE(this->get_logger(), "In Guided Mode");
      state_sub_.reset();
    }
    else 
    {
      RCLCPP_INFO_ONCE(this->get_logger(), "Waiting for GUIDED, currently in %s mode.", current_state.mode.c_str());
    }
    return;
  }

  void Task::poseCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg)
  {
    current_global_pose_ = *msg;
    // Extract latitude and longitude from the message
    double latitude = msg->pose.position.latitude;
    double longitude = msg->pose.position.longitude;

    // Log the values
    RCLCPP_INFO(this->get_logger(), "Latitude: %f, Longitude: %f", latitude, longitude);
  }

  void Task::publishGlobalWP(double lat, double lon)
  {
    geographic_msgs::msg::GeoPoseStamped msg;
    msg.header.stamp = this->get_clock()->now();
    msg.header.frame_id = "map";  // or use an appropriate frame_id

    msg.pose.position.latitude = lat;
    msg.pose.position.longitude = lon;
    wp_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Published GeoPose: lat=%.6f, lon=%.6f", msg.pose.position.latitude, msg.pose.position.longitude);
  }
  void Task::wpReachedCallback(const mavros_msgs::msg::WaypointReached msg)
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
    mavros_msgs::msg::WaypointReached wpr = msg;
    wp_reached_ = true;
  }

  void Task::taskStatusCallback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    if (msg->data == 1)
    {
      task_complete_ = true;
      RCLCPP_INFO(this->get_logger(), "Task complete with success");
    }
    else{
      RCLCPP_INFO(this->get_logger(), "Task failed");
    }      
  }

  void Task::publishStartTaskSignal()
  {
    njord_tasks_interfaces::msg::StartTask start_task;
    start_task.task.current_task = njord_tasks_interfaces::msg::Task::MANEUVERING;
    start_task.start_pnt.latitude = p_start_lat_;
    start_task.start_pnt.longitude = p_start_lon_;
    start_task.finish_pnt.latitude = p_finish_lat_;
    start_task.finish_pnt.longitude = p_finish_lon_;
    start_task_pub_->publish(start_task);
  }
  
  void Task::timerCallback()
  {
    RCLCPP_DEBUG(this->get_logger(), "timerCallback");
    switch (status_)
    {
    case States::WAIT_FOR_GUIDED:
    {
      if (in_guided_)
      {
        RCLCPP_INFO(this->get_logger(), "In GUIDED mode, Starting task");
        //publishGlobalWP(p_start_lat_, p_start_lon_);

        status_ = States::TASK;
      }
      else 
      {
        wait();
      }
      break;
    }

    case States::WAIT_TO_REACH_START:
    {
      if (wp_reached_)
      {
        wp_reached_ = false;
        RCLCPP_INFO(this->get_logger(), "Reached start point, starting task");
        publishStartTaskSignal();
        status_ = States::TASK;
      }
      else 
      {
        RCLCPP_INFO_ONCE(this->get_logger(), "Waiting to reach start point"); // TODO Add in distance to start point
        wait();
      }
      break;
    }

    case States::TASK:
    {
      if(task_complete_)
      {
        RCLCPP_INFO(this->get_logger(), "Heading to finish point");
        publishGlobalWP(p_finish_lat_, p_finish_lon_);
        status_ = States::WAIT_TO_REACH_FINISH;
      }
      else 
      {
        RCLCPP_INFO_ONCE(this->get_logger(), "Waiting for task to complete");
        wait();
      }
      break;
    }

    case States::WAIT_TO_REACH_FINISH:
    {
      if (wp_reached_)
      {
        wp_reached_ = false;
        RCLCPP_INFO(this->get_logger(), "Reached finish point, task complete!");
        status_ = States::COMPLETE;
      }
      else 
      {
        RCLCPP_INFO_ONCE(this->get_logger(), "Waiting to reach finish point"); // TODO Add in distance to start point
        wait();
      }
      break;
    }

    case States::COMPLETE:
    {
      RCLCPP_INFO_ONCE(this->get_logger(), "Complete!");
    }
  }
  }

}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Task)
