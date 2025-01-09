#include <memory>

#include "comp_tasks/test_life_cycle_node_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto test_life_cycle_node = std::make_shared<comp_tasks::TestLifeCycleNode>(options);
  
  exec.add_node(test_life_cycle_node->get_node_base_interface());
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
