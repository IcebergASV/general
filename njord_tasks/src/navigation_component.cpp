#include "njord_tasks/navigation_component.hpp"
#include "njord_tasks/lib/task_lib.hpp"

namespace njord_tasks
{
  navigation::navigation(const rclcpp::NodeOptions & options)
  : Node("navigation", options)
  {
    example_sub_ = this->create_subscription<njord_tasks_interfaces::msg::StartTask>("/njord_tasks/task_to_execute", 10, std::bind(&navigation::callback, this, _1));
    wp_reached_sub_ = this->create_subscription<std_msgs::msg::Int32>("/njord_tasks/wp_reached_test", 10, std::bind(&navigation::wpReachedCallback, this, _1));
    timer_ = this->create_wall_timer(500ms, std::bind(&navigation::timerCallback, this));
    
    navigation::getParam("nav_points", point_list_1D, std::vector<double>{}, "List of 2D points");
    point_list_2D = navigation::convertTo2DList(point_list_1D);

    number_of_points = static_cast<int32_t>(point_list_2D.size());
    index_of_current_point = 0;


  }

  void navigation::callback(const njord_tasks_interfaces::msg::StartTask::SharedPtr msg)
  {
       if(msg->task.current_task == njord_tasks_interfaces::msg::Task::NAVIGATION){
        status_ = States::START_TASK;
        start_lat = msg->start_pnt.latitude;
        start_lon = msg->start_pnt.longitude;
        finish_lat = msg->finish_pnt.latitude;
        finish_lon = msg->finish_pnt.longitude;
       }
  }

  void navigation::wpReachedCallback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Reached");
    //mavros_msgs::msg::WaypointReached wpr = msg;
    wp_reached_ = true;
  }

  void navigation::timerCallback(){
    switch (status_){
      case States::WAIT_FOR_START:
      {
        RCLCPP_DEBUG(this->get_logger(), "Waiting for task to start");
        break;

      }
      case States::START_TASK:
      {

        RCLCPP_INFO(this->get_logger(), "Starting navigation task");
        RCLCPP_INFO(this->get_logger(), "point: %.2d", number_of_points);

        current_point = task_lib::translate_lat_lon(start_lat, start_lon, point_list_2D[index_of_current_point][0], point_list_2D[index_of_current_point][1] );
        
        RCLCPP_INFO(this->get_logger(), "Publishing x: %.4f, y: %.4f", point_list_2D[index_of_current_point][0], point_list_2D[index_of_current_point][1]);
        RCLCPP_INFO(this->get_logger(), "GeoPoseStamped created with latitude: %.8f, longitude: %.8f", 
                current_point.pose.position.latitude, current_point.pose.position.longitude);
        wp_reached_ = false;
        status_ = GOING_TO_WAYPOINT;
        break;
      }
      case States::GOING_TO_WAYPOINT:
      {
        if(wp_reached_){
          
          index_of_current_point += 1;
          if(index_of_current_point == number_of_points){
            RCLCPP_INFO(this->get_logger(), "GeoPoseStamped created with latitude: %.8f, longitude: %.8f", 
                finish_lat, finish_lon);
            status_ = GOING_TO_FINISH;
            break;
          }
          else{
            status_ = REACHED_WAYPOINT;
            break;
          }
        }
        status_ = GOING_TO_WAYPOINT;
        break;
      }
      case States::REACHED_WAYPOINT:
      {
        RCLCPP_INFO(this->get_logger(), "Reached waypoint");
        wp_reached_ = false;
        current_point = task_lib::translate_lat_lon(start_lat, start_lon, point_list_2D[index_of_current_point][0], point_list_2D[index_of_current_point][1]);

        RCLCPP_INFO(this->get_logger(), "Publishing x: %.4f, y: %.4f", point_list_2D[index_of_current_point][0], point_list_2D[index_of_current_point][1]);
        RCLCPP_INFO(this->get_logger(), "GeoPoseStamped created with latitude: %.8f, longitude: %.8f", 
                current_point.pose.position.latitude, current_point.pose.position.longitude);
        
        status_ = GOING_TO_WAYPOINT;
        break;

      }

      case States::GOING_TO_FINISH:
      {
        RCLCPP_INFO(this->get_logger(), "Going to finish");

        if(wp_reached_){
          wp_reached_ = false;
          status_ = COMPLETE;
          break;
        }
        status_ = GOING_TO_FINISH;
        break;
      }

      case States::COMPLETE:
      {
        RCLCPP_INFO(this->get_logger(), "Complete!!!!!!!");
      }

    }
  }
  
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(njord_tasks::navigation)
