# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_state-estimation_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED state-estimation_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(state-estimation_FOUND FALSE)
  elseif(NOT state-estimation_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(state-estimation_FOUND FALSE)
  endif()
  return()
endif()
set(_state-estimation_CONFIG_INCLUDED TRUE)

# output package information
if(NOT state-estimation_FIND_QUIETLY)
  message(STATUS "Found state-estimation: 0.0.1 (${state-estimation_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'state-estimation' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${state-estimation_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(state-estimation_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${state-estimation_DIR}/${_extra}")
endforeach()
