#include <memory>

#include "utils/retrace_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto mavros_retrace = std::make_shared<comp_tasks::MavRosRetrace>(options);
  
  exec.add_node(mavros_retrace->get_node_base_interface());
  exec.spin();

  rclcpp::shutdown();

  return 0;
}