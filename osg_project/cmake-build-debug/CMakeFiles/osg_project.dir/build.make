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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/geo/Projects/C++/osg_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/geo/Projects/C++/osg_project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/osg_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/osg_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/osg_project.dir/flags.make

CMakeFiles/osg_project.dir/main.cpp.o: CMakeFiles/osg_project.dir/flags.make
CMakeFiles/osg_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/geo/Projects/C++/osg_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/osg_project.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/osg_project.dir/main.cpp.o -c /home/geo/Projects/C++/osg_project/main.cpp

CMakeFiles/osg_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osg_project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/geo/Projects/C++/osg_project/main.cpp > CMakeFiles/osg_project.dir/main.cpp.i

CMakeFiles/osg_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osg_project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/geo/Projects/C++/osg_project/main.cpp -o CMakeFiles/osg_project.dir/main.cpp.s

# Object files for target osg_project
osg_project_OBJECTS = \
"CMakeFiles/osg_project.dir/main.cpp.o"

# External object files for target osg_project
osg_project_EXTERNAL_OBJECTS =

osg_project: CMakeFiles/osg_project.dir/main.cpp.o
osg_project: CMakeFiles/osg_project.dir/build.make
osg_project: CMakeFiles/osg_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/geo/Projects/C++/osg_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable osg_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/osg_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/osg_project.dir/build: osg_project

.PHONY : CMakeFiles/osg_project.dir/build

CMakeFiles/osg_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/osg_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/osg_project.dir/clean

CMakeFiles/osg_project.dir/depend:
	cd /home/geo/Projects/C++/osg_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/geo/Projects/C++/osg_project /home/geo/Projects/C++/osg_project /home/geo/Projects/C++/osg_project/cmake-build-debug /home/geo/Projects/C++/osg_project/cmake-build-debug /home/geo/Projects/C++/osg_project/cmake-build-debug/CMakeFiles/osg_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/osg_project.dir/depend

