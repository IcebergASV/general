#include "comp_tasks/task_controller_component.hpp"

namespace comp_tasks
{
  TaskController::TaskController(const rclcpp::NodeOptions & options)
  : Node("task_controller", options)
  {
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&TaskController::param_callback, this, std::placeholders::_1));
    TaskController::getStringParam("tasks", p_tasks_, "m", "Tasks and order");
    task_complete_sub_ = this->create_subscription<std_msgs::msg::Bool>("/comp_tasks/task/complete", 10, std::bind(&TaskController::taskCompleteCallback, this, _1));
    setNextNodeName();
  }

  rcl_interfaces::msg::SetParametersResult TaskController::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "tasks") { p_tasks_ = params[0].as_string(); } 
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void TaskController::init(std::string node_name)
  {
    std::string node_get_state_topic = node_name + "/get_state";
    std::string node_change_state_topic = node_name + "/change_state";
    client_get_state_ = this->create_client<lifecycle_msgs::srv::GetState>(node_get_state_topic);
    client_change_state_ = this->create_client<lifecycle_msgs::srv::ChangeState>(node_change_state_topic);
  }

  void TaskController::taskCompleteCallback(const std_msgs::msg::Bool::SharedPtr msg)
  {
    if (msg->data)
    {
      change_state(lifecycle_msgs::msg::Transition::TRANSITION_DEACTIVATE);
      change_state(lifecycle_msgs::msg::Transition::TRANSITION_CLEANUP);
      change_state(lifecycle_msgs::msg::Transition::TRANSITION_UNCONFIGURED_SHUTDOWN);
      if (setNextNodeName())
      {
        configureNextTask();
        runTask();
      }
      else
      {
        RCLCPP_INFO(
        get_logger(),
        "All tasks complete");
      }
    }
    else{
      RCLCPP_ERROR(
        get_logger(),
        "Task complete = False");
    }
    return;
  }

  bool TaskController::setNextNodeName()
  {
    if (p_tasks_.empty()) {
      RCLCPP_INFO(this->get_logger(), "No remaining tasks");
      return false;
    }

    char first_letter = p_tasks_[0]; // Get the first letter
    p_tasks_.erase(0, 1);            // Remove the first letter

    switch (first_letter) {
        case 'm':
            node_name_ = "maneuvering";
            break;
        case 'd':
            node_name_ = "docking";
            break;
        case 's':
            node_name_ = "speed";
            break;
        case 'h':
            node_name_ = "home";
            break;
        default:
        {
            RCLCPP_ERROR(this->get_logger(), "Invalid Node Name");
            return false;
        }
    }
    return true;

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
        get_logger(), "Server time out while getting current state for node %s", node_name_.c_str());
      return lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    }

    // We have an succesful answer. So let's print the current state.
    if (future_result.get()) {
      RCLCPP_INFO(
        get_logger(), "Node %s has current state %s.",
        node_name_.c_str(), future_result.get()->current_state.label.c_str());
      return future_result.get()->current_state.id;
    } else {
      RCLCPP_ERROR(
        get_logger(), "Failed to get current state for node %s", node_name_.c_str());
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
      RCLCPP_WARN(
        get_logger(), "Server time out while getting current state for node %s", node_name_.c_str());
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

  void TaskController::configureNextTask() 
  {
      try {
          init(node_name_);
  
          if (!change_state(lifecycle_msgs::msg::Transition::TRANSITION_CONFIGURE)) {
              RCLCPP_ERROR(get_logger(), "Failed to configure node %s", node_name_.c_str());
              return;
          }
  
          unsigned int state = get_state();
          if (state != lifecycle_msgs::msg::State::PRIMARY_STATE_INACTIVE) {
              RCLCPP_ERROR(get_logger(), "Node %s is not in INACTIVE state after configuration. Current state: %u", node_name_.c_str(), state);
              return;
          }
  
          RCLCPP_INFO(get_logger(), "Node %s successfully configured and is in INACTIVE state.", node_name_.c_str());
      } catch (const std::exception &e) {
          RCLCPP_ERROR(get_logger(), "Exception caught during configureNextTask: %s", e.what());
      } catch (...) {
          RCLCPP_ERROR(get_logger(), "Unknown exception caught during configureNextTask");
      }
  }

  void TaskController::runTask() // TODO add error handling
  {
    if (!change_state(lifecycle_msgs::msg::Transition::TRANSITION_ACTIVATE)) {
      return;
    }
    if (!get_state()) {
      return;
    }
  }

    
  
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::TaskController)
