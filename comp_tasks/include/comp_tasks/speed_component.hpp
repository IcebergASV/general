#ifndef speed_HPP
#define speed_HPP

#include <rclcpp/rclcpp.hpp>
#include <comp_tasks/task_component.hpp>
#include "yolov8_msgs/msg/detection_array.hpp"
#include "geometry_msgs/msg/point.hpp"

using std::placeholders::_1;

namespace comp_tasks
{

class Speed : public comp_tasks::Task
{
public:
    explicit Speed(const rclcpp::NodeOptions & options);

private:
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    void sendNextWP(std::vector<geometry_msgs::msg::Point> route, std::string route_name);
    std::vector<geometry_msgs::msg::Point> calculateReturnRoute(const yolov8_msgs::msg::DetectionArray& detections);
    std::vector<geometry_msgs::msg::Point> calculateRouteFromGates(const yolov8_msgs::msg::DetectionArray& detections);
    void handleBlueBuoyDetections(const yolov8_msgs::msg::DetectionArray& detections);
    void handleGateDetections(const yolov8_msgs::msg::DetectionArray& detections);
    double getDistFromBay();
    void continuePastBuoy();
    bool isFarEnoughFromBay();
    void updateReturnRoute(std::vector<geometry_msgs::msg::Point>& route);
    
    int p_use_start_point_;
    double p_time_to_find_bay_;
    double p_max_time_between_bay_detections_;
    double p_max_time_between_buoy_detections_;
    double p_buoy_offset_angle_;
    double p_estimated_buoy_dist_;
    double p_buoy_circling_radius_;
    int p_num_pnts_on_semicircle_;
    double p_min_dist_from_bay_b4_return_;

    enum States {SENDING_START_PNT, GOING_TO_BAY, MANEUVER_THRU_BAY, CALCULATED_ROUTE, PASSING_BUOY, CONTINUE_PASSING_BUOY, RETURNING }; 
    States status_;

    std::vector<geometry_msgs::msg::Point> calculated_route_;
    std::vector<geometry_msgs::msg::Point> return_route_;
    geometry_msgs::msg::PoseStamped last_seen_bay_pose_;
    geometry_msgs::msg::PoseStamped last_seen_blue_buoy_pose_;
    geometry_msgs::msg::PoseStamped continue_past_buoys_pnt_;
    bool passed_buoy_left_;

};

} // namespace comp_tasks

#endif // speed_HPP
