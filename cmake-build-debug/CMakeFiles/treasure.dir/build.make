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
include CMakeFiles/treasure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/treasure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/treasure.dir/flags.make

CMakeFiles/treasure.dir/cf/treasure.cpp.o: CMakeFiles/treasure.dir/flags.make
CMakeFiles/treasure.dir/cf/treasure.cpp.o: ../cf/treasure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/treasure.dir/cf/treasure.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/treasure.dir/cf/treasure.cpp.o -c /Users/tkkim/usaco/cf/treasure.cpp

CMakeFiles/treasure.dir/cf/treasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/treasure.dir/cf/treasure.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/cf/treasure.cpp > CMakeFiles/treasure.dir/cf/treasure.cpp.i

CMakeFiles/treasure.dir/cf/treasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/treasure.dir/cf/treasure.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/cf/treasure.cpp -o CMakeFiles/treasure.dir/cf/treasure.cpp.s

# Object files for target treasure
treasure_OBJECTS = \
"CMakeFiles/treasure.dir/cf/treasure.cpp.o"

# External object files for target treasure
treasure_EXTERNAL_OBJECTS =

treasure: CMakeFiles/treasure.dir/cf/treasure.cpp.o
treasure: CMakeFiles/treasure.dir/build.make
treasure: CMakeFiles/treasure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable treasure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/treasure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/treasure.dir/build: treasure

.PHONY : CMakeFiles/treasure.dir/build

CMakeFiles/treasure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/treasure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/treasure.dir/clean

CMakeFiles/treasure.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/treasure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/treasure.dir/depend
