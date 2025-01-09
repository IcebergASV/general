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
  )
#rclcpp_components_register_nodes(task_component "comp_tasks::Task")
#set(node_plugins "comp_tasks::Task;$<TARGET_FILE:task_component>\n")
install(TARGETS
  task_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)



# add_library(task_component SHARED src/task_component.cpp)
# target_compile_definitions(task_component PRIVATE "COMPOSITION_BUILDING_DLL")
# ament_target_dependencies(task_component
#   "rclcpp"
#   "rclcpp_components"
#   "std_msgs"
#   "mavros_msgs"
#   "geographic_msgs"
#   "comp_tasks_interfaces")
# rclcpp_components_register_nodes(task_component "comp_tasks::Task")
# set(node_plugins "comp_tasks::Task;$<TARGET_FILE:task_component>\n")
# install(TARGETS
#   task_component
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   RUNTIME DESTINATION bin)


  add_executable(detection_filter
  src/detection_filter.cpp)
  ament_target_dependencies(detection_filter
  rclcpp yolov8_msgs comp_tasks_interfaces)
  install(TARGETS
  detection_filter
  DESTINATION lib/${PROJECT_NAME})


# # Add executable for task
# add_executable(task_composition
#   src/task_composition.cpp)
# target_link_libraries(task_composition
# task_component)
# ament_target_dependencies(task_composition
#   rclcpp comp_tasks_interfaces)
# install(TARGETS
#   task_composition
#   DESTINATION lib/${PROJECT_NAME})

# target_link_libraries(task_composition
#   ${YAML_CPP_LIBRARIES}
#   libtask_lib
# )

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
rclcpp_components_register_nodes(wp_sender_component "comp_tasks::WPSender")
set(node_plugins "comp_tasks::WPSender;$<TARGET_FILE:wp_sender_component>\n")
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

add_library(nav_channel_component SHARED src/nav_channel_component.cpp)
target_compile_definitions(nav_channel_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(nav_channel_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "mavros_msgs"
  "geographic_msgs"
  "comp_tasks_interfaces"
  "yolov8_msgs"
  "tf2"
  "tf2_geometry_msgs"
  "rclcpp_lifecycle")
rclcpp_components_register_nodes(nav_channel_component "comp_tasks::NavChannel")
set(node_plugins "comp_tasks::NavChannel;$<TARGET_FILE:nav_channel_component>\n")
install(TARGETS
  nav_channel_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for nav_channel
add_executable(nav_channel_composition
  src/nav_channel_composition.cpp)
target_link_libraries(nav_channel_composition
nav_channel_component)
ament_target_dependencies(nav_channel_composition
  rclcpp)
install(TARGETS
  nav_channel_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(nav_channel_composition
  ${YAML_CPP_LIBRARIES}
  task_component
  libtask_lib
  libbbox_calculations
)

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
  "rclcpp_lifecycle")
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
)

add_library(test_life_cycle_node_component SHARED src/test_life_cycle_node_component.cpp)
target_compile_definitions(test_life_cycle_node_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(test_life_cycle_node_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
  "lifecycle_msgs"
  "rclcpp_lifecycle"
  )
rclcpp_components_register_nodes(test_life_cycle_node_component "comp_tasks::TestLifeCycleNode")
set(node_plugins "comp_tasks::TestLifeCycleNode;$<TARGET_FILE:test_life_cycle_node_component>\n")
install(TARGETS
  test_life_cycle_node_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Add executable for test_life_cycle_node
add_executable(test_life_cycle_node_composition
  src/test_life_cycle_node_composition.cpp)
target_link_libraries(test_life_cycle_node_composition
test_life_cycle_node_component)
ament_target_dependencies(test_life_cycle_node_composition
  rclcpp)
install(TARGETS
  test_life_cycle_node_composition
  DESTINATION lib/${PROJECT_NAME})
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
