cmake_minimum_required(VERSION 3.8)
project(bur_rov)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(bur_rov_msgs REQUIRED)
find_package(bur_rov_sensors REQUIRED)
find_package(controller REQUIRED)
find_package(thruster_manager REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(joy REQUIRED)
find_package(nav_msgs REQUIRED)
# find_package(state_estimation REQUIRED)
# find_package(controller REQUIRED)

include_directories(include/${PROJECT_NAME})

add_executable(joy_command src/joy_command.cpp)
ament_target_dependencies(joy_command tf2 tf2_geometry_msgs nav_msgs rclcpp sensor_msgs bur_rov_msgs joy)

install(TARGETS joy_command DESTINATION lib/${PROJECT_NAME})

# Install launch files.
install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME}/)

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

ament_package()
