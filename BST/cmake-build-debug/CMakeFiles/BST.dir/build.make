# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hussamelemmawi/practice-data-structure/BST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST.dir/flags.make

CMakeFiles/BST.dir/main.c.o: CMakeFiles/BST.dir/flags.make
CMakeFiles/BST.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BST.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BST.dir/main.c.o   -c /home/hussamelemmawi/practice-data-structure/BST/main.c

CMakeFiles/BST.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BST.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hussamelemmawi/practice-data-structure/BST/main.c > CMakeFiles/BST.dir/main.c.i

CMakeFiles/BST.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BST.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hussamelemmawi/practice-data-structure/BST/main.c -o CMakeFiles/BST.dir/main.c.s

CMakeFiles/BST.dir/main.c.o.requires:

.PHONY : CMakeFiles/BST.dir/main.c.o.requires

CMakeFiles/BST.dir/main.c.o.provides: CMakeFiles/BST.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/BST.dir/build.make CMakeFiles/BST.dir/main.c.o.provides.build
.PHONY : CMakeFiles/BST.dir/main.c.o.provides

CMakeFiles/BST.dir/main.c.o.provides.build: CMakeFiles/BST.dir/main.c.o


# Object files for target BST
BST_OBJECTS = \
"CMakeFiles/BST.dir/main.c.o"

# External object files for target BST
BST_EXTERNAL_OBJECTS =

BST: CMakeFiles/BST.dir/main.c.o
BST: CMakeFiles/BST.dir/build.make
BST: CMakeFiles/BST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST.dir/build: BST

.PHONY : CMakeFiles/BST.dir/build

CMakeFiles/BST.dir/requires: CMakeFiles/BST.dir/main.c.o.requires

.PHONY : CMakeFiles/BST.dir/requires

CMakeFiles/BST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BST.dir/clean

CMakeFiles/BST.dir/depend:
	cd /home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hussamelemmawi/practice-data-structure/BST /home/hussamelemmawi/practice-data-structure/BST /home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug /home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug /home/hussamelemmawi/practice-data-structure/BST/cmake-build-debug/CMakeFiles/BST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BST.dir/depend

