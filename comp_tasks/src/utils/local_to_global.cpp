#include <rclcpp/rclcpp.hpp> 
#include <geographic_msgs/msg/geo_point_stamped.hpp> 
#include <geometry_msgs/msg/pose_stamped.hpp> 
#include <GeographicLib/LocalCartesian.hpp> 
#include <comp_tasks_interfaces/msg/wp_group_info.hpp> 
#include "utils/local_to_global.hpp" 
#include <fstream> 
#include <filesystem>

namespace fs = std::filesystem;

LocalToGlobalConverter::LocalToGlobalConverter()
: Node("local_to_global_converter")
{
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    auto qos = rclcpp::QoS(
        rclcpp::QoSInitialization(qos_profile.history, 5),
        qos_profile
    );

    // Initialize ENU converter with default reference
    enu_converter_ = std::make_unique<GeographicLib::LocalCartesian>(
        lat_ref_, lon_ref_, alt_ref_,
        GeographicLib::Geocentric::WGS84()
    );

    wp_group_sub_ =
        this->create_subscription<comp_tasks_interfaces::msg::WpGroupInfo>(
            "/comp_tasks/wp_group_info",
            qos,
            std::bind(
                &LocalToGlobalConverter::wpGroupCallback,
                this,
                std::placeholders::_1
            )
        );

    ref_sub_ =
        this->create_subscription<geographic_msgs::msg::GeoPointStamped>(
            "/mavros/global_position/gp_origin",
            qos,
            std::bind(
                &LocalToGlobalConverter::refCallback,
                this,
                std::placeholders::_1
            )
        );

    global_pub_ =
        this->create_publisher<geographic_msgs::msg::GeoPointStamped>(
            "/comp_tasks/converted_local_to_global_wps",
            10
        );

    RCLCPP_INFO(get_logger(), "LocalToGlobalConverter initialized");
}

void LocalToGlobalConverter::wpGroupCallback(
    const comp_tasks_interfaces::msg::WpGroupInfo::SharedPtr msg)
{
    fs::path current_file(__FILE__);
    fs::path package_path = current_file.parent_path().parent_path();
    fs::path routes_dir = package_path / "routes";

    if (!fs::exists(routes_dir)) {
        fs::create_directories(routes_dir);
        RCLCPP_INFO(
            get_logger(),
            "Created routes directory: %s",
            routes_dir.c_str()
        );
    }

    std::string base_name =
        msg->group_name + "_" + std::to_string(msg->header.stamp.sec);
    std::replace(base_name.begin(), base_name.end(), ' ', '_');

    /* -------- Global CSV -------- */
    fs::path global_file = routes_dir / (base_name + ".csv");
    std::ofstream csv_global(global_file);

    if (!csv_global.is_open()) {
        RCLCPP_ERROR(
            get_logger(),
            "Failed to open file: %s",
            global_file.c_str()
        );
        return;
    }

    csv_global << "latitude,longitude,name\n";

    double lat, lon, alt;
    enu_converter_->Reverse(
        msg->current_pose_local.position.x,
        msg->current_pose_local.position.y,
        msg->current_pose_local.position.z,
        lat, lon, alt
    );

    csv_global << std::fixed << std::setprecision(6)
               << lat << "," << lon << ",pose_when_sent\n";

    for (const auto & wp : msg->wps) {
        enu_converter_->Reverse(
            wp.wp.x, wp.wp.y, wp.wp.z,
            lat, lon, alt
        );

        csv_global << std::fixed << std::setprecision(6)
                   << lat << "," << lon << "," << wp.wp_name << "\n";
    }

    csv_global.close();

    /* -------- Local CSV -------- */
    fs::path local_file = routes_dir / (base_name + "_local.csv");
    std::ofstream csv_local(local_file);

    if (!csv_local.is_open()) {
        RCLCPP_ERROR(
            get_logger(),
            "Failed to open file: %s",
            local_file.c_str()
        );
        return;
    }

    csv_local << "x,y,name\n";

    csv_local << std::fixed << std::setprecision(6)
              << msg->current_pose_local.position.x << ","
              << msg->current_pose_local.position.y << ",pose_when_sent\n";

    for (const auto & wp : msg->wps) {
        csv_local << std::fixed << std::setprecision(6)
                  << wp.wp.x << "," << wp.wp.y << ","
                  << wp.wp_name << "\n";
    }

    csv_local.close();

    RCLCPP_INFO(
        get_logger(),
        "Saved waypoint CSVs to %s",
        routes_dir.c_str()
    );
}

void LocalToGlobalConverter::refCallback(
    const geographic_msgs::msg::GeoPointStamped::SharedPtr msg)
{
    lat_ref_ = msg->position.latitude;
    lon_ref_ = msg->position.longitude;
    alt_ref_ = msg->position.altitude;

    enu_converter_->Reset(lat_ref_, lon_ref_, alt_ref_);

    RCLCPP_INFO(
        get_logger(),
        "Reference origin set to (%.6f, %.6f, %.2f)",
        lat_ref_, lon_ref_, alt_ref_
    );

    ref_sub_.reset();  // Unsubscribe after first fix
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LocalToGlobalConverter>());
    rclcpp::shutdown();
    return 0;
}
