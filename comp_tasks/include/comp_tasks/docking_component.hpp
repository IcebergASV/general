#ifndef docking_HPP
#define docking_HPP

#include <rclcpp/rclcpp.hpp>
#include <comp_tasks/task_component.hpp>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace comp_tasks
{

// Forward declare the structure
struct DockGap {
    size_t start_idx;
    size_t end_idx;
    double width;
    double center_angle;
};

struct DockStructure {
    DockGap gap;
    bool has_left_wall;
    bool has_right_wall;
    double left_wall_distance;
    double right_wall_distance;
};

class Docking : public comp_tasks::Task
{
public:
    explicit Docking(const rclcpp::NodeOptions & options);

private:
    void taskLogic(const yolov8_msgs::msg::DetectionArray& detections) override;
    void lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void dockLocationCallback(const std_msgs::msg::String::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params) override;
    
    // Subscribers
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr lidar_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr dock_location_sub_;
    
    // Parameters
    double p_approach_distance_;     // Distance to maintain while approaching
    double p_dock_depth_;           // How far to go into dock
    double p_reverse_distance_;     // How far to reverse after docking
    std::string p_target_dock_;     // Left, Center, Right
    
    // State machine
    enum class DockingStates {
        APPROACHING,    // Moving toward dock entrance
        ALIGNING,      // Aligning with specific dock
        ENTERING,      // Moving into dock
        DOCKED,        // Successfully in dock
        REVERSING,     // Backing out
        COMPLETED      // Task done
    };
    DockingStates status_;
    
    // Lidar data processing
    std::vector<float> current_lidar_data_;
    std::vector<DockStructure> current_dock_structures_;
    bool analyzeLidarData();
    bool isDockDetected();
    geometry_msgs::msg::PoseStamped calculateDockingWaypoint();

    // Add publisher
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr viz_pub_;
    
    // Add helper function
    void publishDebugMarkers();
};

} // namespace comp_tasks

#endif // docking_HPP
