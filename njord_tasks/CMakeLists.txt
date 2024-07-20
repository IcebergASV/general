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
