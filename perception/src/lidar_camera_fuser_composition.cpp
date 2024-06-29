#include <memory>

#include "perception/lidar_camera_fuser_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto lidar_camera_fuser = std::make_shared<perception::LidarCameraFuser>(options);
  
  exec.add_node(lidar_camera_fuser);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}