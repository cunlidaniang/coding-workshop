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
include CMakeFiles/Matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matrix.dir/flags.make

CMakeFiles/Matrix.dir/src/Matrix.o: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/src/Matrix.o: src/Matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Matrix.dir/src/Matrix.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Matrix.dir/src/Matrix.o   -c "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c"

CMakeFiles/Matrix.dir/src/Matrix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Matrix.dir/src/Matrix.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c" > CMakeFiles/Matrix.dir/src/Matrix.i

CMakeFiles/Matrix.dir/src/Matrix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Matrix.dir/src/Matrix.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/Matrix.c" -o CMakeFiles/Matrix.dir/src/Matrix.s

CMakeFiles/Matrix.dir/src/main.o: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/src/main.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Matrix.dir/src/main.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Matrix.dir/src/main.o   -c "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c"

CMakeFiles/Matrix.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Matrix.dir/src/main.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c" > CMakeFiles/Matrix.dir/src/main.i

CMakeFiles/Matrix.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Matrix.dir/src/main.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/workshops/coding workshop/c++ workshop/project 3/src/main.c" -o CMakeFiles/Matrix.dir/src/main.s

# Object files for target Matrix
Matrix_OBJECTS = \
"CMakeFiles/Matrix.dir/src/Matrix.o" \
"CMakeFiles/Matrix.dir/src/main.o"

# External object files for target Matrix
Matrix_EXTERNAL_OBJECTS =

Matrix: CMakeFiles/Matrix.dir/src/Matrix.o
Matrix: CMakeFiles/Matrix.dir/src/main.o
Matrix: CMakeFiles/Matrix.dir/build.make
Matrix: CMakeFiles/Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matrix.dir/build: Matrix

.PHONY : CMakeFiles/Matrix.dir/build

CMakeFiles/Matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Matrix.dir/clean

CMakeFiles/Matrix.dir/depend:
	cd "/mnt/d/workshops/coding workshop/c++ workshop/project 3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3" "/mnt/d/workshops/coding workshop/c++ workshop/project 3/CMakeFiles/Matrix.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Matrix.dir/depend
