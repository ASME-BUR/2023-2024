cmake_minimum_required(VERSION 3.16.3) # version on Ubuntu Focal
project(bur_auv_planner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# DEPENDENCIES
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED )
find_package(rclcpp_action REQUIRED )
find_package(behaviortree_cpp_v3 REQUIRED )
find_package(ament_index_cpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav2_behavior_tree REQUIRED)
find_package(orca_nav2 REQUIRED)
# find_package(pure_pursuit_controller_3d REQUIRED)


set(THIS_PACKAGE_INCLUDE_DEPENDS
    behaviortree_cpp_v3
    rclcpp
    geometry_msgs
    std_msgs
    nav2_behavior_tree
    orca_nav2
    )

# macro to remove some boiler plate
function(add_target_dependencies target)
    target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
    ament_target_dependencies(${target} ${THIS_PACKAGE_INCLUDE_DEPENDS})
#    rosidl_target_interfaces(${target} ${PROJECT_NAME} "rosidl_typesupport_cpp")
endfunction()

# EXECUTABLES

add_executable(bur_planner src/bur_planner.cpp)
add_target_dependencies(bur_planner pure_pursuit_controller_3d)

# target_link_libraries(${PROJECT_NAME}
# ${rclcpp_LIBRARIES}
# ${std_msgs_LIBRARIES}
# ${geometry_msgs_LIBRARIES}
# )

install(TARGETS bur_planner
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch behavior_trees
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

ament_export_dependencies(behaviortree_cpp_v3)

ament_package()
