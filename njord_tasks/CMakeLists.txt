cmake_minimum_required(VERSION 3.8)
project(njord_tasks)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(composition REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(geographic_msgs REQUIRED)
find_package(njord_tasks_interfaces REQUIRED)
find_package(perception_interfaces REQUIRED)
find_package(yolov8_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(slg_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

include_directories(
    include
    ${tf2_INCLUDE_DIRS}
)

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

include_directories(include)

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)



add_library(libtask_lib
  lib/task_lib.cpp
)
ament_target_dependencies(libtask_lib
  "geographic_msgs"
  "rclcpp"
  "mavros_msgs"
  "sensor_msgs"
  "tf2"
  "tf2_geometry_msgs"
)

## Declare a C++ library
add_library(liblidar_calculations
  lib/lidar_calculations.cpp
)
ament_target_dependencies(liblidar_calculations
  "geometry_msgs"
  "rclcpp"
  "perception_interfaces"
)

add_library(libbbox_calculations
  lib/bbox_calculations.cpp
)
ament_target_dependencies(libbbox_calculations
  "geometry_msgs"
  "rclcpp"
  "perception_interfaces"
  "yolov8_msgs"
)

add_library(libvisualization
  lib/visualization.cpp
)
ament_target_dependencies(libvisualization
  "slg_msgs"
  "visualization_msgs"
  "rclcpp"
  "tf2_geometry_msgs"
)

ament_package()
add_library(maneuvering_component SHARED src/maneuvering_component.cpp)

target_compile_definitions(maneuvering_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(maneuvering_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "sensor_msgs"
  "geographic_msgs"
  "njord_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs")
rclcpp_components_register_nodes(maneuvering_component "njord_tasks::Maneuvering")
set(node_plugins "njord_tasks::Maneuvering;$<TARGET_FILE:maneuvering_component>\n")
install(TARGETS
  maneuvering_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for maneuvering
add_executable(maneuvering_composition
  src/maneuvering_composition.cpp)
target_link_libraries(maneuvering_composition
maneuvering_component)
ament_target_dependencies(maneuvering_composition
  rclcpp njord_tasks_interfaces)
install(TARGETS
  maneuvering_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(maneuvering_composition
  ${YAML_CPP_LIBRARIES}
  libtask_lib
  libbbox_calculations
)

add_library(navigation_component SHARED src/navigation_component.cpp)
target_compile_definitions(navigation_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(navigation_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs")
rclcpp_components_register_nodes(navigation_component "njord_tasks::navigation")
set(node_plugins "njord_tasks::navigation;$<TARGET_FILE:navigation_component>\n")
install(TARGETS
  navigation_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for navigation
add_executable(navigation_composition
  src/navigation_composition.cpp)
target_link_libraries(navigation_composition
navigation_component)
ament_target_dependencies(navigation_composition
  rclcpp)
install(TARGETS
  navigation_composition
  DESTINATION lib/${PROJECT_NAME})

add_library(task_component SHARED src/task_component.cpp)
target_compile_definitions(task_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(task_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "njord_tasks_interfaces")
rclcpp_components_register_nodes(task_component "njord_tasks::Task")
set(node_plugins "njord_tasks::Task;$<TARGET_FILE:task_component>\n")
install(TARGETS
  task_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

  # Add executable for navigation
  add_executable(detection_filter
  src/detection_filter.cpp)
  ament_target_dependencies(detection_filter
  rclcpp yolov8_msgs njord_tasks_interfaces)
  install(TARGETS
  detection_filter
  DESTINATION lib/${PROJECT_NAME})


# Add executable for task
add_executable(task_composition
  src/task_composition.cpp)
target_link_libraries(task_composition
task_component)
ament_target_dependencies(task_composition
  rclcpp njord_tasks_interfaces)
install(TARGETS
  task_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(task_composition
  ${YAML_CPP_LIBRARIES}
  libtask_lib
)
add_library(collision_avoidance_component SHARED src/collision_avoidance_component.cpp)
target_compile_definitions(collision_avoidance_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(collision_avoidance_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "njord_tasks_interfaces"
  "slg_msgs"
  "visualization_msgs")
rclcpp_components_register_nodes(collision_avoidance_component "njord_tasks::CollisionAvoidance")
set(node_plugins "njord_tasks::CollisionAvoidance;$<TARGET_FILE:collision_avoidance_component>\n")
install(TARGETS
  collision_avoidance_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for collision_avoidance
add_executable(collision_avoidance_composition
  src/collision_avoidance_composition.cpp)
target_link_libraries(collision_avoidance_composition
collision_avoidance_component)
ament_target_dependencies(collision_avoidance_composition
  rclcpp)
target_link_libraries(collision_avoidance_composition
${YAML_CPP_LIBRARIES}
libtask_lib
liblidar_calculations
libvisualization
)
install(TARGETS
  collision_avoidance_composition
  DESTINATION lib/${PROJECT_NAME})
add_library(wp_sender_component SHARED src/wp_sender_component.cpp)
target_compile_definitions(wp_sender_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(wp_sender_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geometry_msgs"
  "geographic_msgs"
  "tf2_geometry_msgs")
rclcpp_components_register_nodes(wp_sender_component "njord_tasks::WPSender")
set(node_plugins "njord_tasks::WPSender;$<TARGET_FILE:wp_sender_component>\n")
install(TARGETS
  wp_sender_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for wp_sender
add_executable(wp_sender_composition
  src/wp_sender_composition.cpp)
target_link_libraries(wp_sender_composition
wp_sender_component)
ament_target_dependencies(wp_sender_composition
  rclcpp)
install(TARGETS
  wp_sender_composition
  DESTINATION lib/${PROJECT_NAME})
