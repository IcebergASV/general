#include "njord_tasks/lib/task_lib.hpp"

namespace task_lib
{

    bool inGuided(const mavros_msgs::msg::State& state)
    {
        if (state.mode == "GUIDED")
        {
            return true;
        }

        return false;
    }
    
    bool isReached(double lat, double lon, const geographic_msgs::msg::GeoPoseStamped& global_pose, double max_dist)
    {
        // Using haversine formula as described in https://www.movable-type.co.uk/scripts/latlong.html
        double dist = haversine(lat, lon, global_pose.pose.position.latitude, global_pose.pose.position.longitude) * 1000;
        // double dist = haversine(47.5829284, -52.7167824, 47.5826969, -52.7172384); // Test Case - distance should be around 0.04281 km
        
        if (dist < max_dist)
        {
            RCLCPP_INFO(logger, "Robot has made it to the %fm radius around the target", max_dist);
            return true;
        }
        RCLCPP_INFO(logger, "Robot is %fm away from target", dist);
        return false;
    }
    double haversine(double lat1, double lon1, double lat2, double lon2)
    {
        // distance between latitudes
        // and longitudes
        double dLat = (lat2 - lat1) *
                      M_PI / 180.0;
        double dLon = (lon2 - lon1) * 
                      M_PI / 180.0;
    
        // convert to radians
        lat1 = (lat1) * M_PI / 180.0;
        lat2 = (lat2) * M_PI / 180.0;
    
        // apply formulae
        double a = pow(sin(dLat / 2), 2) + 
                   pow(sin(dLon / 2), 2) * 
                   cos(lat1) * cos(lat2);
        double rad = 6371;
        double c = 2 * asin(sqrt(a));
        return rad * c;
    }

    geometry_msgs::msg::Point relativePolarToLocalCoords(double radius, double angle, geometry_msgs::msg::Pose local_pose)
    {
       
        geometry_msgs::msg::Point local_coords;
        // Convert relative coordinates to local coordinates 
        double heading = quaternionToHeading(local_pose.orientation);
        double x_aligned = radius*cos(angle-((M_PI/2)-heading));
        double y_aligned = radius*sin(angle-((M_PI/2)-heading));
        double x =  local_pose.position.x + x_aligned;
        double y =  local_pose.position.y + y_aligned;

        local_coords.x = -y; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
        local_coords.y = x; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
        RCLCPP_DEBUG(logger, "x robot = %f", local_pose.position.y);
        RCLCPP_DEBUG(logger, "y robot = %f", -local_pose.position.x);
        RCLCPP_DEBUG(logger, "x target = %f", x);
        RCLCPP_DEBUG(logger, "y target = %f", y);
        return local_coords;
    }

    double quaternionToHeading(const geometry_msgs::msg::Quaternion q)
    {
        double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
        double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
        double heading = std::atan2(siny_cosp, cosy_cosp);
        return heading;
    }

    geographic_msgs::msg::GeoPoseStamped getGlobalWPMsg(double lat, double lon)
    {
        geographic_msgs::msg::GeoPoseStamped msg;
        msg.header.frame_id = "map";  // or use an appropriate frame_id

        msg.pose.position.latitude = lat;
        msg.pose.position.longitude = lon;
        return msg;
    }

    geometry_msgs::msg::PoseStamped getRelativeWPMsg(double x, double y)
    {
        geometry_msgs::msg::PoseStamped msg;
        msg.header.frame_id = "body";  // or use an appropriate frame_id

        msg.pose.position.x = x;
        msg.pose.position.y = y;
        return msg;
    }

    geometry_msgs::msg::Point polarToCartesian(double radius, double angle)
    {
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        geometry_msgs::msg::Point cartesian;
        cartesian.x = x;
        cartesian.y = y;
        return cartesian;
    }
}
