# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/mnt/d/workshops/coding workshop/c++ workshop/project 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/workshops/coding workshop/c++ workshop/project 3"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/Matrix.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Matrix.o: src/Matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/src/Matrix.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/src/Matrix.o   -c "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c"

CMakeFiles/main.dir/src/Matrix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/src/Matrix.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c" > CMakeFiles/main.dir/src/Matrix.i

CMakeFiles/main.dir/src/Matrix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/src/Matrix.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c" -o CMakeFiles/main.dir/src/Matrix.s

CMakeFiles/main.dir/src/main.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/src/main.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/src/main.o   -c "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c"

CMakeFiles/main.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/src/main.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c" > CMakeFiles/main.dir/src/main.i

CMakeFiles/main.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/src/main.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c" -o CMakeFiles/main.dir/src/main.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/Matrix.o" \
"CMakeFiles/main.dir/src/main.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/Matrix.o
main: CMakeFiles/main.dir/src/main.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/mnt/d/workshops/coding workshop/c++ workshop/project 3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

