#include <memory>

#include "comp_tasks/task_controller_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto task_controller = std::make_shared<comp_tasks::TaskController>(options);
  task_controller->configureNextTask();
  task_controller->runTask();
  exec.add_node(task_controller);
  exec.spin();


  rclcpp::shutdown();

  return 0;
}
