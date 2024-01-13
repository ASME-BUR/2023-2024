cmake_minimum_required(VERSION 3.16.3) # version on Ubuntu Focal
project(bt_test)

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

set(THIS_PACKAGE_INCLUDE_DEPENDS
    behaviortree_cpp)

#add_library(bt_test src/bt_test.cpp)
#ament_target_dependencies(bt_test ${THIS_PACKAGE_INCLUDE_DEPENDS})
#ament_target_dependencies()

# macro to remove some boiler plate
function(add_target_dependencies target)
    target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
    ament_target_dependencies(${target} ${THIS_PACKAGE_INCLUDE_DEPENDS})
#    rosidl_target_interfaces(${target} ${PROJECT_NAME} "rosidl_typesupport_cpp")
endfunction()

# EXECUTABLES

add_executable(bt_test src/bt_test.cpp)
add_executable(bur_test src/bur_test.cpp)

add_target_dependencies(bt_test)
ament_target_dependencies(bur_test behaviortree_cpp rclcpp geometry_msgs std_msgs)

#target_include_directories(bur_test PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#  $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME}
${rclcpp_LIBRARIES}
${std_msgs_LIBRARIES}
${geometry_msgs_LIBRARIES}
)

install(TARGETS bt_test
  DESTINATION lib/${PROJECT_NAME})
install(TARGETS bur_test
  DESTINATION lib/${PROJECT_NAME})

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
