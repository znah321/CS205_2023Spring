# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/goweild/Labs/Lab06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/goweild/Labs/Lab06

# Include any dependencies generated for this target.
include CMakeFiles/exp1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exp1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exp1.dir/flags.make

CMakeFiles/exp1.dir/exp1.cpp.o: CMakeFiles/exp1.dir/flags.make
CMakeFiles/exp1.dir/exp1.cpp.o: exp1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/goweild/Labs/Lab06/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exp1.dir/exp1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exp1.dir/exp1.cpp.o -c /home/goweild/Labs/Lab06/exp1.cpp

CMakeFiles/exp1.dir/exp1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exp1.dir/exp1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goweild/Labs/Lab06/exp1.cpp > CMakeFiles/exp1.dir/exp1.cpp.i

CMakeFiles/exp1.dir/exp1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exp1.dir/exp1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goweild/Labs/Lab06/exp1.cpp -o CMakeFiles/exp1.dir/exp1.cpp.s

CMakeFiles/exp1.dir/exp1.cpp.o.requires:

.PHONY : CMakeFiles/exp1.dir/exp1.cpp.o.requires

CMakeFiles/exp1.dir/exp1.cpp.o.provides: CMakeFiles/exp1.dir/exp1.cpp.o.requires
	$(MAKE) -f CMakeFiles/exp1.dir/build.make CMakeFiles/exp1.dir/exp1.cpp.o.provides.build
.PHONY : CMakeFiles/exp1.dir/exp1.cpp.o.provides

CMakeFiles/exp1.dir/exp1.cpp.o.provides.build: CMakeFiles/exp1.dir/exp1.cpp.o


# Object files for target exp1
exp1_OBJECTS = \
"CMakeFiles/exp1.dir/exp1.cpp.o"

# External object files for target exp1
exp1_EXTERNAL_OBJECTS =

exp1: CMakeFiles/exp1.dir/exp1.cpp.o
exp1: CMakeFiles/exp1.dir/build.make
exp1: CMakeFiles/exp1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/goweild/Labs/Lab06/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exp1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exp1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exp1.dir/build: exp1

.PHONY : CMakeFiles/exp1.dir/build

CMakeFiles/exp1.dir/requires: CMakeFiles/exp1.dir/exp1.cpp.o.requires

.PHONY : CMakeFiles/exp1.dir/requires

CMakeFiles/exp1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exp1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exp1.dir/clean

CMakeFiles/exp1.dir/depend:
	cd /home/goweild/Labs/Lab06 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/goweild/Labs/Lab06 /home/goweild/Labs/Lab06 /home/goweild/Labs/Lab06 /home/goweild/Labs/Lab06 /home/goweild/Labs/Lab06/CMakeFiles/exp1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exp1.dir/depend
