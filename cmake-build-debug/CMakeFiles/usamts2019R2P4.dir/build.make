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
include CMakeFiles/usamts2019R2P4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/usamts2019R2P4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/usamts2019R2P4.dir/flags.make

CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o: CMakeFiles/usamts2019R2P4.dir/flags.make
CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o: ../astar/turing/UCF/usamts2019R2P4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o -c /Users/tkkim/usaco/astar/turing/UCF/usamts2019R2P4.cpp

CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/astar/turing/UCF/usamts2019R2P4.cpp > CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.i

CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/astar/turing/UCF/usamts2019R2P4.cpp -o CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.s

# Object files for target usamts2019R2P4
usamts2019R2P4_OBJECTS = \
"CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o"

# External object files for target usamts2019R2P4
usamts2019R2P4_EXTERNAL_OBJECTS =

usamts2019R2P4: CMakeFiles/usamts2019R2P4.dir/astar/turing/UCF/usamts2019R2P4.cpp.o
usamts2019R2P4: CMakeFiles/usamts2019R2P4.dir/build.make
usamts2019R2P4: CMakeFiles/usamts2019R2P4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable usamts2019R2P4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usamts2019R2P4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/usamts2019R2P4.dir/build: usamts2019R2P4

.PHONY : CMakeFiles/usamts2019R2P4.dir/build

CMakeFiles/usamts2019R2P4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/usamts2019R2P4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/usamts2019R2P4.dir/clean

CMakeFiles/usamts2019R2P4.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/usamts2019R2P4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/usamts2019R2P4.dir/depend

