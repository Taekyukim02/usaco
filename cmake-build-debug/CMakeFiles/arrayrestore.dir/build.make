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
include CMakeFiles/arrayrestore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arrayrestore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrayrestore.dir/flags.make

CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o: CMakeFiles/arrayrestore.dir/flags.make
CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o: ../cf/arrayrestore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o -c /Users/tkkim/usaco/cf/arrayrestore.cpp

CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkkim/usaco/cf/arrayrestore.cpp > CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.i

CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkkim/usaco/cf/arrayrestore.cpp -o CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.s

# Object files for target arrayrestore
arrayrestore_OBJECTS = \
"CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o"

# External object files for target arrayrestore
arrayrestore_EXTERNAL_OBJECTS =

arrayrestore: CMakeFiles/arrayrestore.dir/cf/arrayrestore.cpp.o
arrayrestore: CMakeFiles/arrayrestore.dir/build.make
arrayrestore: CMakeFiles/arrayrestore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tkkim/usaco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrayrestore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrayrestore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arrayrestore.dir/build: arrayrestore

.PHONY : CMakeFiles/arrayrestore.dir/build

CMakeFiles/arrayrestore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arrayrestore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arrayrestore.dir/clean

CMakeFiles/arrayrestore.dir/depend:
	cd /Users/tkkim/usaco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkkim/usaco /Users/tkkim/usaco /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug /Users/tkkim/usaco/cmake-build-debug/CMakeFiles/arrayrestore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrayrestore.dir/depend
