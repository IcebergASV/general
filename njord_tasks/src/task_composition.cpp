#include <memory>

#include "njord_tasks/task_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto task = std::make_shared<njord_tasks::Task>(options);
  
  exec.add_node(task);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
