# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest.dir/flags.make

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o: ../tests/gtest-1.8.1/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o -c /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/tests/gtest-1.8.1/gtest-all.cc

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/tests/gtest-1.8.1/gtest-all.cc > CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.i

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/tests/gtest-1.8.1/gtest-all.cc -o CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

libgtest.a: CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.o
libgtest.a: CMakeFiles/gtest.dir/build.make
libgtest.a: CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest.dir/build: libgtest.a

.PHONY : CMakeFiles/gtest.dir/build

CMakeFiles/gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest.dir/clean

CMakeFiles/gtest.dir/depend:
	cd /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04 /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04 /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug /home/ezequiel/Documents/Carrera/Algo_II/Labo/L04/cmake-build-debug/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest.dir/depend

