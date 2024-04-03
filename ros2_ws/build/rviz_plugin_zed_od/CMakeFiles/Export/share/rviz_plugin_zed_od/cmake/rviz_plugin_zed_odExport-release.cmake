#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rviz_plugin_zed_od::rviz_plugin_zed_od" for configuration "Release"
set_property(TARGET rviz_plugin_zed_od::rviz_plugin_zed_od APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rviz_plugin_zed_od::rviz_plugin_zed_od PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librviz_plugin_zed_od.so"
  IMPORTED_SONAME_RELEASE "librviz_plugin_zed_od.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rviz_plugin_zed_od::rviz_plugin_zed_od )
list(APPEND _IMPORT_CHECK_FILES_FOR_rviz_plugin_zed_od::rviz_plugin_zed_od "${_IMPORT_PREFIX}/lib/librviz_plugin_zed_od.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
