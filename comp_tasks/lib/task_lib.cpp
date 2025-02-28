#include "comp_tasks/lib/task_lib.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"


namespace task_lib
{
std::string toStringWithTwoDecimals(double value) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    return stream.str();
}
// Function to compute the centroid of a set of points
geometry_msgs::msg::Point computeCentroid(const std::vector<geometry_msgs::msg::Point>& points) {
    geometry_msgs::msg::Point centroid;
    centroid.x = 0.0;
    centroid.y = 0.0;
    centroid.z = 0.0;

    for (const auto& p : points) {
        centroid.x += p.x;
        centroid.y += p.y;
    }

    centroid.x /= points.size();
    centroid.y /= points.size();

    return centroid;
}

// Function to compute the relative angle of a point with respect to a reference direction
double computeRelativeAngle(const geometry_msgs::msg::Point& point, 
                            const geometry_msgs::msg::Point& reference_point, 
                            const geometry_msgs::msg::Point& forward_point) {
    // Compute the global angle from reference point to this point
    double point_angle = std::atan2(point.y - reference_point.y, point.x - reference_point.x);

    // Compute the angle of the forward direction (from reference point to centroid)
    double forward_angle = std::atan2(forward_point.y - reference_point.y, forward_point.x - reference_point.x);

    // Compute the relative angle
    double relative_angle = point_angle - forward_angle;

    // Normalize to range (-π, π]
    while (relative_angle <= -M_PI) relative_angle += 2 * M_PI;
    while (relative_angle > M_PI) relative_angle -= 2 * M_PI;

    return relative_angle;
}

// Function to sort points right to left
void orderPointsRightToLeft(std::vector<geometry_msgs::msg::Point>& points, 
                            const geometry_msgs::msg::Point& reference_point) {
    // Compute the centroid to get the forward direction
    geometry_msgs::msg::Point centroid = computeCentroid(points);

    // Sort based on the computed relative angles
    std::sort(points.begin(), points.end(), 
              [&](const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2) {
                  double angle1 = computeRelativeAngle(p1, reference_point, centroid);
                  double angle2 = computeRelativeAngle(p2, reference_point, centroid);

                  return angle1 > angle2; // Right to left
              });
}

    bool inGuided(const mavros_msgs::msg::State& state)
    {
        if (state.mode == "GUIDED")
        {
            return true;
        }

        return false;
    }
    bool inHold(const mavros_msgs::msg::State& state)
    {
        if (state.mode == "HOLD")
        {
            return true;
        }

        return false;
    }

    bool inManual(const mavros_msgs::msg::State& state)
    {
        if (state.mode == "MANUAL")
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

    geometry_msgs::msg::PoseStamped relativePolarToLocalCoords(double radius, double angle, geometry_msgs::msg::PoseStamped local_pose)
    {
        // Convert relative coordinates to local coordinates 
        // double heading = quaternionToHeading(local_pose.orientation);
        // double x_aligned = radius*cos(angle-((M_PI/2)-heading));
        // double y_aligned = radius*sin(angle-((M_PI/2)-heading));
        geometry_msgs::msg::PoseStamped relative_pose;
        relative_pose.pose.position.x = radius*cos(angle);
        relative_pose.pose.position.y = radius*sin(angle);
        geometry_msgs::msg::PoseStamped local_coords = rel_to_local_cord_converter(relative_pose, local_pose);
        local_coords.header.frame_id = "map"; 
        // double x =  local_pose.position.x + x_aligned;
        // double y =  local_pose.position.y + y_aligned;

        // local_coords.x = -y; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
        // local_coords.y = x; // FIGURE OUT IF THIS SHOULD BE SWAPPED IN REAL LIFE TODO
        // RCLCPP_DEBUG(logger, "x robot = %f", local_pose.position.y);
        // RCLCPP_DEBUG(logger, "y robot = %f", -local_pose.position.x);
        // RCLCPP_DEBUG(logger, "x target = %f", x);
        // RCLCPP_DEBUG(logger, "y target = %f", y);
        return local_coords;
    }

    geometry_msgs::msg::PoseStamped rel_to_local_cord_converter(const geometry_msgs::msg::PoseStamped &rel_pose, const geometry_msgs::msg::PoseStamped &local_pose)
    {
      // Convert relative coordinates to local coordinates
      tf2::Quaternion orientation;
      tf2::fromMsg(local_pose.pose.orientation, orientation);
      double roll, pitch, yaw;
      tf2::Matrix3x3(orientation).getRPY(roll, pitch, yaw);

      RCLCPP_DEBUG(logger, "Robot yaw: %f", yaw);
      double rel_x, rel_y;
      rel_x = rel_pose.pose.position.x;
      rel_y = rel_pose.pose.position.y;
      double heading = yaw;
      double prop_x_aligned = rel_x*cos(heading) - rel_y*sin(heading);
      double prop_y_aligned = rel_x*sin(heading) + rel_y*cos(heading);
      double x_prime =  local_pose.pose.position.x + prop_x_aligned;
      double y_prime =  local_pose.pose.position.y + prop_y_aligned;
      RCLCPP_DEBUG(logger, "rel x: %f, rel y: %f", rel_pose.pose.position.x, rel_pose.pose.position.y);
      RCLCPP_DEBUG(logger, "x aligned: %f, y aligned: %f", prop_x_aligned, prop_y_aligned);
      RCLCPP_DEBUG(logger, "boatx: %f, boaty: %f", local_pose.pose.position.x, local_pose.pose.position.y);
      RCLCPP_DEBUG(logger, "xprime: %f, yprime: %f", x_prime, y_prime);

      geometry_msgs::msg::PoseStamped relative_position;
      //relative_position.header.frame_id = "base_link";  // Frame of reference for the robot
      
      relative_position.pose.position.x = x_prime;
      relative_position.pose.position.y = y_prime;

      return relative_position;
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

    geometry_msgs::msg::PoseStamped getLocalWPMsg(double x, double y)
    {
        geometry_msgs::msg::PoseStamped msg;
        msg.header.frame_id = "map"; 
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

    double distBetween2Pnts(geometry_msgs::msg::Point p1, geometry_msgs::msg::Point p2)
    {
        return std::sqrt(std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2));
    }

    std::vector<geometry_msgs::msg::Point> generateCirclePoints(
        const geometry_msgs::msg::Point& center, double radius, int num_points) {
        
        std::vector<geometry_msgs::msg::Point> circle_points;
        circle_points.reserve(num_points);
        
        const double angle_increment = 2.0 * M_PI / num_points;
        
        for (int i = 0; i < num_points; ++i) {
            double angle = i * angle_increment;
            geometry_msgs::msg::Point point;
            point.x = center.x + radius * std::cos(angle);
            point.y = center.y + radius * std::sin(angle);
            point.z = center.z; // Keeping the original z value from center
            circle_points.push_back(point);
        }
        
        return circle_points;
    }

    std::vector<geometry_msgs::msg::Point> createSemicirce(
        const std::vector<geometry_msgs::msg::Point>& circle_points,
        const geometry_msgs::msg::Point& reference_point) {
        
        std::vector<double> distances;
        distances.reserve(circle_points.size());
        
        for (const auto& point : circle_points) {
            distances.push_back(std::hypot(point.x - reference_point.x, point.y - reference_point.y));
        }
        
        std::vector<size_t> indices(circle_points.size());
        std::iota(indices.begin(), indices.end(), 0);

        int offset= 1;
        if (circle_points.size() % 4 != 0) {
            offset = 0;
        }
        
        std::nth_element(indices.begin(), indices.begin() + (indices.size() / 2)-offset, indices.end(),
            [&distances](size_t i1, size_t i2) {
                return distances[i1] < distances[i2];
            });
        
        std::unordered_set<size_t> remove_indices(indices.begin(), indices.begin() + (indices.size() / 2)-offset);
        
        std::vector<geometry_msgs::msg::Point> farther_points;
        for (size_t i = 0; i < circle_points.size(); ++i) {
            if (remove_indices.find(i) == remove_indices.end()) {
                farther_points.push_back(circle_points[i]);
            }
        }
        std::vector<geometry_msgs::msg::Point> ordered_points = farther_points;
        // std::sort(ordered_points.begin(), ordered_points.end(),
        // [&reference_point](const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2) {
        //     // Compute angles relative to the reference point
        //     double angle1 = std::atan2(p1.y - reference_point.y, p1.x - reference_point.x);
        //     double angle2 = std::atan2(p2.y - reference_point.y, p2.x - reference_point.x);
            
        //     return angle1 > angle2;  // Sort in descending order (right to left)
        // });
        orderPointsRightToLeft(ordered_points, reference_point);

        return ordered_points;
    }

    std::vector<geometry_msgs::msg::Point> createQuarterCircle(
        const std::vector<geometry_msgs::msg::Point>& semicircle,
        double heading,
        bool left)
    {
        std::vector<geometry_msgs::msg::Point> quarter_circle;
        
        // Normalize the heading to the range [-pi, pi]
        heading = std::atan2(std::sin(heading), std::cos(heading));
        
        for (const auto& point : semicircle)
        {
            // Compute the angle of the point relative to the origin
            double point_angle = std::atan2(point.y, point.x);
            
            // Normalize the point angle to the range [-pi, pi]
            point_angle = std::atan2(std::sin(point_angle), std::cos(point_angle));
            
            // Compute the relative angle difference
            double angle_diff = point_angle - heading;
            angle_diff = std::atan2(std::sin(angle_diff), std::cos(angle_diff));
            
            // If left, keep points on the left (angle_diff > 0); otherwise, keep right (angle_diff < 0)
            if ((left && angle_diff > 0) || (!left && angle_diff < 0))
            {
                quarter_circle.push_back(point);
            }
        }
        
        return quarter_circle;
    }

    std::vector<geometry_msgs::msg::Point> translateSemicircle(
        const std::vector<geometry_msgs::msg::Point>& semicircle,
        const geometry_msgs::msg::Point& reference_point,
        bool align_to_end) 
    {
        if (semicircle.empty()) {
            return semicircle;
        }
    
        // Determine which point to align with the reference point
        geometry_msgs::msg::Point target_point = align_to_end ? semicircle.back() : semicircle.front();
    
        // Compute translation offsets
        double dx = reference_point.x - target_point.x;
        double dy = reference_point.y - target_point.y;
    
        // Apply translation to all points
        std::vector<geometry_msgs::msg::Point> translated_semicircle;
        translated_semicircle.reserve(semicircle.size());
    
        for (const auto& point : semicircle) {
            geometry_msgs::msg::Point translated_point;
            translated_point.x = point.x + dx;
            translated_point.y = point.y + dy;
            translated_point.z = point.z; // Assuming Z remains unchanged
            translated_semicircle.push_back(translated_point);
        }
    
        return translated_semicircle;
    }
    void writePointsToCSV(const std::vector<geometry_msgs::msg::Point>& points, const std::string& filename)
    {
        std::ofstream file(filename);
    
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }
    
        // Write the header
        file << "X,Y\n";
    
        // Write the points
        for (const auto& point : points)
        {
            file << point.x << "," << point.y << "\n";
        }
    
        file.close();
        std::cout << "Points written to " << filename << std::endl;
    }
}
