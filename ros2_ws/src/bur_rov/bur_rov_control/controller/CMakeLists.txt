cmake_minimum_required(VERSION 3.5)
project(controller)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(bur_rov_msgs REQUIRED)
find_package(control_toolbox REQUIRED)



# rosidl_generate_interfaces(
#   DEPENDENCIES geometry_msgs sensor_msgs std_msgs
# )

# catkin_package()

# Include directories
include_directories(
  REQUIRED
  include/controller
)

# Build main filter
add_executable(${PROJECT_NAME}
  src/ControllerNode.cpp
  src/utility_func.cpp
)

ament_target_dependencies(${PROJECT_NAME} rclcpp control_toolbox bur_rov_msgs)

target_include_directories(
  ${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                  "$<INSTALL_INTERFACE:include>")

# Install executable
install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files if any
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()

