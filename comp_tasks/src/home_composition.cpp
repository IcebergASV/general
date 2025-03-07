#include <memory>

#include "comp_tasks/home_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto home = std::make_shared<comp_tasks::Home>(options);
  
  exec.add_node(home->get_node_base_interface());
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
