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
include CMakeFiles/importantfiles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/importantfiles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/importantfiles.dir/flags.make

CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o: CMakeFiles/importantfiles.dir/flags.make
CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o: ../cf/importantfiles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o -c /Users/tkkim/usaco/cf/importantfiles.cpp

CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/cf/importantfiles.cpp > CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.i

CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/cf/importantfiles.cpp -o CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.s

# Object files for target importantfiles
importantfiles_OBJECTS = \
"CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o"

# External object files for target importantfiles
importantfiles_EXTERNAL_OBJECTS =

importantfiles: CMakeFiles/importantfiles.dir/cf/importantfiles.cpp.o
importantfiles: CMakeFiles/importantfiles.dir/build.make
importantfiles: CMakeFiles/importantfiles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable importantfiles"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/importantfiles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/importantfiles.dir/build: importantfiles

.PHONY : CMakeFiles/importantfiles.dir/build

CMakeFiles/importantfiles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/importantfiles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/importantfiles.dir/clean

CMakeFiles/importantfiles.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/importantfiles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/importantfiles.dir/depend
