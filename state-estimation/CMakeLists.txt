cmake_minimum_required(VERSION 3.5)
project(state-estimation)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(message_filters REQUIRED)
# find_package(message_generation REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


# find_package(ament_cmake_auto REQUIRED)
# ament_auto_find_build_dependencies()

# rosidl_generate_interfaces(
#   DEPENDENCIES geometry_msgs sensor_msgs std_msgs
# )

# Include directories
include_directories(
  include/eskf
  # ${catkin_INCLUDE_DIRS}
  ${Eigen3_INCLUDE_DIRS}
  ${mavros_INCLUDE_DIRS}
)

# Create ament package
ament_package()

# Build shared library
add_library(ESKF SHARED
  src/ESKF.cpp
)



# Build main filter
add_executable(${PROJECT_NAME}
  src/eskf.cpp
  src/Node.cpp
)

# Link relevant libraries
target_link_libraries(${PROJECT_NAME}
ESKF
${rclcpp_LIBRARIES}
${std_msgs_LIBRARIES}
${geometry_msgs_LIBRARIES}
${sensor_msgs_LIBRARIES}
${nav_msgs_LIBRARIES}
${message_filters_LIBRARIES}
${message_runtime_LIBRARIES}
${Eigen3_LIBRARIES}
${mavros_msgs_LIBRARIES}
)

# Install executable
install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

# Install shared library
install(TARGETS ESKF
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Install include directory
install(DIRECTORY include/
  DESTINATION include
)

# Install launch files if any
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

