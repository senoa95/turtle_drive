# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver

# Include any dependencies generated for this target.
include mbs/CMakeFiles/roboteq_driver_script.dir/depend.make

# Include the progress variables for this target.
include mbs/CMakeFiles/roboteq_driver_script.dir/progress.make

# Include the compile flags for this target's objects.
include mbs/CMakeFiles/roboteq_driver_script.dir/flags.make

mbs/genc_script_hex.cpp: /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver/mbs/genc
mbs/genc_script_hex.cpp: /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver/mbs/script.mbs
mbs/genc_script_hex.cpp: /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver/mbs/script.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating genc_script_hex.cpp"
	cd /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver/mbs && ./genc script_lines script.hex > /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs/genc_script_hex.cpp

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o: mbs/CMakeFiles/roboteq_driver_script.dir/flags.make
mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o: mbs/genc_script_hex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o"
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o -c /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs/genc_script_hex.cpp

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.i"
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs/genc_script_hex.cpp > CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.i

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.s"
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs/genc_script_hex.cpp -o CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.s

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.requires:

.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.requires

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.provides: mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.requires
	$(MAKE) -f mbs/CMakeFiles/roboteq_driver_script.dir/build.make mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.provides.build
.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.provides

mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.provides.build: mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o


# Object files for target roboteq_driver_script
roboteq_driver_script_OBJECTS = \
"CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o"

# External object files for target roboteq_driver_script
roboteq_driver_script_EXTERNAL_OBJECTS =

/home/nishanth/TurtleStuff/turtle_drive/devel/.private/roboteq_driver/lib/libroboteq_driver_script.a: mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o
/home/nishanth/TurtleStuff/turtle_drive/devel/.private/roboteq_driver/lib/libroboteq_driver_script.a: mbs/CMakeFiles/roboteq_driver_script.dir/build.make
/home/nishanth/TurtleStuff/turtle_drive/devel/.private/roboteq_driver/lib/libroboteq_driver_script.a: mbs/CMakeFiles/roboteq_driver_script.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library /home/nishanth/TurtleStuff/turtle_drive/devel/.private/roboteq_driver/lib/libroboteq_driver_script.a"
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && $(CMAKE_COMMAND) -P CMakeFiles/roboteq_driver_script.dir/cmake_clean_target.cmake
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roboteq_driver_script.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mbs/CMakeFiles/roboteq_driver_script.dir/build: /home/nishanth/TurtleStuff/turtle_drive/devel/.private/roboteq_driver/lib/libroboteq_driver_script.a

.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/build

mbs/CMakeFiles/roboteq_driver_script.dir/requires: mbs/CMakeFiles/roboteq_driver_script.dir/genc_script_hex.cpp.o.requires

.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/requires

mbs/CMakeFiles/roboteq_driver_script.dir/clean:
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs && $(CMAKE_COMMAND) -P CMakeFiles/roboteq_driver_script.dir/cmake_clean.cmake
.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/clean

mbs/CMakeFiles/roboteq_driver_script.dir/depend: mbs/genc_script_hex.cpp
	cd /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver /home/nishanth/TurtleStuff/turtle_drive/src/roboteq/roboteq_driver/mbs /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs /home/nishanth/TurtleStuff/turtle_drive/build/roboteq_driver/mbs/CMakeFiles/roboteq_driver_script.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mbs/CMakeFiles/roboteq_driver_script.dir/depend

