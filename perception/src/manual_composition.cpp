#include <memory>

#include "perception/lidar_prop_detector_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto lidar_clusterer = std::make_shared<perception::LidarPropDetector>(options);
  exec.add_node(lidar_clusterer);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}