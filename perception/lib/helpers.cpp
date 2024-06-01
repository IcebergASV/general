#include "perception/lib/helpers.hpp"

namespace helpers
{

  std::string vectorToString(const std::vector<double>& vec) 
  {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
      oss << vec[i];
      if (i != vec.size() - 1) {
        oss << ", ";
      }
    }
    oss << "]";
    return oss.str();
  }

}
