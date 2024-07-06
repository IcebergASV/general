#include <memory>

#include "perception/mock_coord_pub_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto mock_coord_pub = std::make_shared<perception::MockCoordPub>(options);
  
  exec.add_node(mock_coord_pub);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}