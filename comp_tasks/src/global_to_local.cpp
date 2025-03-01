#include <rclcpp/rclcpp.hpp>
#include <geographic_msgs/msg/geo_pose_stamped.hpp>
#include <GeographicLib/LocalCartesian.hpp>

class GlobalToLocalConverter : public rclcpp::Node {
public:
    GlobalToLocalConverter() : Node("global_to_local_converter") {
        // Define the reference local origin (set this according to your home position)
        lat_ref_ = 28.55814;
        lon_ref_ = -81.22903;
        alt_ref_ = 500.0;

        // Initialize the ENU converter with the reference origin
        enu_converter_ = std::make_unique<GeographicLib::LocalCartesian>(
            lat_ref_, lon_ref_, alt_ref_, GeographicLib::Geocentric::WGS84()
        );

        // Subscriber to MAVROS global setpoints
        global_sub_ = this->create_subscription<geographic_msgs::msg::GeoPoseStamped>(
            "/mavros/setpoint_position/global", 10,
            std::bind(&GlobalToLocalConverter::globalCallback, this, std::placeholders::_1)
        );

        RCLCPP_INFO(this->get_logger(), "Global to Local Converter Node Initialized!");
    }

private:
    void globalCallback(const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received Global Pose");
        double lat = msg->pose.position.latitude;  // Assuming X stores latitude
        double lon = msg->pose.position.longitude;  // Assuming Y stores longitude
        double alt = msg->pose.position.altitude;  // Assuming Z stores altitude

        double x_local, y_local, z_local;
        enu_converter_->Forward(lat, lon, alt, x_local, y_local, z_local);

        RCLCPP_INFO(
            this->get_logger(), "Global (Lat: %.6f, Lon: %.6f, Alt: %.2f) -> Local ENU (X: %.2f, Y: %.2f, Z: %.2f)",
            lat, lon, alt, x_local, y_local, z_local
        );
    }

    rclcpp::Subscription<geographic_msgs::msg::GeoPoseStamped>::SharedPtr global_sub_;
    std::unique_ptr<GeographicLib::LocalCartesian> enu_converter_;
    double lat_ref_, lon_ref_, alt_ref_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GlobalToLocalConverter>());
    rclcpp::shutdown();
    return 0;
}
