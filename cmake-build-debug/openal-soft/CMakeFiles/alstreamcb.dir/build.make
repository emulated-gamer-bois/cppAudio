# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/molle/Documents/projects/cppAudio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/molle/Documents/projects/cppAudio/cmake-build-debug

# Include any dependencies generated for this target.
include openal-soft/CMakeFiles/alstreamcb.dir/depend.make

# Include the progress variables for this target.
include openal-soft/CMakeFiles/alstreamcb.dir/progress.make

# Include the compile flags for this target's objects.
include openal-soft/CMakeFiles/alstreamcb.dir/flags.make

openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o: openal-soft/CMakeFiles/alstreamcb.dir/flags.make
openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o: ../openal-soft/examples/alstreamcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/molle/Documents/projects/cppAudio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o"
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o -c /home/molle/Documents/projects/cppAudio/openal-soft/examples/alstreamcb.cpp

openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.i"
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/molle/Documents/projects/cppAudio/openal-soft/examples/alstreamcb.cpp > CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.i

openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.s"
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/molle/Documents/projects/cppAudio/openal-soft/examples/alstreamcb.cpp -o CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.s

# Object files for target alstreamcb
alstreamcb_OBJECTS = \
"CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o"

# External object files for target alstreamcb
alstreamcb_EXTERNAL_OBJECTS =

openal-soft/alstreamcb: openal-soft/CMakeFiles/alstreamcb.dir/examples/alstreamcb.cpp.o
openal-soft/alstreamcb: openal-soft/CMakeFiles/alstreamcb.dir/build.make
openal-soft/alstreamcb: /usr/lib/libsndfile.so
openal-soft/alstreamcb: openal-soft/libex-common.a
openal-soft/alstreamcb: openal-soft/libopenal.so.1.21.1
openal-soft/alstreamcb: openal-soft/CMakeFiles/alstreamcb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/molle/Documents/projects/cppAudio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alstreamcb"
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alstreamcb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openal-soft/CMakeFiles/alstreamcb.dir/build: openal-soft/alstreamcb

.PHONY : openal-soft/CMakeFiles/alstreamcb.dir/build

openal-soft/CMakeFiles/alstreamcb.dir/clean:
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft && $(CMAKE_COMMAND) -P CMakeFiles/alstreamcb.dir/cmake_clean.cmake
.PHONY : openal-soft/CMakeFiles/alstreamcb.dir/clean

openal-soft/CMakeFiles/alstreamcb.dir/depend:
	cd /home/molle/Documents/projects/cppAudio/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/molle/Documents/projects/cppAudio /home/molle/Documents/projects/cppAudio/openal-soft /home/molle/Documents/projects/cppAudio/cmake-build-debug /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft /home/molle/Documents/projects/cppAudio/cmake-build-debug/openal-soft/CMakeFiles/alstreamcb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openal-soft/CMakeFiles/alstreamcb.dir/depend

