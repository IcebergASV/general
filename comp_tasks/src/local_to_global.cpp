#include <rclcpp/rclcpp.hpp>
#include <geographic_msgs/msg/geo_point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <comp_tasks_interfaces/msg/wp_group_info.hpp>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
class LocalToGlobalConverter : public rclcpp::Node {
public:
    LocalToGlobalConverter() : Node("local_to_global_converter") {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

        // Initialize the ENU converter with a default reference origin
        enu_converter_ = std::make_unique<GeographicLib::LocalCartesian>(
            lat_ref_, lon_ref_, alt_ref_, GeographicLib::Geocentric::WGS84()
        );

        // Subscriber to comp_tasks/wp_group_info
        wp_group_sub_ = this->create_subscription<comp_tasks_interfaces::msg::WpGroupInfo>(
            "/comp_tasks/wp_group_info", qos,
            std::bind(&LocalToGlobalConverter::wpGroupCallback, this, std::placeholders::_1)
        );

        // Subscriber to reference GPS origin
        ref_sub_ = this->create_subscription<geographic_msgs::msg::GeoPointStamped>(
            "/mavros/global_position/gp_origin", qos,
            std::bind(&LocalToGlobalConverter::refCallback, this, std::placeholders::_1)
        );

        // Publisher for converted global coordinates
        global_pub_ = this->create_publisher<geographic_msgs::msg::GeoPointStamped>(
            "/comp_tasks/converted_local_to_global_wps", 10
        );

        RCLCPP_INFO(this->get_logger(), "Local to Global Converter Node Initialized!");
    }

private:
    void wpGroupCallback(const comp_tasks_interfaces::msg::WpGroupInfo::SharedPtr msg) {
        // Generate CSV file name using wp group name and timestamp
        std::filesystem::path current_file(__FILE__); 
        std::filesystem::path package_path = current_file.parent_path().parent_path();

        std::string routes_dir = package_path.string() + "/routes";

        // Create the routes directory if it doesn't exist
        if (!fs::exists(routes_dir)) {
            fs::create_directories(routes_dir);
            RCLCPP_INFO(this->get_logger(), "Created routes directory at: %s", routes_dir.c_str());
        }
        std::string filename = routes_dir + "/" + msg->group_name + "_" + std::to_string(msg->header.stamp.sec) + ".csv";
        std::replace(filename.begin(), filename.end(), ' ', '_');
        std::ofstream csv_file(filename);
        
        if (!csv_file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open file: %s", filename.c_str());
            return;
        }
        
        // Write CSV header
        csv_file << "latitude,longitude,name" << std::endl;  
        double x_local = msg->current_pose_local.position.x;
        double y_local = msg->current_pose_local.position.y;
        double z_local = msg->current_pose_local.position.z;

        double lat, lon, alt;
        enu_converter_->Reverse(x_local, y_local, z_local, lat, lon, alt);    
        csv_file << std::fixed << std::setprecision(6) << lat << "," << lon << "," << "pose_when_sent" << std::endl;  
        for (const auto& wp : msg->wps) {
            double x_local = wp.wp.x;
            double y_local = wp.wp.y;
            double z_local = wp.wp.z;

            double lat, lon, alt;
            enu_converter_->Reverse(x_local, y_local, z_local, lat, lon, alt);

            RCLCPP_DEBUG(
                this->get_logger(), "Local ENU (X: %.2f, Y: %.2f, Z: %.2f) -> Global (Lat: %.6f, Lon: %.6f, Alt: %.2f)",
                x_local, y_local, z_local, lat, lon, alt
            );

            // // Publish each converted global waypoint
            // auto global_msg = geographic_msgs::msg::GeoPointStamped();
            // global_msg.header.stamp = this->now();
            // global_msg.header.frame_id = "map";
            // global_msg.position.latitude = lat;
            // global_msg.position.longitude = lon;
            // global_msg.position.altitude = alt;

            // global_pub_->publish(global_msg);
            // Write to CSV file
            csv_file << std::fixed << std::setprecision(6) << lat << "," << lon << "," << wp.wp_name << std::endl;  
        }

        csv_file.close();
        RCLCPP_INFO(this->get_logger(), "Saved global waypoints to %s", filename.c_str());
    
    }

    void refCallback(const geographic_msgs::msg::GeoPointStamped::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received Reference GPS Origin");
        lat_ref_ = msg->position.latitude;
        lon_ref_ = msg->position.longitude;
        alt_ref_ = msg->position.altitude;

        // Update the ENU converter with the new reference origin
        enu_converter_->Reset(lat_ref_, lon_ref_, alt_ref_);

        RCLCPP_INFO(
            this->get_logger(), "Updated Reference Origin to (Lat: %.6f, Lon: %.6f, Alt: %.2f)",
            lat_ref_, lon_ref_, alt_ref_
        );

        ref_sub_.reset();  // Unsubscribe after receiving reference
    }

    rclcpp::Subscription<comp_tasks_interfaces::msg::WpGroupInfo>::SharedPtr wp_group_sub_;
    rclcpp::Subscription<geographic_msgs::msg::GeoPointStamped>::SharedPtr ref_sub_;
    rclcpp::Publisher<geographic_msgs::msg::GeoPointStamped>::SharedPtr global_pub_;
    std::unique_ptr<GeographicLib::LocalCartesian> enu_converter_;
    double lat_ref_ = 0.0, lon_ref_ = 0.0, alt_ref_ = 0.0;

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LocalToGlobalConverter>());
    rclcpp::shutdown();
    return 0;
}
