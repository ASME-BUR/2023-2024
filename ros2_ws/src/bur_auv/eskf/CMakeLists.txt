cmake_minimum_required(VERSION 3.5)
project(eskf)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


# Include directories
include_directories(
  include/eskf
  ${Eigen3_INCLUDE_DIRS}
  ${mavros_INCLUDE_DIRS}
)

# Build shared library
add_library(eskf SHARED
  src/eskf.cpp
)

# Link relevant libraries
# target_link_libraries(eskf
# ${rclcpp_LIBRARIES}
# ${std_msgs_LIBRARIES}
# ${geometry_msgs_LIBRARIES}
# ${sensor_msgs_LIBRARIES}
# ${nav_msgs_LIBRARIES}
# ${message_filters_LIBRARIES}
# ${message_runtime_LIBRARIES}
# ${Eigen3_LIBRARIES}
# ${mavros_msgs_LIBRARIES}
# )

target_include_directories(eskf
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

ament_target_dependencies(eskf rclcpp std_msgs geometry_msgs sensor_msgs 
                          nav_msgs message_filters Eigen3 mavros_msgs)
ament_export_dependencies(rclcpp std_msgs geometry_msgs sensor_msgs 
                          nav_msgs message_filters Eigen3 mavros_msgs)
ament_export_targets(export_eskf HAS_LIBRARY_TARGET)

# Install shared library
install(TARGETS eskf
  EXPORT export_eskf
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Build main filter
add_executable(eskf_node
  src/eskf_node.cpp
  src/eskf.cpp
  src/Node.cpp
)
ament_target_dependencies(eskf_node rclcpp std_msgs geometry_msgs sensor_msgs 
                          nav_msgs message_filters Eigen3 mavros_msgs)
# Install executable
install(TARGETS eskf_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files if any
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

# Create ament package
ament_package()
