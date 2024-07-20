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
}