# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/aasmc/CLionProjects/PersonalBudget

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PersonalBudget.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PersonalBudget.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PersonalBudget.dir/flags.make

CMakeFiles/PersonalBudget.dir/main.cpp.o: CMakeFiles/PersonalBudget.dir/flags.make
CMakeFiles/PersonalBudget.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PersonalBudget.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PersonalBudget.dir/main.cpp.o -c /Users/aasmc/CLionProjects/PersonalBudget/main.cpp

CMakeFiles/PersonalBudget.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PersonalBudget.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aasmc/CLionProjects/PersonalBudget/main.cpp > CMakeFiles/PersonalBudget.dir/main.cpp.i

CMakeFiles/PersonalBudget.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PersonalBudget.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aasmc/CLionProjects/PersonalBudget/main.cpp -o CMakeFiles/PersonalBudget.dir/main.cpp.s

# Object files for target PersonalBudget
PersonalBudget_OBJECTS = \
"CMakeFiles/PersonalBudget.dir/main.cpp.o"

# External object files for target PersonalBudget
PersonalBudget_EXTERNAL_OBJECTS =

PersonalBudget: CMakeFiles/PersonalBudget.dir/main.cpp.o
PersonalBudget: CMakeFiles/PersonalBudget.dir/build.make
PersonalBudget: CMakeFiles/PersonalBudget.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PersonalBudget"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PersonalBudget.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PersonalBudget.dir/build: PersonalBudget
.PHONY : CMakeFiles/PersonalBudget.dir/build

CMakeFiles/PersonalBudget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PersonalBudget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PersonalBudget.dir/clean

CMakeFiles/PersonalBudget.dir/depend:
	cd /Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aasmc/CLionProjects/PersonalBudget /Users/aasmc/CLionProjects/PersonalBudget /Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug /Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug /Users/aasmc/CLionProjects/PersonalBudget/cmake-build-debug/CMakeFiles/PersonalBudget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PersonalBudget.dir/depend

