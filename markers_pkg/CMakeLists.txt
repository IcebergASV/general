cmake_minimum_required(VERSION 3.8)
project(markers_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
# HS: find_package(rosidl_default_generators REQUIRED)
# HS: find_package(markers_pkg REQUIRED)
find_package(markers_pkg_interfaces REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# HS: Commented block below
# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/Prop.msg"
#   "msg/PropArray.msg"
#   "msg/Waypoint.msg"
# )
# ament_export_dependencies(rosidl_default_runtime)

add_executable(test_markers src/test_markers.cpp)
ament_target_dependencies(test_markers rclcpp visualization_msgs)

add_executable(subscribe_markers src/subscribe_markers.cpp)
ament_target_dependencies(subscribe_markers rclcpp visualization_msgs nav_msgs markers_pkg_interfaces)
# HS: ament_target_dependencies(subscribe_markers rclcpp visualization_msgs nav_msgs rosidl_default_generators markers_pkg)

add_executable(publish_markers src/publish_markers.cpp)
ament_target_dependencies(publish_markers rclcpp visualization_msgs markers_pkg_interfaces)
# HS: ament_target_dependencies(publish_markers rclcpp visualization_msgs rosidl_default_generators markers_pkg)

add_executable(rviz_markers src/rviz_markers.cpp)
ament_target_dependencies(rviz_markers rclcpp visualization_msgs nav_msgs markers_pkg_interfaces)
# HS: ament_target_dependencies(rviz_markers rclcpp visualization_msgs nav_msgs rosidl_default_generators markers_pkg)


install(TARGETS
   test_markers
   subscribe_markers
   publish_markers
   rviz_markers
   DESTINATION lib/${PROJECT_NAME}
 )

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)


ament_package()
