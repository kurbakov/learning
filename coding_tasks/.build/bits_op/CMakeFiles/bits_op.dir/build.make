# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kurbakov/cmake_playground

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kurbakov/cmake_playground/.build

# Include any dependencies generated for this target.
include bits_op/CMakeFiles/bits_op.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bits_op/CMakeFiles/bits_op.dir/compiler_depend.make

# Include the progress variables for this target.
include bits_op/CMakeFiles/bits_op.dir/progress.make

# Include the compile flags for this target's objects.
include bits_op/CMakeFiles/bits_op.dir/flags.make

bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o: bits_op/CMakeFiles/bits_op.dir/flags.make
bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o: ../bits_op/bits_op.cpp
bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o: bits_op/CMakeFiles/bits_op.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurbakov/cmake_playground/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o"
	cd /home/kurbakov/cmake_playground/.build/bits_op && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o -MF CMakeFiles/bits_op.dir/bits_op.cpp.o.d -o CMakeFiles/bits_op.dir/bits_op.cpp.o -c /home/kurbakov/cmake_playground/bits_op/bits_op.cpp

bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bits_op.dir/bits_op.cpp.i"
	cd /home/kurbakov/cmake_playground/.build/bits_op && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurbakov/cmake_playground/bits_op/bits_op.cpp > CMakeFiles/bits_op.dir/bits_op.cpp.i

bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bits_op.dir/bits_op.cpp.s"
	cd /home/kurbakov/cmake_playground/.build/bits_op && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurbakov/cmake_playground/bits_op/bits_op.cpp -o CMakeFiles/bits_op.dir/bits_op.cpp.s

# Object files for target bits_op
bits_op_OBJECTS = \
"CMakeFiles/bits_op.dir/bits_op.cpp.o"

# External object files for target bits_op
bits_op_EXTERNAL_OBJECTS =

bits_op/bits_op: bits_op/CMakeFiles/bits_op.dir/bits_op.cpp.o
bits_op/bits_op: bits_op/CMakeFiles/bits_op.dir/build.make
bits_op/bits_op: bits_op/CMakeFiles/bits_op.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kurbakov/cmake_playground/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bits_op"
	cd /home/kurbakov/cmake_playground/.build/bits_op && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bits_op.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bits_op/CMakeFiles/bits_op.dir/build: bits_op/bits_op
.PHONY : bits_op/CMakeFiles/bits_op.dir/build

bits_op/CMakeFiles/bits_op.dir/clean:
	cd /home/kurbakov/cmake_playground/.build/bits_op && $(CMAKE_COMMAND) -P CMakeFiles/bits_op.dir/cmake_clean.cmake
.PHONY : bits_op/CMakeFiles/bits_op.dir/clean

bits_op/CMakeFiles/bits_op.dir/depend:
	cd /home/kurbakov/cmake_playground/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kurbakov/cmake_playground /home/kurbakov/cmake_playground/bits_op /home/kurbakov/cmake_playground/.build /home/kurbakov/cmake_playground/.build/bits_op /home/kurbakov/cmake_playground/.build/bits_op/CMakeFiles/bits_op.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bits_op/CMakeFiles/bits_op.dir/depend

