#include <memory>

#include "comp_tasks/task_controller_component.hpp"
#include "rclcpp/rclcpp.hpp"

void wake_executor(std::shared_future<void> future, rclcpp::executors::SingleThreadedExecutor & exec)
{
  future.wait();
  // Wake the executor when the script is done
  // https://github.com/ros2/rclcpp/issues/1916
  exec.cancel();
}

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto task_controller = std::make_shared<comp_tasks::TaskController>(options);
  exec.add_node(task_controller);

  std::shared_future<void> script = std::async(
    std::launch::async,
    std::bind(comp_tasks::callee_script, task_controller));

  auto wake_exec = std::async(
    std::launch::async,
    std::bind(wake_executor, script, std::ref(exec)));

  exec.spin_until_future_complete(script);

  rclcpp::shutdown();

  return 0;
}
