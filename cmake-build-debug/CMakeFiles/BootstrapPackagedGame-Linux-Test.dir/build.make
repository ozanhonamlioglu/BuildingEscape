# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/router/Desktop/games/01_BuildingEscape/BuildingEscape

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/router/Desktop/games/01_BuildingEscape/BuildingEscape/cmake-build-debug

# Utility rule file for BootstrapPackagedGame-Linux-Test.

# Include the progress variables for this target.
include CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/progress.make

CMakeFiles/BootstrapPackagedGame-Linux-Test:
	cd /home/router/UnrealEngine && bash /home/router/UnrealEngine/Engine/Build/BatchFiles/Linux/Build.sh BootstrapPackagedGame Linux Test -project=/home/router/Desktop/games/01_BuildingEscape/BuildingEscape/BuildingEscape.uproject -game -progress -buildscw

BootstrapPackagedGame-Linux-Test: CMakeFiles/BootstrapPackagedGame-Linux-Test
BootstrapPackagedGame-Linux-Test: CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/build.make

.PHONY : BootstrapPackagedGame-Linux-Test

# Rule to build all files generated by this target.
CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/build: BootstrapPackagedGame-Linux-Test

.PHONY : CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/build

CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/clean

CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/depend:
	cd /home/router/Desktop/games/01_BuildingEscape/BuildingEscape/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/router/Desktop/games/01_BuildingEscape/BuildingEscape /home/router/Desktop/games/01_BuildingEscape/BuildingEscape /home/router/Desktop/games/01_BuildingEscape/BuildingEscape/cmake-build-debug /home/router/Desktop/games/01_BuildingEscape/BuildingEscape/cmake-build-debug /home/router/Desktop/games/01_BuildingEscape/BuildingEscape/cmake-build-debug/CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BootstrapPackagedGame-Linux-Test.dir/depend
