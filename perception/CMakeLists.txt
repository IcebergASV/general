cmake_minimum_required(VERSION 3.8)
project(perception)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(composition REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(slg_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(perception_interfaces REQUIRED)


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

add_library(lidar_clusterer_component SHARED src/lidar_clusterer_component.cpp)
target_compile_definitions(lidar_clusterer_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(lidar_clusterer_component
  "rclcpp"
  "rclcpp_components"
  "sensor_msgs"
  "slg_msgs"
  "geometry_msgs"
  "perception_interfaces")
rclcpp_components_register_nodes(lidar_clusterer_component "perception::LidarClusterer")
set(node_plugins "${node_plugins}perception::LidarClusterer;$<TARGET_FILE:lidar_clusterer_component>\n")

install(TARGETS
  lidar_clusterer_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)


# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

add_executable(manual_composition
  src/manual_composition.cpp)
target_link_libraries(manual_composition
  lidar_clusterer_component)
ament_target_dependencies(manual_composition
  rclcpp perception_interfaces)

install(TARGETS
  manual_composition
  DESTINATION lib/${PROJECT_NAME})

ament_package()
