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
include CMakeFiles/asyaarray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asyaarray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asyaarray.dir/flags.make

CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o: CMakeFiles/asyaarray.dir/flags.make
CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o: ../cf/asyaarray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o -c /Users/tkkim/usaco/cf/asyaarray.cpp

CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/cf/asyaarray.cpp > CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.i

CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/cf/asyaarray.cpp -o CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.s

# Object files for target asyaarray
asyaarray_OBJECTS = \
"CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o"

# External object files for target asyaarray
asyaarray_EXTERNAL_OBJECTS =

asyaarray: CMakeFiles/asyaarray.dir/cf/asyaarray.cpp.o
asyaarray: CMakeFiles/asyaarray.dir/build.make
asyaarray: CMakeFiles/asyaarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable asyaarray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asyaarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asyaarray.dir/build: asyaarray

.PHONY : CMakeFiles/asyaarray.dir/build

CMakeFiles/asyaarray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asyaarray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asyaarray.dir/clean

CMakeFiles/asyaarray.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/asyaarray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asyaarray.dir/depend

