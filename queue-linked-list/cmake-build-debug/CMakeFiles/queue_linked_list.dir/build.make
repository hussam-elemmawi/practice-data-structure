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
CMAKE_SOURCE_DIR = /home/hussamelemmawi/practice-data-structure/queue-linked-list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/queue_linked_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/queue_linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue_linked_list.dir/flags.make

CMakeFiles/queue_linked_list.dir/main.c.o: CMakeFiles/queue_linked_list.dir/flags.make
CMakeFiles/queue_linked_list.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/queue_linked_list.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/queue_linked_list.dir/main.c.o   -c /home/hussamelemmawi/practice-data-structure/queue-linked-list/main.c

CMakeFiles/queue_linked_list.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/queue_linked_list.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hussamelemmawi/practice-data-structure/queue-linked-list/main.c > CMakeFiles/queue_linked_list.dir/main.c.i

CMakeFiles/queue_linked_list.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/queue_linked_list.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hussamelemmawi/practice-data-structure/queue-linked-list/main.c -o CMakeFiles/queue_linked_list.dir/main.c.s

CMakeFiles/queue_linked_list.dir/main.c.o.requires:

.PHONY : CMakeFiles/queue_linked_list.dir/main.c.o.requires

CMakeFiles/queue_linked_list.dir/main.c.o.provides: CMakeFiles/queue_linked_list.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/queue_linked_list.dir/build.make CMakeFiles/queue_linked_list.dir/main.c.o.provides.build
.PHONY : CMakeFiles/queue_linked_list.dir/main.c.o.provides

CMakeFiles/queue_linked_list.dir/main.c.o.provides.build: CMakeFiles/queue_linked_list.dir/main.c.o


# Object files for target queue_linked_list
queue_linked_list_OBJECTS = \
"CMakeFiles/queue_linked_list.dir/main.c.o"

# External object files for target queue_linked_list
queue_linked_list_EXTERNAL_OBJECTS =

queue_linked_list: CMakeFiles/queue_linked_list.dir/main.c.o
queue_linked_list: CMakeFiles/queue_linked_list.dir/build.make
queue_linked_list: CMakeFiles/queue_linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable queue_linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queue_linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue_linked_list.dir/build: queue_linked_list

.PHONY : CMakeFiles/queue_linked_list.dir/build

CMakeFiles/queue_linked_list.dir/requires: CMakeFiles/queue_linked_list.dir/main.c.o.requires

.PHONY : CMakeFiles/queue_linked_list.dir/requires

CMakeFiles/queue_linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queue_linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queue_linked_list.dir/clean

CMakeFiles/queue_linked_list.dir/depend:
	cd /home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hussamelemmawi/practice-data-structure/queue-linked-list /home/hussamelemmawi/practice-data-structure/queue-linked-list /home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug /home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug /home/hussamelemmawi/practice-data-structure/queue-linked-list/cmake-build-debug/CMakeFiles/queue_linked_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue_linked_list.dir/depend

