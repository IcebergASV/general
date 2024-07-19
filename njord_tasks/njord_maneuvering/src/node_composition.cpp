#include <memory>

#include "njord_maneuvering/maneuvering_node.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log msgs without buffering

    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto maneuvering_node = std::make_shared<njord_maneuvering::ManeuveringNode>(options);
    
    exec.add_node(maneuvering_node);
    exec.spin();

    rclcpp::shutdown();

    return 0;
}