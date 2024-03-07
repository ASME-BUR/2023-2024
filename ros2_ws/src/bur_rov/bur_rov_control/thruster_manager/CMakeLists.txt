cmake_minimum_required(VERSION 3.5)
project(thruster_manager)

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
# find_package(eigen3 REQUIRED)
find_package(bur_rov_msgs REQUIRED)


include_directories(include/${PROJECT_NAME} include/utilities)

add_executable(thruster_manager src/thruster_manager.cpp src/utilities/common_functions.cpp)
# ament_target_dependencies(thruster_manager rclcpp geometry_msgs eigen3 bur_rov_msgs)
ament_target_dependencies(thruster_manager rclcpp geometry_msgs bur_rov_msgs)

target_include_directories(
  thruster_manager PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
             "$<INSTALL_INTERFACE:include>")

install(TARGETS thruster_manager DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_package()
