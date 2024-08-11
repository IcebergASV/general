#include "njord_tasks/navigation_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"

namespace njord_tasks
{
  navigation::navigation(const rclcpp::NodeOptions & options)
  : Node("navigation", options)
  {
    example_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&navigation::callback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&navigation::timerCallback, this));
    navigation::getParam<std::vector<std::pair<double, double>>>("nav_points", test, {{0.0,0.0}}, "Nav points");
    
  }

  void navigation::callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
       if(msg->task.current_task == njord_tasks_interfaces::msg::Task::NAVIGATION){
        status_ = States::START_TASK;
       }
  }

  void navigation::timerCallback(){
    switch (status_){
      case States::WAIT_FOR_START:
      {
        RCLCPP_INFO(this->get_logger(), "Waiting for task to start");
        break;

      }
      case States::START_TASK:
      {
        RCLCPP_INFO(this->get_logger(), "Sending first waypoint");

        // Set way point to first 
        //publish waypoint
        
        status_ = GOING_TO_WAYPOINT;
        break;
      }
      case States::GOING_TO_WAYPOINT:
      {

        // if waypoint reached 
            //if last waypoint reached 
                // next state = going to finish 

            //else
                //next state = waypoint reached 


        geographic_msgs::msg::GeoPoseStamped next_point = task_lib::translate_lat_lon(45, 50, 2000, 3000);

        RCLCPP_INFO(this->get_logger(), "GeoPoseStamped created with latitude: %.8f, longitude: %.8f", 
                next_point.pose.position.latitude, next_point.pose.position.longitude);

      }
      case States::REACHED_WAYPOINT:
      {

        // send next waypoint

      }

      case States::GOING_TO_FINISH:
      {


      }

      case States::COMPLETE
      {


      }
      


    }



  }
  
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::navigation)
