cmake_minimum_required(VERSION 3.5)
project(auv_ros)

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
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(custom_msg_srv REQUIRED)
find_package(message_filters REQUIRED)

include_directories(include/${PROJECT_NAME})

add_executable(pid_recombiner_sync src/pid_recombiner_sync.cpp)
ament_target_dependencies(pid_recombiner_sync rclcpp geometry_msgs custom_msg_srv message_filters)

add_executable(pid_recombiner src/pid_recombiner.cpp)
ament_target_dependencies(pid_recombiner rclcpp geometry_msgs custom_msg_srv)

add_executable(imu_repub src/imu_repub.cpp)
ament_target_dependencies(imu_repub rclcpp geometry_msgs sensor_msgs custom_msg_srv)

install(TARGETS imu_repub pid_recombiner pid_recombiner_sync DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME})

ament_package()
