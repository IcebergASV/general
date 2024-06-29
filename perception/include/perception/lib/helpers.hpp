#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <sstream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include "perception_interfaces/msg/gate.hpp"

namespace helpers
{
    std::string vectorToString(const std::vector<double>& vec);
    perception_interfaces::msg::Gate createGate(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2);

    template <typename T>
    std::string matrixToString(const Eigen::MatrixBase<T>& matrix) 
    {
        std::ostringstream oss;
        oss << matrix;
        return oss.str();
    };
}

#endif // HELPERS_H