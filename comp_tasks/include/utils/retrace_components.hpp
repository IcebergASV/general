#ifndef retrace_HPP
#define retrace_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <task_component.hpp>

using std::placeholders::_1;

namespace comp_tasks
{

class Retrace : public comp_tasks::Task
{
public:
    explicit Retrace(const rclcpp::NodeOptions & options);

private:
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &) override;
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    void executeRecoveryBehaviour() override;
    void taskLogic(const int standin) override;
    void checkIfFinished();

    void setState(std::string str_state);
    
    int p_max_consec_recoveries_;
    std::string p_state_;
    double gate_y_;
    int number_of_nodes;
    
};

} // namespace comp_tasks

#endif // retrace_HPP
