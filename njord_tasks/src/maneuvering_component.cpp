#include "njord_tasks/maneuvering_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"
void wait()
{
  rclcpp::Rate rate(1);
  rate.sleep();
}
namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&Maneuvering::stateCallback, this, _1));
    //velocity_pub_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&Maneuvering::timerCallback, this));

    Maneuvering::getParam<int>("wait_time", p_wait_time_, 0, "Time to wait in miliseconds");
    Maneuvering::getParam<double>("speed_factor", p_speed_factor_, 0.0, "Used to scale robot speed by this factor");
    Maneuvering::getParam<double>("start_lat", p_start_lat_, 0.0, "Starting latitude");
    Maneuvering::getParam<double>("start_lon", p_start_lon_, 0.0, "Starting longitude");
    Maneuvering::getParam<double>("finish_lat", p_finish_lat_, 0.0, "Finish latitude");
    Maneuvering::getParam<double>("finish_lon", p_finish_lon_, 0.0, "Finish longitude");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    in_guided_ = false;
    status_ = States::WAIT_FOR_GUIDED;
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "wait_time") { p_wait_time_ = params[0].as_int(); }
    else if (params[0].get_name() == "speed_factor") { p_speed_factor_ = params[0].as_double(); }
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
  void Maneuvering::maneuver()
  {
    return;
  }
  void Maneuvering::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    in_guided_ = task_lib::inGuided(current_state);
    if (in_guided_)
    {
      state_sub_.reset();
    }
    else 
    {
      RCLCPP_INFO(this->get_logger(), "Waiting for GUIDED, currently in %s mode.", current_state.mode.c_str());
    }
    return;
  }
  void Maneuvering::timerCallback()
  {
    RCLCPP_DEBUG(this->get_logger(), "timerCallback");
    switch (status_)
    {
    case States::WAIT_FOR_GUIDED:
    {
      if (in_guided_)
      {
        RCLCPP_INFO(this->get_logger(), "In GUIDED mode, Heading to Maneuvering start point");
        // Send start point
        status_ = States::WAIT_TO_REACH_START;
      }
      else 
      {
        wait();
      }
      break;
    }

    case States::WAIT_TO_REACH_START:
    {
      if (task_lib::isReached(p_start_lat_, p_start_lon_, current_global_pose_))
      {
        RCLCPP_INFO(this->get_logger(), "Reached start point, starting to maneuver");
        status_ = States::MANEUVER;
      }
      else 
      {
        RCLCPP_INFO(this->get_logger(), "Waiting to reach start point"); // TODO Add in distance to start point
        wait();
      }
      break;
    }

    case States::MANEUVER:
    {
      if (true)//clear_path_to_finish)
      {
        RCLCPP_INFO(this->get_logger(), "Detected clear path to finish, heading to finish point");
        // send finish point
        status_ = States::WAIT_TO_REACH_FINISH;
      }
      else 
      {
        if (true)//red_marker_to_left_of_green)
        {
          maneuver();
        }
        else 
        {
          RCLCPP_INFO(this->get_logger(), "Unexpected Obstacles detected, waiting for gate to be detected");  // TODO Add more description into what robot sees
          wait();
        }
      }
      break;
    }

    case States::WAIT_TO_REACH_FINISH:
    {
      if (task_lib::isReached(p_finish_lat_, p_finish_lon_, current_global_pose_))
      {
        RCLCPP_INFO(this->get_logger(), "Reached finish point, task complete!");
        status_ = States::COMPLETE;
      }
      else 
      {
        RCLCPP_INFO(this->get_logger(), "Waiting to reach finish point"); // TODO Add in distance to start point
        wait();
      }
      break;
    }

    case States::COMPLETE:
    {
      RCLCPP_INFO(this->get_logger(), "Complete!");
    }
  }






}
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
