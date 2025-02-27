#include <memory>

#include "comp_tasks/buoy_counter_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto buoy_counter = std::make_shared<comp_tasks::BuoyCounter>(options);
  
  exec.add_node(buoy_counter);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
