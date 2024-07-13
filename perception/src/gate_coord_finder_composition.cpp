#include <memory>

#include "perception/gate_coord_finder_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto gate_coord_finder = std::make_shared<perception::GateCoordFinder>(options);
  
  exec.add_node(gate_coord_finder);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
