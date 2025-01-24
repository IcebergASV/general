#include "comp_tasks/task_controller_component.hpp"

namespace comp_tasks
{
  TaskController::TaskController(const rclcpp::NodeOptions & options)
  : Node("task_controller", options)
  {
    example_sub_ = this->create_subscription<std_msgs::msg::Int32>("/comp_tasks/subscribing_topic", 10, std::bind(&TaskController::callback, this, _1));
    example_pub_ = this->create_publisher<std_msgs::msg::Float64>("comp_tasks/publishing_topic", 10);

    TaskController::getParam<int>("multiplier", p_multiplier_, 0, "Multiplies number by this integer");
    TaskController::getParam<double>("adder", p_adder_, 0, "Adds this double to a number");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&TaskController::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult TaskController::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "multiplier") { p_multiplier_ = params[0].as_int(); }
    else if (params[0].get_name() == "adder") { p_adder_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void TaskController::callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    std_msgs::msg::Float64 new_value;
    new_value.data = msg->data *p_multiplier_ + p_adder_;

    example_pub_->publish(new_value);
  }

  void TaskController::init()
  {
    client_get_state_ = this->create_client<lifecycle_msgs::srv::GetState>("maneuvering/get_state");
    client_change_state_ = this->create_client<lifecycle_msgs::srv::ChangeState>(node_change_state_topic);
  }

  unsigned int TaskController::get_state(std::chrono::seconds time_out)
  {
    auto request = std::make_shared<lifecycle_msgs::srv::GetState::Request>();

    if (!client_get_state_->wait_for_service(time_out)) {
      RCLCPP_ERROR(
        get_logger(),
        "Service %s is not available.",
        client_get_state_->get_service_name());
      return lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    }

    // We send the service request for asking the current
    // state of the lc_talker node.
    auto future_result = client_get_state_->async_send_request(request).future.share();

    // Let's wait until we have the answer from the node.
    // If the request times out, we return an unknown state.
    auto future_status = wait_for_result(future_result, time_out);

    if (future_status != std::future_status::ready) {
      RCLCPP_ERROR(
        get_logger(), "Server time out while getting current state for node %s", lifecycle_node);
      return lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    }

    // We have an succesful answer. So let's print the current state.
    if (future_result.get()) {
      RCLCPP_INFO(
        get_logger(), "Node %s has current state %s.",
        lifecycle_node, future_result.get()->current_state.label.c_str());
      return future_result.get()->current_state.id;
    } else {
      RCLCPP_ERROR(
        get_logger(), "Failed to get current state for node %s", lifecycle_node);
      return lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    }
  }

  bool TaskController::change_state(std::uint8_t transition, std::chrono::seconds time_out)
  {
    auto request = std::make_shared<lifecycle_msgs::srv::ChangeState::Request>();
    request->transition.id = transition;

    if (!client_change_state_->wait_for_service(time_out)) {
      RCLCPP_ERROR(
        get_logger(),
        "Service %s is not available.",
        client_change_state_->get_service_name());
      return false;
    }

    // We send the request with the transition we want to invoke.
    auto future_result = client_change_state_->async_send_request(request).future.share();

    // Let's wait until we have the answer from the node.
    // If the request times out, we return an unknown state.
    auto future_status = wait_for_result(future_result, time_out);

    if (future_status != std::future_status::ready) {
      RCLCPP_ERROR(
        get_logger(), "Server time out while getting current state for node %s", lifecycle_node);
      return false;
    }

    // We have an answer, let's print our success.
    if (future_result.get()->success) {
      RCLCPP_INFO(
        get_logger(), "Transition %d successfully triggered.", static_cast<int>(transition));
      return true;
    } else {
      RCLCPP_WARN(
        get_logger(), "Failed to trigger transition %u", static_cast<unsigned int>(transition));
      return false;
    }
  }

  void TaskController::configureTask(std::string node_name)
  {
    std::string node_get_state_topic = node_name + "/get_state";
    std::string node_change_state_topic = node_name + "/change_state";
  }

    
  
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::TaskController)
