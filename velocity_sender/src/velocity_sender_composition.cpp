// #include <memory>

// #include "velocity_sender/velocity_sender_component.hpp"
// #include "rclcpp/rclcpp.hpp"

// int main(int argc, char *argv[]) 
// {
//   setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

//   rclcpp::init(argc, argv);

//   rclcpp::executors::SingleThreadedExecutor exec;
//   rclcpp::NodeOptions options;

//   auto velocity_sender = std::make_shared<velocity_sender::VelocitySender>(options);
  
//   exec.add_node(velocity_sender);
//   exec.spin();

//   rclcpp::shutdown();

//   return 0;
// }
