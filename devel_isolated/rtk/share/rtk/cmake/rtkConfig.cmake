# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(rtk_CONFIG_INCLUDED)
  return()
endif()
set(rtk_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(rtk_SOURCE_PREFIX /home/nishanth/TurtleStuff/turtle_drive/src/rtk)
  set(rtk_DEVEL_PREFIX /home/nishanth/TurtleStuff/turtle_drive/devel_isolated/rtk)
  set(rtk_INSTALL_PREFIX "")
  set(rtk_PREFIX ${rtk_DEVEL_PREFIX})
else()
  set(rtk_SOURCE_PREFIX "")
  set(rtk_DEVEL_PREFIX "")
  set(rtk_INSTALL_PREFIX /home/nishanth/TurtleStuff/turtle_drive/install_isolated)
  set(rtk_PREFIX ${rtk_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'rtk' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(rtk_FOUND_CATKIN_PROJECT TRUE)

if(NOT " " STREQUAL " ")
  set(rtk_INCLUDE_DIRS "")
  set(_include_dirs "")
  if(NOT " " STREQUAL " ")
    set(_report "Check the issue tracker '' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT " " STREQUAL " ")
    set(_report "Check the website '' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'agbot <agbot@todo.todo>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${rtk_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'rtk' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'rtk' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/nishanth/TurtleStuff/turtle_drive/src/rtk/${idir}'.  ${_report}")
    endif()
    _list_append_unique(rtk_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND rtk_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND rtk_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND rtk_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/nishanth/TurtleStuff/turtle_drive/devel_isolated/rtk/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/rqt_joint_trajectory_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ros_controllers/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_driver/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_msgs/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_diagnostics/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/qtros/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/position_controllers/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_imu/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_gps_driver/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_gps_msgs/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/laser_proc/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/jpeg_streamer/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/joint_trajectory_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/joint_state_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/imu_sensor_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_trajectory_server/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_slam_launch/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_slam/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_map_server/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_geotiff_plugins/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_geotiff/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_nav_msgs/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_marker_drawing/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_mapping/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_compressed_map_transport/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_map_tools/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_imu_tools/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_imu_attitude_to_tf/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/gripper_action_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/four_wheel_steering_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/effort_controllers/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/forward_command_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/force_torque_sensor_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/driver_common/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/driver_base/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ackermann_steering_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/diff_drive_controller/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/camera_umd/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ar_track_alvar/lib;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ar_track_alvar_msgs/lib;/home/nishanth/TurtleStuff/turtle_drive/devel/lib;/opt/ros/kinetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(rtk_LIBRARY_DIRS ${lib_path})
      list(APPEND rtk_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'rtk'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND rtk_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(rtk_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${rtk_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 rtk_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${rtk_dep}_FOUND)
      find_package(${rtk_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${rtk_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(rtk_INCLUDE_DIRS ${${rtk_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(rtk_LIBRARIES ${rtk_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${rtk_dep}_LIBRARIES})
  _list_append_deduplicate(rtk_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(rtk_LIBRARIES ${rtk_LIBRARIES})

  _list_append_unique(rtk_LIBRARY_DIRS ${${rtk_dep}_LIBRARY_DIRS})
  list(APPEND rtk_EXPORTED_TARGETS ${${rtk_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${rtk_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
