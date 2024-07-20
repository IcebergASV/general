cmake_minimum_required(VERSION 3.8)
project(velocity_sender)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


# Include directories
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

add_executable( velocity_sender src/velocity_sender_component.cpp)

ament_target_dependencies(velocity_sender
  rclcpp
  tf2
  tf2_geometry_msgs
  mavros_msgs
)

install(TARGETS
  velocity_sender
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME})

ament_package()


# cmake_minimum_required(VERSION 3.8)
# project(velocity_sender)

# add_library(velocity_sender_component SHARED src/velocity_sender_component.cpp)
# target_compile_definitions(velocity_sender_component PRIVATE "COMPOSITION_BUILDING_DLL")

# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(mavros_msgs REQUIRED)
# find_package(tf2 REQUIRED)
# find_package(tf2_geometry_msgs REQUIRED)

# include_directories(
#     include
#     ${tf2_INCLUDE_DIRS}
# )

# ament_target_dependencies(velocity_sender_component
#   rclcpp
#   tf2
#   tf2_geometry_msgs
#   mavros_msgs
#   )
# rclcpp_components_register_nodes(velocity_sender_component "velocity_sender::VelocitySender")
# set(node_plugins "velocity_sender::VelocitySender;$<TARGET_FILE:velocity_sender_component>\n")
# install(TARGETS
#   velocity_sender_component
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   RUNTIME DESTINATION bin)

# # Add executable for velocity_sender
# add_executable(velocity_sender_composition
#   src/velocity_sender_composition.cpp)
# target_link_libraries(velocity_sender_composition
# velocity_sender_component)
# ament_target_dependencies(velocity_sender_composition
#   rclcpp)
# install(TARGETS
#   velocity_sender_composition
#   DESTINATION lib/${PROJECT_NAME})
