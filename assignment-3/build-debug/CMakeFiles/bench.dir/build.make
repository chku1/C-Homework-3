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
CMAKE_SOURCE_DIR = /home/chku/Desktop/C/assignment-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chku/Desktop/C/assignment-3/build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bench.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bench.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bench.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bench.dir/flags.make

CMakeFiles/bench.dir/benchmark_example.cpp.o: CMakeFiles/bench.dir/flags.make
CMakeFiles/bench.dir/benchmark_example.cpp.o: ../benchmark_example.cpp
CMakeFiles/bench.dir/benchmark_example.cpp.o: CMakeFiles/bench.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chku/Desktop/C/assignment-3/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bench.dir/benchmark_example.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bench.dir/benchmark_example.cpp.o -MF CMakeFiles/bench.dir/benchmark_example.cpp.o.d -o CMakeFiles/bench.dir/benchmark_example.cpp.o -c /home/chku/Desktop/C/assignment-3/benchmark_example.cpp

CMakeFiles/bench.dir/benchmark_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench.dir/benchmark_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chku/Desktop/C/assignment-3/benchmark_example.cpp > CMakeFiles/bench.dir/benchmark_example.cpp.i

CMakeFiles/bench.dir/benchmark_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench.dir/benchmark_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chku/Desktop/C/assignment-3/benchmark_example.cpp -o CMakeFiles/bench.dir/benchmark_example.cpp.s

# Object files for target bench
bench_OBJECTS = \
"CMakeFiles/bench.dir/benchmark_example.cpp.o"

# External object files for target bench
bench_EXTERNAL_OBJECTS =

bench: CMakeFiles/bench.dir/benchmark_example.cpp.o
bench: CMakeFiles/bench.dir/build.make
bench: CMakeFiles/bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chku/Desktop/C/assignment-3/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bench"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bench.dir/build: bench
.PHONY : CMakeFiles/bench.dir/build

CMakeFiles/bench.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bench.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bench.dir/clean

CMakeFiles/bench.dir/depend:
	cd /home/chku/Desktop/C/assignment-3/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chku/Desktop/C/assignment-3 /home/chku/Desktop/C/assignment-3 /home/chku/Desktop/C/assignment-3/build-debug /home/chku/Desktop/C/assignment-3/build-debug /home/chku/Desktop/C/assignment-3/build-debug/CMakeFiles/bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bench.dir/depend

