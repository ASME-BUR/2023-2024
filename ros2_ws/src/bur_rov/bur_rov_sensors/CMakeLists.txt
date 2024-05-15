cmake_minimum_required(VERSION 3.5)
project(bur_rov_sensors)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in further dependencies
# manually. find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(drivers REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

include_directories(include/${PROJECT_NAME})

# add_executable(imu_node src/${PROJECT_NAME}/imu_node.cpp)
# ament_target_dependencies(imu_node rclcpp sensor_msgs geometry_msgs)
# target_link_libraries(imu_node drivers::xsens_mti_i2c)

# target_include_directories(
#   imu_node PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
#              "$<INSTALL_INTERFACE:include>")

add_executable(bar30_node src/${PROJECT_NAME}/bar30_node.cpp)
ament_target_dependencies(bar30_node rclcpp geometry_msgs nav_msgs)
target_link_libraries(bar30_node drivers::bar30_depth_sensor)

target_include_directories(
  bar30_node PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
             "$<INSTALL_INTERFACE:include>")

install(TARGETS bar30_node DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()
