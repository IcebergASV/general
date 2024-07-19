cmake_minimum_required(VERSION 3.8)
project(njord_maneuvering)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(composition REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(perception_interfaces REQUIRED)
find_package(perception REQUIRED)

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

include_directories(include ${tf2_INCLUDE_DIRS})

add_library(maneuvering_node_component SHARED src/maneuvering_node.cpp)
target_compile_definitions(maneuvering_node_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(maneuvering_node_component
  rclcpp
  rclcpp_components
  geometry_msgs
  mavros_msgs
  tf2
  tf2_geometry_msgs
  perception_interfaces
  perception)

rclcpp_components_register_nodes(maneuvering_node_component "njord_maneuvering::ManeuveringNode")
set(node_plugins "${node_plugins}njord_maneuvering::ManeuveringNode;$<TARGET_FILE:maneuvering_node_component>\n")

install(TARGETS
  maneuvering_node_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}/)

add_executable(node_composition
  src/node_composition.cpp)
target_link_libraries(node_composition
  maneuvering_node_component)
ament_target_dependencies(node_composition
  rclcpp)

install(TARGETS
  node_composition
  DESTINATION lib/${PROJECT_NAME})

ament_package()
