#include <memory>

#include "comp_tasks/docking_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto docking = std::make_shared<comp_tasks::Docking>(options);
  
  exec.add_node(docking);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
