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
  "geographic_msgs")
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
  rclcpp)
install(TARGETS
  maneuvering_composition
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(maneuvering_composition
  ${YAML_CPP_LIBRARIES}
  libtask_lib
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