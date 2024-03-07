cmake_minimum_required(VERSION 3.5)
project(pid)

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
# find_package(std_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(custom_msg_srv REQUIRED)

include_directories(include/${PROJECT_NAME})

add_library(pid_component SHARED src/pid_component.cpp src/pid.cpp)
ament_target_dependencies(pid_component rclcpp custom_msg_srv)
rclcpp_components_register_nodes(pid_component "Pid_component")
# To register multiple components in the same shared library, use multiple calls
# rclcpp_components_register_nodes(talker_component "composition::Talker2")

set(HEADER_FILES include/pid/pid.hpp)
add_library(pid SHARED src/pid.cpp ${HEADER_FILES})

target_include_directories(
  pid PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
             $<INSTALL_INTERFACE:include/pid>)

ament_export_targets(pidTargets HAS_LIBRARY_TARGET)

install(DIRECTORY include/ DESTINATION include)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

install(
  TARGETS pid
  EXPORT pidTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)

install(
  TARGETS pid_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include/${PROJECT_NAME})

ament_package()
