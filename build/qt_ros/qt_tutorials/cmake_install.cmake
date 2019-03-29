# Install script for directory: /home/nishanth/TurtleStuff/turtle_drive/src/qt_ros/qt_tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nishanth/TurtleStuff/turtle_drive/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qt_tutorials/srv" TYPE FILE FILES "/home/nishanth/TurtleStuff/turtle_drive/src/qt_ros/qt_tutorials/srv/TwoInts.srv")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qt_tutorials/cmake" TYPE FILE FILES "/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/catkin_generated/installspace/qt_tutorials-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/devel/include/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/devel/share/roseus/ros/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/devel/share/common-lisp/ros/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/devel/share/gennodejs/ros/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/nishanth/TurtleStuff/turtle_drive/devel/lib/python2.7/dist-packages/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/devel/lib/python2.7/dist-packages/qt_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/catkin_generated/installspace/qt_tutorials.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qt_tutorials/cmake" TYPE FILE FILES "/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/catkin_generated/installspace/qt_tutorials-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qt_tutorials/cmake" TYPE FILE FILES
    "/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/catkin_generated/installspace/qt_tutorialsConfig.cmake"
    "/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/catkin_generated/installspace/qt_tutorialsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qt_tutorials" TYPE FILE FILES "/home/nishanth/TurtleStuff/turtle_drive/src/qt_ros/qt_tutorials/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nishanth/TurtleStuff/turtle_drive/install/share/qt_tutorials/resources")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nishanth/TurtleStuff/turtle_drive/install/share/qt_tutorials" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/src/qt_ros/qt_tutorials/resources")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nishanth/TurtleStuff/turtle_drive/install/share/qt_tutorials/ui")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nishanth/TurtleStuff/turtle_drive/install/share/qt_tutorials" TYPE DIRECTORY FILES "/home/nishanth/TurtleStuff/turtle_drive/src/qt_ros/qt_tutorials/ui")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/common/cmake_install.cmake")
  include("/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/qtalker/cmake_install.cmake")
  include("/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/qlistener/cmake_install.cmake")
  include("/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/qadd_server/cmake_install.cmake")
  include("/home/nishanth/TurtleStuff/turtle_drive/build/qt_ros/qt_tutorials/qadd_client/cmake_install.cmake")

endif()

