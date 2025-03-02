#include <rclcpp/rclcpp.hpp>
#include <geographic_msgs/msg/geo_pose_stamped.hpp>
#include <geographic_msgs/msg/geo_point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <GeographicLib/LocalCartesian.hpp>

class GlobalToLocalConverter : public rclcpp::Node {
public:
    GlobalToLocalConverter() : Node("global_to_local_converter") {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
    
        // Initialize the ENU converter with the reference origin
        enu_converter_ = std::make_unique<GeographicLib::LocalCartesian>(
            lat_ref_, lon_ref_, alt_ref_, GeographicLib::Geocentric::WGS84()
        );

        // Subscriber to MAVROS global setpoints
        global_sub_ = this->create_subscription<geographic_msgs::msg::GeoPoseStamped>(
            "/mavros/setpoint_position/global", qos,
            std::bind(&GlobalToLocalConverter::globalCallback, this, std::placeholders::_1)
        );

        // Subscriber to reference GPS origin
        ref_sub_ = this->create_subscription<geographic_msgs::msg::GeoPointStamped>(
            "mavros/global_position/gp_origin", qos,
            std::bind(&GlobalToLocalConverter::refCallback, this, std::placeholders::_1)
        );

        // Publisher for converted local coordinates
        local_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "/comp_tasks/converted_global_to_local_wps", 10
        );

        RCLCPP_INFO(this->get_logger(), "Global to Local Converter Node Initialized!");
    }

private:
    void globalCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg) {
        double lat = msg->pose.position.latitude;  // Assuming X stores latitude
        double lon = msg->pose.position.longitude;  // Assuming Y stores longitude
        double alt = msg->pose.position.altitude;  // Assuming Z stores altitude

        double x_local, y_local, z_local;
        enu_converter_->Forward(lat, lon, alt, x_local, y_local, z_local);

        RCLCPP_DEBUG(
            this->get_logger(), "Global (Lat: %.6f, Lon: %.6f, Alt: %.2f) -> Local ENU (X: %.2f, Y: %.2f, Z: %.2f)",
            lat, lon, alt, x_local, y_local, z_local
        );

        // Publish the converted local coordinates
        auto local_msg = geometry_msgs::msg::PoseStamped();
        local_msg.header.stamp = this->now();
        local_msg.header.frame_id = "map";
        local_msg.pose.position.x = x_local;
        local_msg.pose.position.y = y_local;
        local_msg.pose.position.z = 0.0;
        local_msg.pose.orientation = msg->pose.orientation;  // Copy orientation from the original message

        local_pub_->publish(local_msg);
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

        ref_sub_.reset();
    }

    rclcpp::Subscription<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_sub_;
    rclcpp::Subscription<geographic_msgs::msg::GeoPointStamped>::SharedPtr ref_sub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr local_pub_;
    std::unique_ptr<GeographicLib::LocalCartesian> enu_converter_;
    double lat_ref_, lon_ref_, alt_ref_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GlobalToLocalConverter>());
    rclcpp::shutdown();
    return 0;
}
