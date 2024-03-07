cmake_minimum_required(VERSION 3.5)
project(drivers)

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

include_directories(src/xsens_mti_i2c/ src/raspi_dma_pwm/ src/lps331ap_i2c/
                    src/bar30_depth_sensor/)

set(HEADER_FILES src/xsens_mti_i2c/Xbus.h src/xsens_mti_i2c/MTi.h)
add_library(xsens_mti_i2c SHARED src/xsens_mti_i2c/MTi.cpp
                                 src/xsens_mti_i2c/Xbus.cpp ${HEADER_FILES})

set(HEADER_FILES src/raspi_dma_pwm/raspi_dma_pwm.h)
add_library(raspi_dma_pwm SHARED src/raspi_dma_pwm/raspi_dma_pwm.cpp
                                 ${HEADER_FILES})

set(HEADER_FILES src/lps331ap_i2c/LPS.h)
add_library(lps331ap_i2c SHARED src/lps331ap_i2c/LPS.cpp ${HEADER_FILES})

set(HEADER_FILES src/bar30_depth_sensor/MS5837.h)
add_library(bar30_depth_sensor SHARED src/bar30_depth_sensor/MS5837.cpp
                                      ${HEADER_FILES})

target_include_directories(
  xsens_mti_i2c PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                       $<INSTALL_INTERFACE:include/xsens_mti_i2c>)
target_include_directories(
  raspi_dma_pwm PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                       $<INSTALL_INTERFACE:include/raspi_dma_pwm>)
target_include_directories(
  lps331ap_i2c PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                      $<INSTALL_INTERFACE:include/lps331ap_i2c>)
target_include_directories(
  bar30_depth_sensor
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/bar30_depth_sensor>)

ament_export_targets(xsens_mti_i2cTargets HAS_LIBRARY_TARGET)
ament_export_targets(raspi_dma_pwmTargets HAS_LIBRARY_TARGET)
ament_export_targets(lps331ap_i2cTargets HAS_LIBRARY_TARGET)
ament_export_targets(bar30_depth_sensorTargets HAS_LIBRARY_TARGET)

target_link_libraries(xsens_mti_i2c pigpiod_if2)
target_link_libraries(raspi_dma_pwm pigpiod_if2)
target_link_libraries(lps331ap_i2c pigpiod_if2)
target_link_libraries(bar30_depth_sensor pigpiod_if2)

install(DIRECTORY src/ DESTINATION include)

install(
  TARGETS xsens_mti_i2c
  EXPORT xsens_mti_i2cTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)

install(
  TARGETS raspi_dma_pwm
  EXPORT raspi_dma_pwmTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)

install(
  TARGETS lps331ap_i2c
  EXPORT lps331ap_i2cTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)

install(
  TARGETS bar30_depth_sensor
  EXPORT bar30_depth_sensorTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)

ament_package()
