#include <memory>

#include "comp_tasks/nav_channel_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto nav_channel = std::make_shared<comp_tasks::NavChannel>(options);
  
  exec.add_node(nav_channel);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
