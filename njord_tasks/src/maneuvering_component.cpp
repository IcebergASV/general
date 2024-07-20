#include "njord_tasks/maneuvering_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"
namespace njord_tasks
{
  Maneuvering::Maneuvering(const rclcpp::NodeOptions & options)
  : Node("maneuvering", options)
  {
    state_sub_ = this->create_subscription<mavros_msgs::msg::State>("/mavros/state", 10, std::bind(&Maneuvering::stateCallback, this, _1));

    Maneuvering::getParam<int>("wait_time", p_wait_time_, 0, "Time to wait in miliseconds");
    Maneuvering::getParam<double>("speed_factor", p_speed_factor_, 0.0, "Used to scale robot speed by this factor");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&Maneuvering::param_callback, this, std::placeholders::_1));

    in_guided_ = false;
  }

  rcl_interfaces::msg::SetParametersResult Maneuvering::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
   rcl_interfaces::msg::SetParametersResult result;

   if (params[0].get_name() == "wait_time") { p_wait_time_ = params[0].as_int(); }
   else if (params[0].get_name() == "speed_factor") { p_speed_factor_ = params[0].as_double(); }
   else {
     RCLCPP_ERROR(this->get_logger(), "Invalid Param");
     result.successful = false;
     return result;
   }

   result.successful = true;
   return result;
  }

  void Maneuvering::stateCallback(const mavros_msgs::msg::State::SharedPtr msg)
  {
    mavros_msgs::msg::State current_state = *msg;
    in_guided_ = task_lib::inGuided(current_state);
    if (in_guided_)
    {
      RCLCPP_INFO(this->get_logger(), "In GUIDED mode, starting Maneuvering task");
      state_sub_.reset();
    }
    else 
    {
      RCLCPP_INFO(this->get_logger(), "Waiting for GUIDED, currently in %s mode.", current_state.mode.c_str());
    }
    return;
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::Maneuvering)
