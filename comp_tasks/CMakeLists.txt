cmake_minimum_required(VERSION 3.8)
project(comp_tasks)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ----------------------------
# Find dependencies
# ----------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(composition REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(geographic_msgs REQUIRED)
find_package(comp_tasks_interfaces REQUIRED)
find_package(yolov8_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};/usr/share/cmake/geographiclib")
find_package(GeographicLib REQUIRED)

if(GeographicLib_FOUND)
  message(STATUS "GeographicLib found!")
  message(STATUS "Include path: ${GeographicLib_INCLUDE_DIRS}")
  message(STATUS "Libraries: ${GeographicLib_LIBRARIES}")
else()
  message(FATAL_ERROR "GeographicLib not found!")
endif()

# ----------------------------
# Include directories
# ----------------------------
include_directories(
  include
  ${tf2_INCLUDE_DIRS}
)

# ----------------------------
# Install launch and config
# ----------------------------
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

# ----------------------------
# Libraries
# ----------------------------
add_library(libtask_lib lib/task_lib.cpp)
ament_target_dependencies(libtask_lib
  rclcpp
  mavros_msgs
  sensor_msgs
  geographic_msgs
  tf2
  tf2_geometry_msgs
)

add_library(libbbox_calculations lib/bbox_calculations.cpp)
ament_target_dependencies(libbbox_calculations
  rclcpp
  geometry_msgs
  yolov8_msgs
)

# ----------------------------
# Task components
# ----------------------------
add_library(task_component SHARED src/task_component.cpp)
target_compile_definitions(task_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(task_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  sensor_msgs
  geographic_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
)
target_link_libraries(task_component yaml-cpp)
install(TARGETS task_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_library(task_controller_component SHARED src/task_controller_component.cpp)
target_compile_definitions(task_controller_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(task_controller_component
  rclcpp
  rclcpp_components
  std_msgs
  lifecycle_msgs
)
rclcpp_components_register_nodes(task_controller_component "comp_tasks::TaskController")
install(TARGETS task_controller_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(task_controller_composition src/task_controller_composition.cpp)
ament_target_dependencies(task_controller_composition rclcpp)
target_link_libraries(task_controller_composition
  task_controller_component
)
install(TARGETS task_controller_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# Retrace components
# ----------------------------
add_library(retrace_component SHARED src/utils/retrace_component.cpp)
target_compile_definitions(retrace_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(retrace_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  geographic_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
  yaml-cpp
)
rclcpp_components_register_nodes(retrace_component "comp_tasks::Retrace")
install(TARGETS retrace_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(retrace_composition src/utils/retrace_composition.cpp)
ament_target_dependencies(retrace_composition rclcpp)
target_link_libraries(retrace_composition
  retrace_component
  task_component
  libtask_lib
  yaml-cpp
)
install(TARGETS retrace_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# Home component
# ----------------------------
add_library(home_component SHARED src/comp_tasks/home_component.cpp)
target_compile_definitions(home_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(home_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  geographic_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
  yaml-cpp
)
rclcpp_components_register_nodes(home_component "comp_tasks::Home")
install(TARGETS home_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(home_composition src/comp_tasks/home_composition.cpp)
ament_target_dependencies(home_composition rclcpp)
target_link_libraries(home_composition
  home_component
  task_component
  libtask_lib
  libbbox_calculations
  yaml-cpp
)
install(TARGETS home_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# Maneuvering component
# ----------------------------
add_library(maneuvering_component SHARED src/comp_tasks/maneuvering_component.cpp)
target_compile_definitions(maneuvering_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(maneuvering_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  geographic_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
  yaml-cpp
)
rclcpp_components_register_nodes(maneuvering_component "comp_tasks::Maneuvering")
install(TARGETS maneuvering_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(maneuvering_composition src/comp_tasks/maneuvering_composition.cpp)
ament_target_dependencies(maneuvering_composition rclcpp)
target_link_libraries(maneuvering_composition
  maneuvering_component
  task_component
  libtask_lib
  libbbox_calculations
  yaml-cpp
)
install(TARGETS maneuvering_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# Speed component
# ----------------------------
add_library(speed_component SHARED src/comp_tasks/speed_component.cpp)
target_compile_definitions(speed_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(speed_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  geographic_msgs
  geometry_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
  yaml-cpp
)
rclcpp_components_register_nodes(speed_component "comp_tasks::Speed")
install(TARGETS speed_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(speed_composition src/comp_tasks/speed_composition.cpp)
ament_target_dependencies(speed_composition rclcpp)
target_link_libraries(speed_composition
  speed_component
  task_component
  libtask_lib
  libbbox_calculations
  yaml-cpp
)
install(TARGETS speed_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# MavROS Republisher component
# ----------------------------
add_library(mavros_repub_component SHARED src/utils/mavros_repub_component.cpp)
target_compile_definitions(mavros_repub_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(mavros_repub_component
  rclcpp
  rclcpp_components
  std_msgs
  mavros_msgs
  geographic_msgs
  geometry_msgs
  comp_tasks_interfaces
  yolov8_msgs
  tf2
  tf2_geometry_msgs
  rclcpp_lifecycle
)
rclcpp_components_register_nodes(mavros_repub_component "comp_tasks::MavROSRepublisher")
install(TARGETS mavros_repub_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

add_executable(mavros_repub_composition src/utils/mavros_repub_composition.cpp)
ament_target_dependencies(mavros_repub_composition rclcpp)
target_link_libraries(mavros_repub_composition
  mavros_repub_component
  libtask_lib
  libbbox_calculations
  yaml-cpp
)
install(TARGETS mavros_repub_composition DESTINATION lib/${PROJECT_NAME})

# ----------------------------
# Global <-> Local executables
# ----------------------------
add_executable(global_to_local src/utils/global_to_local.cpp)
target_include_directories(global_to_local PRIVATE ${GeographicLib_INCLUDE_DIRS})
ament_target_dependencies(global_to_local
  rclcpp
  sensor_msgs
  geographic_msgs
  geometry_msgs
  yaml-cpp
)
target_link_libraries(global_to_local
  ${GeographicLib_LIBRARIES}
)
install(TARGETS global_to_local DESTINATION lib/${PROJECT_NAME})

add_executable(local_to_global src/utils/local_to_global.cpp)
target_include_directories(local_to_global PRIVATE ${GeographicLib_INCLUDE_DIRS})
ament_target_dependencies(local_to_global
  rclcpp
  sensor_msgs
  geographic_msgs
  geometry_msgs
  comp_tasks_interfaces
  yaml-cpp
)
target_link_libraries(local_to_global
  ${GeographicLib_LIBRARIES}
)
install(TARGETS local_to_global DESTINATION lib/${PROJECT_NAME})

# ----------------------------
ament_package()
