# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Theater-Seat-Reservation-Simulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Theater-Seat-Reservation-Simulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Theater-Seat-Reservation-Simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Theater-Seat-Reservation-Simulator.dir/flags.make

CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o: CMakeFiles/Theater-Seat-Reservation-Simulator.dir/flags.make
CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o: /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/main.c
CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o: CMakeFiles/Theater-Seat-Reservation-Simulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o -MF CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o.d -o CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o -c /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/main.c

CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/main.c > CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.i

CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/main.c -o CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.s

# Object files for target Theater-Seat-Reservation-Simulator
Theater__Seat__Reservation__Simulator_OBJECTS = \
"CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o"

# External object files for target Theater-Seat-Reservation-Simulator
Theater__Seat__Reservation__Simulator_EXTERNAL_OBJECTS =

Theater-Seat-Reservation-Simulator: CMakeFiles/Theater-Seat-Reservation-Simulator.dir/main.c.o
Theater-Seat-Reservation-Simulator: CMakeFiles/Theater-Seat-Reservation-Simulator.dir/build.make
Theater-Seat-Reservation-Simulator: CMakeFiles/Theater-Seat-Reservation-Simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Theater-Seat-Reservation-Simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Theater-Seat-Reservation-Simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Theater-Seat-Reservation-Simulator.dir/build: Theater-Seat-Reservation-Simulator
.PHONY : CMakeFiles/Theater-Seat-Reservation-Simulator.dir/build

CMakeFiles/Theater-Seat-Reservation-Simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Theater-Seat-Reservation-Simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Theater-Seat-Reservation-Simulator.dir/clean

CMakeFiles/Theater-Seat-Reservation-Simulator.dir/depend:
	cd /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug /Users/smnls/CLionProjects/Theater-Seat-Reservation-Simulator/cmake-build-debug/CMakeFiles/Theater-Seat-Reservation-Simulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Theater-Seat-Reservation-Simulator.dir/depend

