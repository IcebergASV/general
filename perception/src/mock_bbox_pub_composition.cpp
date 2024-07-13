#include <memory>

#include "perception/mock_bbox_pub_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto mock_bbox_pub = std::make_shared<perception::MockBBoxPub>(options);
  
  exec.add_node(mock_bbox_pub);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}