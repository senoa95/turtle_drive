# CMake generated Testfile for 
# Source directory: /home/sena/turtle_drive/src/novatel_gps_driver/novatel_gps_driver
# Build directory: /home/sena/turtle_drive/build/novatel_gps_driver
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_novatel_gps_driver_gtest_parser_tests "/home/sena/turtle_drive/build/novatel_gps_driver/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/sena/turtle_drive/build/novatel_gps_driver/test_results/novatel_gps_driver/gtest-parser_tests.xml" "--return-code" "/home/sena/turtle_drive/devel/.private/novatel_gps_driver/lib/novatel_gps_driver/parser_tests --gtest_output=xml:/home/sena/turtle_drive/build/novatel_gps_driver/test_results/novatel_gps_driver/gtest-parser_tests.xml")
add_test(_ctest_novatel_gps_driver_rostest_test_novatel_gps_tests.test "/home/sena/turtle_drive/build/novatel_gps_driver/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/sena/turtle_drive/build/novatel_gps_driver/test_results/novatel_gps_driver/rostest-test_novatel_gps_tests.xml" "--return-code" "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/sena/turtle_drive/src/novatel_gps_driver/novatel_gps_driver --package=novatel_gps_driver --results-filename test_novatel_gps_tests.xml --results-base-dir \"/home/sena/turtle_drive/build/novatel_gps_driver/test_results\" /home/sena/turtle_drive/src/novatel_gps_driver/novatel_gps_driver/test/novatel_gps_tests.test ")
subdirs(gtest)
