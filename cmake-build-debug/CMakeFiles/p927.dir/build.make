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
include CMakeFiles/p927.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p927.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p927.dir/flags.make

CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o: CMakeFiles/p927.dir/flags.make
CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o: ../newLowerBoundProblems/p927.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o -c /Users/tkkim/usaco/newLowerBoundProblems/p927.cpp

CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/newLowerBoundProblems/p927.cpp > CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.i

CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/newLowerBoundProblems/p927.cpp -o CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.s

# Object files for target p927
p927_OBJECTS = \
"CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o"

# External object files for target p927
p927_EXTERNAL_OBJECTS =

p927: CMakeFiles/p927.dir/newLowerBoundProblems/p927.cpp.o
p927: CMakeFiles/p927.dir/build.make
p927: CMakeFiles/p927.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p927"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p927.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p927.dir/build: p927

.PHONY : CMakeFiles/p927.dir/build

CMakeFiles/p927.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p927.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p927.dir/clean

CMakeFiles/p927.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/p927.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p927.dir/depend

