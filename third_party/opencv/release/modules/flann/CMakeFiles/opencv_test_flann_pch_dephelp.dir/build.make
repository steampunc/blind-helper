# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/finn/code/my_projects/blind/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/finn/code/my_projects/blind/opencv/release

# Include any dependencies generated for this target.
include modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/depend.make

# Include the progress variables for this target.
include modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/progress.make

# Include the compile flags for this target's objects.
include modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/flags.make

modules/flann/opencv_test_flann_pch_dephelp.cxx: ../modules/flann/test/test_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/finn/code/my_projects/blind/opencv/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating opencv_test_flann_pch_dephelp.cxx"
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo \#include\ \"/home/finn/code/my_projects/blind/opencv/modules/flann/test/test_precomp.hpp\" > /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo int\ testfunction\(\)\; >> /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo int\ testfunction\(\) >> /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo { >> /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo \ \ \ \ \return\ 0\; >> /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/cmake -E echo } >> /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/flags.make
modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o: modules/flann/opencv_test_flann_pch_dephelp.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/finn/code/my_projects/blind/opencv/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o"
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o -c /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.i"
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx > CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.i

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.s"
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/finn/code/my_projects/blind/opencv/release/modules/flann/opencv_test_flann_pch_dephelp.cxx -o CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.s

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.requires:
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.requires

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.provides: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.requires
	$(MAKE) -f modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/build.make modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.provides.build
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.provides

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.provides.build: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o

# Object files for target opencv_test_flann_pch_dephelp
opencv_test_flann_pch_dephelp_OBJECTS = \
"CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o"

# External object files for target opencv_test_flann_pch_dephelp
opencv_test_flann_pch_dephelp_EXTERNAL_OBJECTS =

lib/libopencv_test_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o
lib/libopencv_test_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/build.make
lib/libopencv_test_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libopencv_test_flann_pch_dephelp.a"
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_flann_pch_dephelp.dir/cmake_clean_target.cmake
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test_flann_pch_dephelp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/build: lib/libopencv_test_flann_pch_dephelp.a
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/build

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/requires: modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/opencv_test_flann_pch_dephelp.cxx.o.requires
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/requires

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/clean:
	cd /home/finn/code/my_projects/blind/opencv/release/modules/flann && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_flann_pch_dephelp.dir/cmake_clean.cmake
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/clean

modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/depend: modules/flann/opencv_test_flann_pch_dephelp.cxx
	cd /home/finn/code/my_projects/blind/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/finn/code/my_projects/blind/opencv /home/finn/code/my_projects/blind/opencv/modules/flann /home/finn/code/my_projects/blind/opencv/release /home/finn/code/my_projects/blind/opencv/release/modules/flann /home/finn/code/my_projects/blind/opencv/release/modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/flann/CMakeFiles/opencv_test_flann_pch_dephelp.dir/depend

