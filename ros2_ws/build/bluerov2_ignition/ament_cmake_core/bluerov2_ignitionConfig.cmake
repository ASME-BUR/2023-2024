# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_bluerov2_ignition_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED bluerov2_ignition_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(bluerov2_ignition_FOUND FALSE)
  elseif(NOT bluerov2_ignition_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(bluerov2_ignition_FOUND FALSE)
  endif()
  return()
endif()
set(_bluerov2_ignition_CONFIG_INCLUDED TRUE)

# output package information
if(NOT bluerov2_ignition_FIND_QUIETLY)
  message(STATUS "Found bluerov2_ignition: 0.1.0 (${bluerov2_ignition_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'bluerov2_ignition' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${bluerov2_ignition_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(bluerov2_ignition_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${bluerov2_ignition_DIR}/${_extra}")
endforeach()
