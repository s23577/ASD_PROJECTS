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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SORTING_PROGRAM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SORTING_PROGRAM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SORTING_PROGRAM.dir/flags.make

CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o: CMakeFiles/SORTING_PROGRAM.dir/flags.make
CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o -c /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/main.cpp

CMakeFiles/SORTING_PROGRAM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SORTING_PROGRAM.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/main.cpp > CMakeFiles/SORTING_PROGRAM.dir/main.cpp.i

CMakeFiles/SORTING_PROGRAM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SORTING_PROGRAM.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/main.cpp -o CMakeFiles/SORTING_PROGRAM.dir/main.cpp.s

# Object files for target SORTING_PROGRAM
SORTING_PROGRAM_OBJECTS = \
"CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o"

# External object files for target SORTING_PROGRAM
SORTING_PROGRAM_EXTERNAL_OBJECTS =

SORTING_PROGRAM: CMakeFiles/SORTING_PROGRAM.dir/main.cpp.o
SORTING_PROGRAM: CMakeFiles/SORTING_PROGRAM.dir/build.make
SORTING_PROGRAM: CMakeFiles/SORTING_PROGRAM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SORTING_PROGRAM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SORTING_PROGRAM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SORTING_PROGRAM.dir/build: SORTING_PROGRAM

.PHONY : CMakeFiles/SORTING_PROGRAM.dir/build

CMakeFiles/SORTING_PROGRAM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SORTING_PROGRAM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SORTING_PROGRAM.dir/clean

CMakeFiles/SORTING_PROGRAM.dir/depend:
	cd /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug /Users/ala/CLionProjects/PROJECT_1/SORTING_PROGRAM/cmake-build-debug/CMakeFiles/SORTING_PROGRAM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SORTING_PROGRAM.dir/depend
