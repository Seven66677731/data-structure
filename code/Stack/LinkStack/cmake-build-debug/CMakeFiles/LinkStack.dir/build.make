# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Software\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Software\CLion\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\datastruct\data-structure\code\Stack\LinkStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkStack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LinkStack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkStack.dir/flags.make

CMakeFiles/LinkStack.dir/main.cpp.obj: CMakeFiles/LinkStack.dir/flags.make
CMakeFiles/LinkStack.dir/main.cpp.obj: F:/datastruct/data-structure/code/Stack/LinkStack/main.cpp
CMakeFiles/LinkStack.dir/main.cpp.obj: CMakeFiles/LinkStack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkStack.dir/main.cpp.obj"
	D:\Software\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LinkStack.dir/main.cpp.obj -MF CMakeFiles\LinkStack.dir\main.cpp.obj.d -o CMakeFiles\LinkStack.dir\main.cpp.obj -c F:\datastruct\data-structure\code\Stack\LinkStack\main.cpp

CMakeFiles/LinkStack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkStack.dir/main.cpp.i"
	D:\Software\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\datastruct\data-structure\code\Stack\LinkStack\main.cpp > CMakeFiles\LinkStack.dir\main.cpp.i

CMakeFiles/LinkStack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkStack.dir/main.cpp.s"
	D:\Software\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\datastruct\data-structure\code\Stack\LinkStack\main.cpp -o CMakeFiles\LinkStack.dir\main.cpp.s

# Object files for target LinkStack
LinkStack_OBJECTS = \
"CMakeFiles/LinkStack.dir/main.cpp.obj"

# External object files for target LinkStack
LinkStack_EXTERNAL_OBJECTS =

LinkStack.exe: CMakeFiles/LinkStack.dir/main.cpp.obj
LinkStack.exe: CMakeFiles/LinkStack.dir/build.make
LinkStack.exe: CMakeFiles/LinkStack.dir/linklibs.rsp
LinkStack.exe: CMakeFiles/LinkStack.dir/objects1.rsp
LinkStack.exe: CMakeFiles/LinkStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkStack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LinkStack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkStack.dir/build: LinkStack.exe
.PHONY : CMakeFiles/LinkStack.dir/build

CMakeFiles/LinkStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LinkStack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LinkStack.dir/clean

CMakeFiles/LinkStack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\datastruct\data-structure\code\Stack\LinkStack F:\datastruct\data-structure\code\Stack\LinkStack F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug F:\datastruct\data-structure\code\Stack\LinkStack\cmake-build-debug\CMakeFiles\LinkStack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkStack.dir/depend
