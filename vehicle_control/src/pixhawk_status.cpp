#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"

using std::placeholders::_1; // cpp thing

class PixhawkStatus : public rclcpp::Node
{
  public:
    PixhawkStatus()
    : Node("pixhawk_status"), previous_guided_state_(std::nullopt)
    {
        subscription_ = this->create_subscription<mavros_msgs::msg::State>(
            "/mavros/state",
            10,
            [this](const mavros_msgs::msg::State::SharedPtr msg) {
                toggle_callback(msg);
            });
    }

  private:

    void toggle_callback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        bool current_guided_state = msg->guided;
        if (previous_guided_state_ && current_guided_state != *previous_guided_state_)
        {
            if (current_guided_state)
            {
                RCLCPP_INFO(this->get_logger(), "Guided mode: true");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Guided mode: false");
            }
        }
        previous_guided_state_ = current_guided_state;
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr subscription_;
    std::optional<bool> previous_guided_state_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PixhawkStatus>());
  rclcpp::shutdown();
  return 0;
}