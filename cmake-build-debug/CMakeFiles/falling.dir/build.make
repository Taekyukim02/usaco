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
include CMakeFiles/falling.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/falling.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/falling.dir/flags.make

CMakeFiles/falling.dir/contests/falling.cpp.o: CMakeFiles/falling.dir/flags.make
CMakeFiles/falling.dir/contests/falling.cpp.o: ../contests/falling.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/falling.dir/contests/falling.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/falling.dir/contests/falling.cpp.o -c /Users/tkkim/usaco/contests/falling.cpp

CMakeFiles/falling.dir/contests/falling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/falling.dir/contests/falling.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/contests/falling.cpp > CMakeFiles/falling.dir/contests/falling.cpp.i

CMakeFiles/falling.dir/contests/falling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/falling.dir/contests/falling.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/contests/falling.cpp -o CMakeFiles/falling.dir/contests/falling.cpp.s

# Object files for target falling
falling_OBJECTS = \
"CMakeFiles/falling.dir/contests/falling.cpp.o"

# External object files for target falling
falling_EXTERNAL_OBJECTS =

falling: CMakeFiles/falling.dir/contests/falling.cpp.o
falling: CMakeFiles/falling.dir/build.make
falling: CMakeFiles/falling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable falling"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/falling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/falling.dir/build: falling

.PHONY : CMakeFiles/falling.dir/build

CMakeFiles/falling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/falling.dir/cmake_clean.cmake
.PHONY : CMakeFiles/falling.dir/clean

CMakeFiles/falling.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/falling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/falling.dir/depend

