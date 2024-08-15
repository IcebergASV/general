#include <memory>

#include "njord_tasks/wp_sender_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto wp_sender = std::make_shared<njord_tasks::WPSender>(options);
  
  exec.add_node(wp_sender);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
