cmake_minimum_required(VERSION 3.5)
project(auv_control)

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
find_package(std_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(auv_msgs REQUIRED)
find_package(drivers REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pid REQUIRED)

include_directories(include/${PROJECT_NAME} include/utilities)

add_executable(motor_controller src/motor_controller.cpp
                                src/utilities/common_functions.cpp)
ament_target_dependencies(motor_controller rclcpp std_msgs auv_msgs)
target_link_libraries(motor_controller drivers::raspi_dma_pwm)

add_executable(motor_controller2 src/motor_controller2.cpp
                                 src/utilities/common_functions.cpp)
ament_target_dependencies(motor_controller2 rclcpp std_msgs auv_msgs)
target_link_libraries(motor_controller2 drivers::raspi_dma_pwm)

add_executable(pid_node src/pid_node.cpp src/utilities/common_functions.cpp)
ament_target_dependencies(pid_node rclcpp std_msgs auv_msgs geometry_msgs
                          sensor_msgs)
target_link_libraries(pid_node pid::pid)

add_executable(thrusters src/thrusters.cpp)
ament_target_dependencies(thrusters rclcpp geometry_msgs auv_msgs)
target_link_libraries(thrusters drivers::raspi_dma_pwm)

target_include_directories(
  motor_controller
  PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
         "$<INSTALL_INTERFACE:include>")

target_include_directories(
  motor_controller2
  PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
         "$<INSTALL_INTERFACE:include>")

target_include_directories(
  pid_node PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                  "$<INSTALL_INTERFACE:include>")

target_include_directories(
  thrusters PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                   "$<INSTALL_INTERFACE:include>")

install(TARGETS thrusters motor_controller pid_node motor_controller2
        DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME})

ament_package()
