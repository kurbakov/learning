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
include fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/compiler_depend.make

# Include the progress variables for this target.
include fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/progress.make

# Include the compile flags for this target's objects.
include fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/flags.make

fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o: fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/flags.make
fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o: ../fast_and_slow_ptr/leet_code_0202/main.cpp
fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o: fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurbakov/cmake_playground/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o"
	cd /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o -MF CMakeFiles/lc_0202.dir/main.cpp.o.d -o CMakeFiles/lc_0202.dir/main.cpp.o -c /home/kurbakov/cmake_playground/fast_and_slow_ptr/leet_code_0202/main.cpp

fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc_0202.dir/main.cpp.i"
	cd /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurbakov/cmake_playground/fast_and_slow_ptr/leet_code_0202/main.cpp > CMakeFiles/lc_0202.dir/main.cpp.i

fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc_0202.dir/main.cpp.s"
	cd /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurbakov/cmake_playground/fast_and_slow_ptr/leet_code_0202/main.cpp -o CMakeFiles/lc_0202.dir/main.cpp.s

# Object files for target lc_0202
lc_0202_OBJECTS = \
"CMakeFiles/lc_0202.dir/main.cpp.o"

# External object files for target lc_0202
lc_0202_EXTERNAL_OBJECTS =

fast_and_slow_ptr/leet_code_0202/lc_0202: fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/main.cpp.o
fast_and_slow_ptr/leet_code_0202/lc_0202: fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/build.make
fast_and_slow_ptr/leet_code_0202/lc_0202: fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kurbakov/cmake_playground/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lc_0202"
	cd /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc_0202.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/build: fast_and_slow_ptr/leet_code_0202/lc_0202
.PHONY : fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/build

fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/clean:
	cd /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 && $(CMAKE_COMMAND) -P CMakeFiles/lc_0202.dir/cmake_clean.cmake
.PHONY : fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/clean

fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/depend:
	cd /home/kurbakov/cmake_playground/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kurbakov/cmake_playground /home/kurbakov/cmake_playground/fast_and_slow_ptr/leet_code_0202 /home/kurbakov/cmake_playground/.build /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202 /home/kurbakov/cmake_playground/.build/fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fast_and_slow_ptr/leet_code_0202/CMakeFiles/lc_0202.dir/depend

