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
}
