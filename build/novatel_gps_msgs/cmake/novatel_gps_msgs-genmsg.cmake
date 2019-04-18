# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "novatel_gps_msgs: 20 messages, 1 services")

set(MSG_I_FLAGS "-Inovatel_gps_msgs:/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(novatel_gps_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" "novatel_gps_msgs/Satellite:std_msgs/Header"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" "novatel_gps_msgs/NovatelReceiverStatus:novatel_gps_msgs/RangeInformation:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" "novatel_gps_msgs/NovatelReceiverStatus:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" "novatel_gps_msgs/NovatelReceiverStatus:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" "novatel_gps_msgs/NovatelReceiverStatus:novatel_gps_msgs/NovatelExtendedSolutionStatus:std_msgs/Header:novatel_gps_msgs/NovatelSignalMask:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" "novatel_gps_msgs/NovatelReceiverStatus:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" "novatel_gps_msgs/NovatelReceiverStatus:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" "novatel_gps_msgs/NovatelReceiverStatus:novatel_gps_msgs/NovatelExtendedSolutionStatus:std_msgs/Header:novatel_gps_msgs/NovatelMessageHeader"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" "novatel_gps_msgs/NovatelReceiverStatus"
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" ""
)

get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_custom_target(_novatel_gps_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "novatel_gps_msgs" "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" "std_msgs/Header:novatel_gps_msgs/TrackstatChannel"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Services
_generate_srv_cpp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Module File
_generate_module_cpp(novatel_gps_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(novatel_gps_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(novatel_gps_msgs_generate_messages novatel_gps_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_cpp _novatel_gps_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(novatel_gps_msgs_gencpp)
add_dependencies(novatel_gps_msgs_gencpp novatel_gps_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS novatel_gps_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Services
_generate_srv_eus(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Module File
_generate_module_eus(novatel_gps_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(novatel_gps_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(novatel_gps_msgs_generate_messages novatel_gps_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_eus _novatel_gps_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(novatel_gps_msgs_geneus)
add_dependencies(novatel_gps_msgs_geneus novatel_gps_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS novatel_gps_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Services
_generate_srv_lisp(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Module File
_generate_module_lisp(novatel_gps_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(novatel_gps_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(novatel_gps_msgs_generate_messages novatel_gps_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_lisp _novatel_gps_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(novatel_gps_msgs_genlisp)
add_dependencies(novatel_gps_msgs_genlisp novatel_gps_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS novatel_gps_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Services
_generate_srv_nodejs(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Module File
_generate_module_nodejs(novatel_gps_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(novatel_gps_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(novatel_gps_msgs_generate_messages novatel_gps_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_nodejs _novatel_gps_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(novatel_gps_msgs_gennodejs)
add_dependencies(novatel_gps_msgs_gennodejs novatel_gps_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS novatel_gps_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg"
  "${MSG_I_FLAGS}"
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)
_generate_msg_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Services
_generate_srv_py(novatel_gps_msgs
  "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
)

### Generating Module File
_generate_module_py(novatel_gps_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(novatel_gps_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(novatel_gps_msgs_generate_messages novatel_gps_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgga.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/srv/NovatelFRESET.srv" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsv.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelExtendedSolutionStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/TrackstatChannel.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gpgsa.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Range.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelVelocity.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Gprmc.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inspva.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelPosition.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelCorrectedImuData.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Time.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Inscov.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelReceiverStatus.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Insstdev.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Satellite.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelMessageHeader.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/NovatelSignalMask.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/RangeInformation.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg/Trackstat.msg" NAME_WE)
add_dependencies(novatel_gps_msgs_generate_messages_py _novatel_gps_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(novatel_gps_msgs_genpy)
add_dependencies(novatel_gps_msgs_genpy novatel_gps_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS novatel_gps_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/novatel_gps_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(novatel_gps_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/novatel_gps_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(novatel_gps_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/novatel_gps_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(novatel_gps_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/novatel_gps_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(novatel_gps_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/novatel_gps_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(novatel_gps_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
