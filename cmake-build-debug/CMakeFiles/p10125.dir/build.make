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
include CMakeFiles/p10125.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p10125.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p10125.dir/flags.make

CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o: CMakeFiles/p10125.dir/flags.make
CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o: ../newLowerBoundProblems/p10125.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o -c /Users/tkkim/usaco/newLowerBoundProblems/p10125.cpp

CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/newLowerBoundProblems/p10125.cpp > CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.i

CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/newLowerBoundProblems/p10125.cpp -o CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.s

# Object files for target p10125
p10125_OBJECTS = \
"CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o"

# External object files for target p10125
p10125_EXTERNAL_OBJECTS =

p10125: CMakeFiles/p10125.dir/newLowerBoundProblems/p10125.cpp.o
p10125: CMakeFiles/p10125.dir/build.make
p10125: CMakeFiles/p10125.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p10125"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p10125.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p10125.dir/build: p10125

.PHONY : CMakeFiles/p10125.dir/build

CMakeFiles/p10125.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p10125.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p10125.dir/clean

CMakeFiles/p10125.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/p10125.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p10125.dir/depend
