#ifndef LIDARCALCULATIONS_H
#define LIDARCALCULATIONS_H

#include <vector>
#include <string>
#include "geometry_msgs/msg/point.hpp"

bool testFunction();

std::vector<double> LidarClusterer::extractXorYCoordsToVector(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract);

#endif // LIDARCALCULATIONS_H