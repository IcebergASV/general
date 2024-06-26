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
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(perception_interfaces REQUIRED)
find_package(YAML-cpp REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

include_directories(include)

add_library(lidar_camera_fuser_component SHARED src/lidar_camera_fuser_component.cpp)
target_compile_definitions(lidar_camera_fuser_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(lidar_camera_fuser_component
  "rclcpp"
  "rclcpp_components"
  "sensor_msgs"
  "slg_msgs"
  "geometry_msgs"
  "perception_interfaces")
rclcpp_components_register_nodes(lidar_camera_fuser_component "perception::LidarCameraFuser")
set(node_plugins "${node_plugins}perception::LidarCameraFuser;$<TARGET_FILE:lidar_camera_fuser_component>\n")

add_library(lidar_prop_detector_component SHARED src/lidar_prop_detector_component.cpp)
target_compile_definitions(lidar_prop_detector_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(lidar_prop_detector_component
  "rclcpp"
  "rclcpp_components"
  "sensor_msgs"
  "slg_msgs"
  "geometry_msgs"
  "perception_interfaces")
rclcpp_components_register_nodes(lidar_prop_detector_component "perception::LidarPropDetector")
set(node_plugins "${node_plugins}perception::LidarPropDetector;$<TARGET_FILE:lidar_prop_detector_component>\n")

add_library(coord_finder_component SHARED src/coord_finder_component.cpp)
target_compile_definitions(coord_finder_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(coord_finder_component
  "rclcpp"
  "rclcpp_components"
  "sensor_msgs"
  "slg_msgs"
  "geometry_msgs"
  "perception_interfaces")
rclcpp_components_register_nodes(coord_finder_component "perception::CoordFinder")
set(node_plugins "${node_plugins}perception::CoordFinder;$<TARGET_FILE:coord_finder_component>\n")

## Declare a C++ library
add_library(liblidar_calculations
  lib/lidar_calculations.cpp
)
ament_target_dependencies(liblidar_calculations
  "geometry_msgs"
  "rclcpp"
  "perception_interfaces"
)

add_library(libhelpers
  lib/helpers.cpp
)


install(TARGETS
  lidar_prop_detector_component
  coord_finder_component
  lidar_camera_fuser_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)


# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)

add_executable(lidar_prop_detector_composition
  src/lidar_prop_detector_composition.cpp)
target_link_libraries(lidar_prop_detector_composition
  lidar_prop_detector_component)
ament_target_dependencies(lidar_prop_detector_composition
  rclcpp perception_interfaces)

add_executable(coord_finder_composition
  src/coord_finder_composition.cpp)
target_link_libraries(coord_finder_composition
  coord_finder_component)
ament_target_dependencies(coord_finder_composition
  rclcpp perception_interfaces)

add_executable(lidar_camera_fuser_composition
  src/lidar_camera_fuser_composition.cpp)
target_link_libraries(lidar_camera_fuser_composition
lidar_camera_fuser_component)
ament_target_dependencies(lidar_camera_fuser_composition
  rclcpp perception_interfaces)

target_link_libraries(lidar_prop_detector_composition
  ${YAML_CPP_LIBRARIES}
  liblidar_calculations
  libhelpers
)

target_link_libraries(lidar_camera_fuser_composition
  ${YAML_CPP_LIBRARIES}
  liblidar_calculations
  libhelpers
)

install(TARGETS
  lidar_prop_detector_composition
  coord_finder_composition
  lidar_camera_fuser_composition
  DESTINATION lib/${PROJECT_NAME})

ament_package()
