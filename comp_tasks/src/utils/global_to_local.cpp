#include "utils/global_to_local.hpp"

#include <functional>

GlobalToLocalConverter::GlobalToLocalConverter()
: Node("global_to_local_converter")
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

    // Subscriber to MAVROS global setpoints
    global_sub_ =
        this->create_subscription<geographic_msgs::msg::GeoPoseStamped>(
            "/mavros/setpoint_position/global",
            qos,
            std::bind(
                &GlobalToLocalConverter::globalCallback,
                this,
                std::placeholders::_1
            )
        );

    // Subscriber to reference GPS origin
    ref_sub_ =
        this->create_subscription<geographic_msgs::msg::GeoPointStamped>(
            "/mavros/global_position/gp_origin",
            qos,
            std::bind(
                &GlobalToLocalConverter::refCallback,
                this,
                std::placeholders::_1
            )
        );

    // Publisher for converted local coordinates
    local_pub_ =
        this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "/comp_tasks/converted_global_to_local_wps",
            10
        );

    RCLCPP_INFO(get_logger(), "GlobalToLocalConverter initialized");
}

void GlobalToLocalConverter::globalCallback(
    const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg)
{
    const double lat = msg->pose.position.latitude;
    const double lon = msg->pose.position.longitude;
    const double alt = msg->pose.position.altitude;

    double x_local, y_local, z_local;
    enu_converter_->Forward(lat, lon, alt, x_local, y_local, z_local);

    RCLCPP_DEBUG(
        get_logger(),
        "Global (Lat %.6f, Lon %.6f, Alt %.2f) -> Local (X %.2f, Y %.2f, Z %.2f)",
        lat, lon, alt, x_local, y_local, z_local
    );

    geometry_msgs::msg::PoseStamped local_msg;
    local_msg.header.stamp = now();
    local_msg.header.frame_id = "map";
    local_msg.pose.position.x = x_local;
    local_msg.pose.position.y = y_local;
    local_msg.pose.position.z = z_local;
    local_msg.pose.orientation = msg->pose.orientation;

    local_pub_->publish(local_msg);
}

void GlobalToLocalConverter::refCallback(
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

    // Only need the reference once
    ref_sub_.reset();
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GlobalToLocalConverter>());
    rclcpp::shutdown();
    return 0;
}
