cmake_minimum_required(VERSION 3.5)
project(controller)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(rcutils REQUIRED)
find_package(realtime_tools REQUIRED)
# find_package(message_generation REQUIRED)
find_package(bur_rov_msgs REQUIRED)
find_package(control_toolbox REQUIRED)


# find_package(ament_cmake_auto REQUIRED)
# ament_auto_find_build_dependencies()

# rosidl_generate_interfaces(
#   DEPENDENCIES geometry_msgs sensor_msgs std_msgs
# )

# catkin_package()

# Include directories
include_directories(
  REQUIRED
  include/controller
)

# Create ament package

add_library(PID SHARED
  src/pid.cpp
)

target_link_libraries(PID 
${rclcpp_LIBRARIES}
${rcutils_LIBRARIES}
)


ament_target_dependencies(PID rclcpp realtime_tools message_filters control_toolbox)
ament_export_dependencies(rclcpp realtime_tools message_filters control_toolbox)
ament_export_targets(export_PID HAS_LIBRARY_TARGET)

# Install shared library
install(TARGETS PID
  EXPORT export_PID
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Build main filter
add_executable(${PROJECT_NAME}
  src/ControllerNode.cpp
)

# Link relevant libraries
target_link_libraries(${PROJECT_NAME}
${rclcpp_LIBRARIES}
${std_msgs_LIBRARIES}
${geometry_msgs_LIBRARIES}
${sensor_msgs_LIBRARIES}
PID
)
target_link_libraries(${PROJECT_NAME} tinyxml)

ament_target_dependencies(${PROJECT_NAME} rclcpp realtime_tools message_filters control_toolbox)

# Install executable
install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files if any
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()

