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
CMAKE_SOURCE_DIR = /home/UDC/107226/linux/FIC_BOX/PROII/P0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote

# Include any dependencies generated for this target.
include CMakeFiles/Rational_struct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rational_struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rational_struct.dir/flags.make

CMakeFiles/Rational_struct.dir/main.c.o: CMakeFiles/Rational_struct.dir/flags.make
CMakeFiles/Rational_struct.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Rational_struct.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Rational_struct.dir/main.c.o   -c /home/UDC/107226/linux/FIC_BOX/PROII/P0/main.c

CMakeFiles/Rational_struct.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rational_struct.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/UDC/107226/linux/FIC_BOX/PROII/P0/main.c > CMakeFiles/Rational_struct.dir/main.c.i

CMakeFiles/Rational_struct.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rational_struct.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/UDC/107226/linux/FIC_BOX/PROII/P0/main.c -o CMakeFiles/Rational_struct.dir/main.c.s

CMakeFiles/Rational_struct.dir/rational_struct.c.o: CMakeFiles/Rational_struct.dir/flags.make
CMakeFiles/Rational_struct.dir/rational_struct.c.o: ../rational_struct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Rational_struct.dir/rational_struct.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Rational_struct.dir/rational_struct.c.o   -c /home/UDC/107226/linux/FIC_BOX/PROII/P0/rational_struct.c

CMakeFiles/Rational_struct.dir/rational_struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rational_struct.dir/rational_struct.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/UDC/107226/linux/FIC_BOX/PROII/P0/rational_struct.c > CMakeFiles/Rational_struct.dir/rational_struct.c.i

CMakeFiles/Rational_struct.dir/rational_struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rational_struct.dir/rational_struct.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/UDC/107226/linux/FIC_BOX/PROII/P0/rational_struct.c -o CMakeFiles/Rational_struct.dir/rational_struct.c.s

# Object files for target Rational_struct
Rational_struct_OBJECTS = \
"CMakeFiles/Rational_struct.dir/main.c.o" \
"CMakeFiles/Rational_struct.dir/rational_struct.c.o"

# External object files for target Rational_struct
Rational_struct_EXTERNAL_OBJECTS =

Rational_struct: CMakeFiles/Rational_struct.dir/main.c.o
Rational_struct: CMakeFiles/Rational_struct.dir/rational_struct.c.o
Rational_struct: CMakeFiles/Rational_struct.dir/build.make
Rational_struct: CMakeFiles/Rational_struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Rational_struct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rational_struct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rational_struct.dir/build: Rational_struct

.PHONY : CMakeFiles/Rational_struct.dir/build

CMakeFiles/Rational_struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rational_struct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rational_struct.dir/clean

CMakeFiles/Rational_struct.dir/depend:
	cd /home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/UDC/107226/linux/FIC_BOX/PROII/P0 /home/UDC/107226/linux/FIC_BOX/PROII/P0 /home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote /home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote /home/UDC/107226/linux/FIC_BOX/PROII/P0/cmake-build-debug-remote/CMakeFiles/Rational_struct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rational_struct.dir/depend

