cmake_minimum_required(VERSION 3.8)
project(comp_tasks)

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
# Check if the package is found and print some useful information
if(GeographicLib_FOUND)
  message(STATUS "GeographicLib found!")
  message(STATUS "GeographicLib include path: ${GeographicLib_INCLUDE_DIRS}")
  message(STATUS "GeographicLib library path: ${GeographicLib_LIBRARIES}")
else()
  message(FATAL_ERROR "GeographicLib not found!")
endif()

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
)

add_library(libbbox_calculations
  lib/bbox_calculations.cpp
)
ament_target_dependencies(libbbox_calculations
  "geometry_msgs"
  "rclcpp"
  "yolov8_msgs"
)

ament_package()

add_library(maneuvering_component SHARED src/maneuvering_component.cpp)
target_compile_definitions(maneuvering_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(maneuvering_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "comp_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs"
  "rclcpp_lifecycle"
  "yaml-cpp")
rclcpp_components_register_nodes(maneuvering_component "comp_tasks::Maneuvering")
set(node_plugins "comp_tasks::Maneuvering;$<TARGET_FILE:maneuvering_component>\n")
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
  rclcpp)
install(TARGETS
  maneuvering_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(maneuvering_composition
  ${YAML_CPP_LIBRARIES}
  task_component
  libtask_lib
  libbbox_calculations
  yaml-cpp
)

add_library(speed_component SHARED src/speed_component.cpp)
target_compile_definitions(speed_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(speed_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "geometry_msgs"
  "comp_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs"
  "rclcpp_lifecycle"
  "yaml-cpp"
)

rclcpp_components_register_nodes(speed_component "comp_tasks::speed")
set(node_plugins "comp_tasks::speed;$<TARGET_FILE:speed_component>\n")
install(TARGETS
  speed_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for speed
add_executable(speed_composition
  src/speed_composition.cpp)
target_link_libraries(speed_composition
speed_component)
ament_target_dependencies(speed_composition
  rclcpp)
install(TARGETS
  speed_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(speed_composition
  ${YAML_CPP_LIBRARIES}
  task_component
  libtask_lib
  libbbox_calculations
)

add_library(mavros_repub_component SHARED src/mavros_repub_component.cpp)
target_compile_definitions(mavros_repub_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(mavros_repub_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "geometry_msgs"
  "comp_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs"
  "rclcpp_lifecycle"
)

rclcpp_components_register_nodes(mavros_repub_component "comp_tasks::MavROSRepublisher")
set(node_plugins "comp_tasks::MavROSRepublisher;$<TARGET_FILE:mavros_repub_component>\n")
install(TARGETS
mavros_repub_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for mavros_repub
add_executable(mavros_repub_composition
  src/mavros_repub_composition.cpp)
target_link_libraries(mavros_repub_composition
mavros_repub_component)
ament_target_dependencies(mavros_repub_composition
  rclcpp)
install(TARGETS
mavros_repub_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(mavros_repub_composition
  ${YAML_CPP_LIBRARIES}
  libtask_lib
  libbbox_calculations
)

add_library(task_component SHARED src/task_component.cpp)

target_compile_definitions(task_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(task_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "sensor_msgs"
  "geographic_msgs"
  "comp_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs"
  "rclcpp_lifecycle"
  "yaml-cpp"
  )
target_link_libraries(task_component yaml-cpp)

install(TARGETS
  task_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

add_library(task_controller_component SHARED src/task_controller_component.cpp)
target_compile_definitions(task_controller_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(task_controller_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "lifecycle_msgs")
rclcpp_components_register_nodes(task_controller_component "comp_tasks::TaskController")
set(node_plugins "comp_tasks::TaskController;$<TARGET_FILE:task_controller_component>\n")
install(TARGETS
  task_controller_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for task_controller
add_executable(task_controller_composition
  src/task_controller_composition.cpp)
target_link_libraries(task_controller_composition
task_controller_component)
ament_target_dependencies(task_controller_composition
  rclcpp)
install(TARGETS
  task_controller_composition
  DESTINATION lib/${PROJECT_NAME})

add_executable(global_to_local src/global_to_local.cpp)
# Check the system architecture
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    # For x86_64 architecture
    target_link_libraries(global_to_local /usr/lib/x86_64-linux-gnu/libGeographic.so)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
    # For ARM architecture
    target_link_libraries(global_to_local /usr/lib/aarch64-linux-gnu/libGeographic.so)
else()
    message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

ament_target_dependencies(global_to_local rclcpp sensor_msgs geographic_msgs geometry_msgs)
install(TARGETS
global_to_local
  DESTINATION lib/${PROJECT_NAME}
)

add_executable(local_to_global src/local_to_global.cpp)
# Check the system architecture
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    # For x86_64 architecture
    target_link_libraries(local_to_global /usr/lib/x86_64-linux-gnu/libGeographic.so)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
    # For ARM architecture
    target_link_libraries(local_to_global /usr/lib/aarch64-linux-gnu/libGeographic.so)
else()
    message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

ament_target_dependencies(local_to_global rclcpp sensor_msgs geographic_msgs geometry_msgs comp_tasks_interfaces)
install(TARGETS
local_to_global
  DESTINATION lib/${PROJECT_NAME}
)
