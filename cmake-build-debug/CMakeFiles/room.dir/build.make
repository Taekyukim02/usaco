# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tkkim/usaco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tkkim/usaco/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/room.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/room.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/room.dir/flags.make

CMakeFiles/room.dir/UCF/room.cpp.o: CMakeFiles/room.dir/flags.make
CMakeFiles/room.dir/UCF/room.cpp.o: ../UCF/room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/room.dir/UCF/room.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/room.dir/UCF/room.cpp.o -c /Users/tkkim/usaco/UCF/room.cpp

CMakeFiles/room.dir/UCF/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/room.dir/UCF/room.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/UCF/room.cpp > CMakeFiles/room.dir/UCF/room.cpp.i

CMakeFiles/room.dir/UCF/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/room.dir/UCF/room.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/UCF/room.cpp -o CMakeFiles/room.dir/UCF/room.cpp.s

# Object files for target room
room_OBJECTS = \
"CMakeFiles/room.dir/UCF/room.cpp.o"

# External object files for target room
room_EXTERNAL_OBJECTS =

room: CMakeFiles/room.dir/UCF/room.cpp.o
room: CMakeFiles/room.dir/build.make
room: CMakeFiles/room.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable room"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/room.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/room.dir/build: room

.PHONY : CMakeFiles/room.dir/build

CMakeFiles/room.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/room.dir/cmake_clean.cmake
.PHONY : CMakeFiles/room.dir/clean

CMakeFiles/room.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/room.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/room.dir/depend
