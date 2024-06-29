#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <sstream>
#include <vector>
#include <eigen3/Eigen/Dense>

namespace helpers
{
    std::string vectorToString(const std::vector<double>& vec);

    template <typename T>
    std::string matrixToString(const Eigen::MatrixBase<T>& matrix) 
    {
        std::ostringstream oss;
        oss << matrix;
        return oss.str();
    };
}

#endif // HELPERS_H