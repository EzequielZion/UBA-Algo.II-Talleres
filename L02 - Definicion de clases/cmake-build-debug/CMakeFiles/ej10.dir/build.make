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
CMAKE_SOURCE_DIR = /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej10.dir/flags.make

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o: CMakeFiles/ej10.dir/flags.make
CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o -c /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/tests/test_recordatorios.cpp

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/tests/test_recordatorios.cpp > CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/tests/test_recordatorios.cpp -o CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s

# Object files for target ej10
ej10_OBJECTS = \
"CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o"

# External object files for target ej10
ej10_EXTERNAL_OBJECTS =

ej10: CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o
ej10: CMakeFiles/ej10.dir/build.make
ej10: libgtest.a
ej10: libgtest_main.a
ej10: CMakeFiles/ej10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej10.dir/build: ej10

.PHONY : CMakeFiles/ej10.dir/build

CMakeFiles/ej10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej10.dir/clean

CMakeFiles/ej10.dir/depend:
	cd /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02 /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02 /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug /home/ezequiel/Documents/Carrera/Algo_II/Labo/L02/cmake-build-debug/CMakeFiles/ej10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej10.dir/depend

