#include <memory>

#include "perception/coord_finder_component.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto coord_finder = std::make_shared<perception::CoordFinder>(options);
  
  exec.add_node(coord_finder);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}