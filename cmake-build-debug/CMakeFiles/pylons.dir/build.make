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
include CMakeFiles/pylons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pylons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pylons.dir/flags.make

CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o: CMakeFiles/pylons.dir/flags.make
CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o: ../codejam2019/round1a/pylons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o -c /Users/tkkim/usaco/codejam2019/round1a/pylons.cpp

CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/codejam2019/round1a/pylons.cpp > CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.i

CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/codejam2019/round1a/pylons.cpp -o CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.s

# Object files for target pylons
pylons_OBJECTS = \
"CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o"

# External object files for target pylons
pylons_EXTERNAL_OBJECTS =

pylons: CMakeFiles/pylons.dir/codejam2019/round1a/pylons.cpp.o
pylons: CMakeFiles/pylons.dir/build.make
pylons: CMakeFiles/pylons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pylons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pylons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pylons.dir/build: pylons

.PHONY : CMakeFiles/pylons.dir/build

CMakeFiles/pylons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pylons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pylons.dir/clean

CMakeFiles/pylons.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/pylons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pylons.dir/depend

