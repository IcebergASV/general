#include "comp_tasks/docking_component.hpp"

namespace comp_tasks
{
    namespace {
        constexpr double DOCK_WIDTH = 1.5;  // meters (60 inches)
        constexpr double WIDTH_TOLERANCE = 0.2;  // meters of tolerance
        constexpr double MIN_GAP_WIDTH = DOCK_WIDTH - WIDTH_TOLERANCE;
        constexpr double MAX_GAP_WIDTH = DOCK_WIDTH + WIDTH_TOLERANCE;
        constexpr double DOCK_DEPTH = 2.0;  // meters (80 inches)
        constexpr double DOCK_WALL_MIN_POINTS = 5;  // Minimum points needed to confirm a wall, arbitrary value for now
        
        enum class DebugLevel {
            MINIMAL = 0,
            NORMAL = 1,
            VERBOSE = 2
        };
    }

    Docking::Docking(const rclcpp::NodeOptions & options)
    : Task(options, "docking"), status_(DockingStates::APPROACHING)
    {
        // Initialize parameters
        Docking::getParam<double>("approach_distance", p_approach_distance_, 5.0, "Distance to maintain while approaching dock");
        Docking::getParam<double>("dock_depth", p_dock_depth_, 2.0, "How far to go into dock");
        Docking::getParam<double>("reverse_distance", p_reverse_distance_, 3.0, "How far to reverse after docking");
        Docking::getStringParam("target_dock", p_target_dock_, "center", "Which dock to enter (left/center/right)");
        Docking::getParam<int>("debug_level", p_debug_level_, 1, "Debug level (0=minimal, 1=normal, 2=verbose)");

        // Set logger level based on debug_level
        if (p_debug_level_ > 0) {
            this->get_logger().set_level(rclcpp::Logger::Level::Debug);
        }

        // Initialize subscribers
        lidar_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, std::bind(&Docking::lidarCallback, this, std::placeholders::_1));
        
        dock_location_sub_ = this->create_subscription<std_msgs::msg::String>(
            "/dock_location", 10, std::bind(&Docking::dockLocationCallback, this, std::placeholders::_1));

        on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(
            std::bind(&Docking::param_callback, this, std::placeholders::_1));

        // Add visualization publisher
        viz_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(
            "dock_debug_markers", 10);
    }

    void Docking::lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) 
    {
        current_lidar_data_ = msg->ranges;
    }

    void Docking::dockLocationCallback(const std_msgs::msg::String::SharedPtr msg) 
    {
        p_target_dock_ = msg->data;
        RCLCPP_INFO(this->get_logger(), "Target dock set to: %s", p_target_dock_.c_str());
    }

    void Docking::taskLogic(const yolov8_msgs::msg::DetectionArray& detections) 
    {
        if (!in_guided_) {
            debugLog("Not in guided mode", DebugLevel::VERBOSE);
            return;
        }

        switch (status_) {
            case DockingStates::APPROACHING: {
                debugLog("State: APPROACHING", DebugLevel::NORMAL);
                publishBehaviourStatus("Approaching dock");
                
                if (isDockDetected()) {
                    debugLog("Dock detected, calculating waypoint", DebugLevel::NORMAL);
                    auto waypoint = calculateDockingWaypoint();
                    debugLog("Publishing waypoint: x=" + std::to_string(waypoint.pose.position.x) + 
                            ", y=" + std::to_string(waypoint.pose.position.y), DebugLevel::VERBOSE);
                    local_wp_pub_->publish(waypoint);
                    status_ = DockingStates::ALIGNING;
                } else {
                    debugLog("No dock detected, executing recovery", DebugLevel::NORMAL);
                    executeRecoveryBehaviour();
                }
                break;
            }

            case DockingStates::ALIGNING: {
                publishBehaviourStatus("Aligning with " + p_target_dock_ + " dock");
                
                if (wp_reached_) {
                    if (analyzeLidarData()) {
                        status_ = DockingStates::ENTERING;
                    } else {
                        // Recalculate alignment
                        auto waypoint = calculateDockingWaypoint();
                        local_wp_pub_->publish(waypoint);
                    }
                }
                break;
            }

            case DockingStates::ENTERING: {
                publishBehaviourStatus("Entering dock");
                
                if (wp_reached_) {
                    status_ = DockingStates::DOCKED;
                    setTimerDuration(5.0);  // Wait 5 seconds in dock
                }
                break;
            }

            case DockingStates::DOCKED: {
                publishBehaviourStatus("Docked");
                
                if (timer_expired_) {
                    status_ = DockingStates::REVERSING;
                    // Calculate and publish reverse waypoint
                    // ... (implement reverse waypoint calculation)
                }
                break;
            }

            case DockingStates::REVERSING: {
                publishBehaviourStatus("Reversing from dock");
                
                if (wp_reached_) {
                    status_ = DockingStates::COMPLETED;
                    signalTaskFinish();
                }
                break;
            }

            case DockingStates::COMPLETED: {
                publishBehaviourStatus("Docking completed");
                break;
            }
        }
    }

    // Helper function to find gaps in LIDAR data that could represent dock entrances
    struct DockGap {
        size_t start_idx;
        size_t end_idx;
        double width;
        double center_angle;
    };

    // Update the findDockGaps function to also validate dock structure
    struct DockStructure {
        DockGap gap;
        bool has_left_wall;
        bool has_right_wall;
        double left_wall_distance;
        double right_wall_distance;
    };

    std::vector<DockStructure> findDockStructures(const std::vector<float>& lidar_data, 
                                                const sensor_msgs::msg::LaserScan::SharedPtr& scan_msg) 
    {
        // TODO: This function may need work.
        std::vector<DockStructure> dock_structures;
        size_t gap_start = 0;
        bool in_gap = false;

        auto isWall = [&](size_t start, size_t end) -> std::pair<bool, double> {
            if (end - start < DOCK_WALL_MIN_POINTS) return {false, 0.0};
            
            double avg_distance = 0.0;
            int valid_points = 0;
            
            for (size_t i = start; i < end; i++) {
                if (lidar_data[i] < scan_msg->range_max) {
                    avg_distance += lidar_data[i];
                    valid_points++;
                }
            }
            
            if (valid_points < DOCK_WALL_MIN_POINTS) return {false, 0.0};
            avg_distance /= valid_points;
            
            return {true, avg_distance};
        };

        for (size_t i = 0; i < lidar_data.size(); i++) {
            if (!in_gap && lidar_data[i] > DOCK_DEPTH) {  // Potential gap start
                gap_start = i;
                in_gap = true;
            } else if (in_gap && lidar_data[i] <= DOCK_DEPTH) {  // Gap end
                double angle_span = (i - gap_start) * scan_msg->angle_increment;
                double avg_distance = std::accumulate(&lidar_data[gap_start], &lidar_data[i], 0.0) / (i - gap_start);
                double width = 2 * avg_distance * sin(angle_span / 2);
                
                if (width >= MIN_GAP_WIDTH && width <= MAX_GAP_WIDTH) {
                    // Check for walls on both sides
                    size_t wall_check_size = 10;  // Number of points to check for walls
                    auto [left_wall, left_dist] = isWall(gap_start - wall_check_size, gap_start);
                    auto [right_wall, right_dist] = isWall(i, i + wall_check_size);
                    
                    double center_angle = scan_msg->angle_min + 
                        (gap_start + (i - gap_start)/2) * scan_msg->angle_increment;
                    
                    DockStructure structure {
                        {gap_start, i, width, center_angle},  // gap
                        left_wall,                            // has_left_wall
                        right_wall,                           // has_right_wall
                        left_dist,                            // left_wall_distance
                        right_dist                            // right_wall_distance
                    };
                    
                    dock_structures.push_back(structure);
                }
                in_gap = false;
            }
        }
        return dock_structures;
    }

    bool Docking::isDockDetected() 
    {
        if (current_lidar_data_.empty()) {
            debugLog("No LIDAR data available", DebugLevel::NORMAL);
            return false;
        }

        auto scan_msg = lidar_sub_->get_last_message();
        if (!scan_msg) {
            debugLog("No LIDAR scan message", DebugLevel::NORMAL);
            return false;
        }

        debugLog("Processing LIDAR data with " + std::to_string(current_lidar_data_.size()) + 
                " points", DebugLevel::VERBOSE);

        current_dock_structures_ = findDockStructures(current_lidar_data_, scan_msg);
        
        if (!current_dock_structures_.empty()) {
            debugLog("Found " + std::to_string(current_dock_structures_.size()) + 
                    " potential dock structures", DebugLevel::NORMAL);
            for (size_t i = 0; i < current_dock_structures_.size(); i++) {
                const auto& dock = current_dock_structures_[i];
                debugLog("Dock " + std::to_string(i) + ": width=" + 
                        std::to_string(dock.gap.width) + "m, angle=" + 
                        std::to_string(dock.gap.center_angle * 180/M_PI) + "deg", 
                        DebugLevel::VERBOSE);
            }
        } else {
            debugLog("No dock structures found", DebugLevel::NORMAL);
        }

        publishDebugMarkers();
        return !current_dock_structures_.empty();
    }

    bool Docking::analyzeLidarData() 
    {
        if (current_dock_structures_.empty()) {
            debugLog("No dock structures to analyze", DebugLevel::NORMAL);
            return false;
        }

        // Find the appropriate dock based on target_dock_
        int target_index = 0;
        if (p_target_dock_ == "left") {
            target_index = 0;
        } else if (p_target_dock_ == "center") {
            target_index = current_dock_structures_.size() / 2;
        } else if (p_target_dock_ == "right") {
            target_index = current_dock_structures_.size() - 1;
        }

        if (target_index >= current_dock_structures_.size()) {
            return false;
        }

        const auto& target_dock = current_dock_structures_[target_index];
        
        // Verify dock structure is valid
        if (!target_dock.has_left_wall || !target_dock.has_right_wall) {
            debugLog("Missing walls - Left: " + std::to_string(target_dock.has_left_wall) + 
                    ", Right: " + std::to_string(target_dock.has_right_wall), DebugLevel::NORMAL);
            return false;
        }

        // Check if walls are roughly equal distance (parallel)
        const double WALL_DISTANCE_TOLERANCE = 0.3;  // meters
        double wall_diff = std::abs(target_dock.left_wall_distance - target_dock.right_wall_distance);
        debugLog("Wall distance difference: " + std::to_string(wall_diff) + "m", DebugLevel::VERBOSE);

        if (wall_diff > WALL_DISTANCE_TOLERANCE) {
            debugLog("Walls not parallel, difference: " + std::to_string(wall_diff) + "m", DebugLevel::NORMAL);
            return false;
        }

        // Check alignment
        const double ALIGNMENT_THRESHOLD = 0.1;  // radians
        double alignment = std::abs(target_dock.gap.center_angle);
        debugLog("Current alignment: " + std::to_string(alignment * 180/M_PI) + " degrees", DebugLevel::VERBOSE);

        return alignment < ALIGNMENT_THRESHOLD;
    }

    geometry_msgs::msg::PoseStamped Docking::calculateDockingWaypoint() 
    {
        // TODO: This function may need work.
        geometry_msgs::msg::PoseStamped waypoint;
        waypoint.header.frame_id = "map";
        waypoint.header.stamp = this->now();

        if (current_dock_structures_.empty()) {
            return waypoint;
        }

        // Select target dock
        int target_index = 0;
        if (p_target_dock_ == "left") {
            target_index = 0;
        } else if (p_target_dock_ == "center") {
            target_index = current_dock_structures_.size() / 2;
        } else if (p_target_dock_ == "right") {
            target_index = current_dock_structures_.size() - 1;
        }

        if (target_index >= current_dock_structures_.size()) {
            return waypoint;
        }

        const auto& target_dock = current_dock_structures_[target_index];
        
        // Calculate position based on current state
        double distance = 0.0;
        switch (status_) {
            case DockingStates::APPROACHING:
                distance = p_approach_distance_;
                break;
            case DockingStates::ALIGNING:
                // Use the average of wall distances for better alignment
                distance = (target_dock.left_wall_distance + target_dock.right_wall_distance) / 2.0;
                break;
            case DockingStates::ENTERING:
                distance = -DOCK_DEPTH * 0.8;  // Go 80% of dock depth
                break;
            case DockingStates::REVERSING:
                distance = p_reverse_distance_;
                break;
            default:
                return waypoint;
        }

        // Convert polar coordinates (distance, angle) to cartesian
        double x = distance * cos(target_dock.gap.center_angle);
        double y = distance * sin(target_dock.gap.center_angle);

        waypoint.pose.position.x = x;
        waypoint.pose.position.y = y;

        // Set orientation to face the dock
        tf2::Quaternion q;
        q.setRPY(0, 0, target_dock.gap.center_angle);
        waypoint.pose.orientation = tf2::toMsg(q);

        return waypoint;
    }

    rcl_interfaces::msg::SetParametersResult Docking::param_callback(
        const std::vector<rclcpp::Parameter> &params) 
    {
        rcl_interfaces::msg::SetParametersResult result;
        result.successful = true;

        for (const auto& param : params) {
            if (param.get_name() == "approach_distance") {
                p_approach_distance_ = param.as_double();
            } else if (param.get_name() == "dock_depth") {
                p_dock_depth_ = param.as_double();
            } else if (param.get_name() == "reverse_distance") {
                p_reverse_distance_ = param.as_double();
            } else if (param.get_name() == "target_dock") {
                p_target_dock_ = param.as_string();
            }
        }

        return result;
    }

    void Docking::publishDebugMarkers()
    {
        visualization_msgs::msg::MarkerArray marker_array;
        
        // Create markers for each dock structure
        for (size_t i = 0; i < current_dock_structures_.size(); i++) {
            const auto& dock = current_dock_structures_[i];
            
            // Marker for dock entrance
            visualization_msgs::msg::Marker entrance_marker;
            entrance_marker.header.frame_id = "laser";  // or whatever frame your LIDAR uses
            entrance_marker.header.stamp = this->now();
            entrance_marker.ns = "dock_entrances";
            entrance_marker.id = i;
            entrance_marker.type = visualization_msgs::msg::Marker::CUBE;
            entrance_marker.action = visualization_msgs::msg::Marker::ADD;
            
            // Set position based on LIDAR data
            entrance_marker.pose.position.x = dock.gap.width/2 * cos(dock.gap.center_angle);
            entrance_marker.pose.position.y = dock.gap.width/2 * sin(dock.gap.center_angle);
            entrance_marker.pose.position.z = 0;
            
            // Set size
            entrance_marker.scale.x = 0.2;  // thickness
            entrance_marker.scale.y = dock.gap.width;
            entrance_marker.scale.z = 1.0;  // height
            
            // Color (green for target dock, blue for others)
            entrance_marker.color.a = 0.5;  // semi-transparent
            if (i == getCurrentTargetDockIndex()) {
                entrance_marker.color.g = 1.0;  // green
            } else {
                entrance_marker.color.b = 1.0;  // blue
            }
            
            marker_array.markers.push_back(entrance_marker);
            
            // Add wall markers
            if (dock.has_left_wall) {
                visualization_msgs::msg::Marker wall_marker;
                // Similar setup as entrance marker
                wall_marker.ns = "dock_walls";
                wall_marker.color.r = 1.0;  // red for walls
                // Position and orientation based on LIDAR data
                marker_array.markers.push_back(wall_marker);
            }
            
            // Add planned waypoint marker
            if (i == getCurrentTargetDockIndex()) {
                visualization_msgs::msg::Marker waypoint_marker;
                waypoint_marker.type = visualization_msgs::msg::Marker::ARROW;
                waypoint_marker.ns = "waypoints";
                waypoint_marker.color.g = 1.0;
                // Position and orientation from calculateDockingWaypoint()
                marker_array.markers.push_back(waypoint_marker);
            }
        }
        
        viz_pub_->publish(marker_array);
    }

    // Helper function for debug logging
    void debugLog(const std::string& msg, DebugLevel level = DebugLevel::NORMAL) {
        if (p_debug_level_ >= static_cast<int>(level)) {
            RCLCPP_DEBUG(this->get_logger(), msg.c_str());
        }
    }
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Docking)
