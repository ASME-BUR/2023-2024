cmake_minimum_required(VERSION 3.16.3) # version on Ubuntu Focal
project(simple_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# DEPENDENCIES
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED )
find_package(rclcpp_action REQUIRED )
find_package(behaviortree_cpp REQUIRED )
find_package(ament_index_cpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav2_behavior_tree REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    behaviortree_cpp
    nav2_behavior_tree
    rclcpp
    geometry_msgs
    std_msgs
    rclcpp_action)

# macro to remove some boiler plate
function(add_target_dependencies target)
    target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
    ament_target_dependencies(${target} ${THIS_PACKAGE_INCLUDE_DEPENDS})
#    rosidl_target_interfaces(${target} ${PROJECT_NAME} "rosidl_typesupport_cpp")
endfunction()

# EXECUTABLES

add_executable(simple_manager src/manager_node.cpp src/bt_nodes.cpp)

add_target_dependencies(simple_manager)

#target_include_directories(simple_manager PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#  $<INSTALL_INTERFACE:include>)

# target_link_libraries(${PROJECT_NAME}
# ${rclcpp_LIBRARIES}
# ${std_msgs_LIBRARIES}
# ${geometry_msgs_LIBRARIES}
# )

install(TARGETS simple_manager
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY behavior_trees launch params
  DESTINATION share/${PROJECT_NAME}/)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_dependencies(behaviortree_cpp)

ament_package()
