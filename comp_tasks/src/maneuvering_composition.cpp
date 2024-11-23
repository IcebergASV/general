#include <memory>

#include "comp_tasks/maneuvering_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto maneuvering = std::make_shared<comp_tasks::Maneuvering>(options);
  
  exec.add_node(maneuvering);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
