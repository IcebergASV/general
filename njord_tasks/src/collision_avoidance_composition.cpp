#include <memory>

#include "njord_tasks/collision_avoidance_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto collision_avoidance = std::make_shared<njord_tasks::CollisionAvoidance>(options);
  
  exec.add_node(collision_avoidance);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
