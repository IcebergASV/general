#ifndef gate_coord_finder_HPP
#define gate_coord_finder_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "perception_interfaces/msg/gate.hpp"
#include "perception_interfaces/msg/prop.hpp"
#include "perception_interfaces/msg/prop_array.hpp"

using std::placeholders::_1;

namespace perception
{

class GateCoordFinder : public rclcpp::Node
{
public:
    explicit GateCoordFinder(const rclcpp::NodeOptions & options);

private:
    void gateCallback(const perception_interfaces::msg::Gate::SharedPtr msg);
    void poseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    bool isValidLabel(std::string label);
    perception_interfaces::msg::Prop relativeToLocalCoords(perception_interfaces::msg::Prop relative_prop);

    geometry_msgs::msg::PoseStamped pose_msg_;
    perception_interfaces::msg::Gate gate_msg_;

    rclcpp::Subscription<perception_interfaces::msg::Gate>::SharedPtr gate_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;

    rclcpp::Publisher<perception_interfaces::msg::Gate>::SharedPtr gate_coords_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    bool new_gate_;
  
};

} // namespace perception

#endif // gate_coord_finder_HPP
