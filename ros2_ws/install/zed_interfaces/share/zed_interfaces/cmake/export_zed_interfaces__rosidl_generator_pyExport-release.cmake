#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "zed_interfaces::zed_interfaces__rosidl_generator_py" for configuration "Release"
set_property(TARGET zed_interfaces::zed_interfaces__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(zed_interfaces::zed_interfaces__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libzed_interfaces__rosidl_generator_py.so"
  IMPORTED_SONAME_RELEASE "libzed_interfaces__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS zed_interfaces::zed_interfaces__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_zed_interfaces::zed_interfaces__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libzed_interfaces__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
