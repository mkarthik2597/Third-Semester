# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.5

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\SCBuilder\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\SCBuilder\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Karthik\Desktop\32bitsiso

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Karthik\Desktop\32bitsiso\.siso_build

# Include any dependencies generated for this target.
include CMakeFiles/siso.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/siso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/siso.dir/flags.make

CMakeFiles/siso.dir/main.cpp.obj: CMakeFiles/siso.dir/flags.make
CMakeFiles/siso.dir/main.cpp.obj: CMakeFiles/siso.dir/includes_CXX.rsp
CMakeFiles/siso.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Karthik\Desktop\32bitsiso\.siso_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/siso.dir/main.cpp.obj"
	C:\SCBuilder\mingw32\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\siso.dir\main.cpp.obj -c C:\Users\Karthik\Desktop\32bitsiso\main.cpp

CMakeFiles/siso.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/siso.dir/main.cpp.i"
	C:\SCBuilder\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Karthik\Desktop\32bitsiso\main.cpp > CMakeFiles\siso.dir\main.cpp.i

CMakeFiles/siso.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/siso.dir/main.cpp.s"
	C:\SCBuilder\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Karthik\Desktop\32bitsiso\main.cpp -o CMakeFiles\siso.dir\main.cpp.s

CMakeFiles/siso.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/siso.dir/main.cpp.obj.requires

CMakeFiles/siso.dir/main.cpp.obj.provides: CMakeFiles/siso.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\siso.dir\build.make CMakeFiles/siso.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/siso.dir/main.cpp.obj.provides

CMakeFiles/siso.dir/main.cpp.obj.provides.build: CMakeFiles/siso.dir/main.cpp.obj


# Object files for target siso
siso_OBJECTS = \
"CMakeFiles/siso.dir/main.cpp.obj"

# External object files for target siso
siso_EXTERNAL_OBJECTS =

siso.exe: CMakeFiles/siso.dir/main.cpp.obj
siso.exe: CMakeFiles/siso.dir/build.make
siso.exe: CMakeFiles/siso.dir/linklibs.rsp
siso.exe: CMakeFiles/siso.dir/objects1.rsp
siso.exe: CMakeFiles/siso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Karthik\Desktop\32bitsiso\.siso_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable siso.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\siso.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/siso.dir/build: siso.exe

.PHONY : CMakeFiles/siso.dir/build

CMakeFiles/siso.dir/requires: CMakeFiles/siso.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/siso.dir/requires

CMakeFiles/siso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\siso.dir\cmake_clean.cmake
.PHONY : CMakeFiles/siso.dir/clean

CMakeFiles/siso.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Karthik\Desktop\32bitsiso C:\Users\Karthik\Desktop\32bitsiso C:\Users\Karthik\Desktop\32bitsiso\.siso_build C:\Users\Karthik\Desktop\32bitsiso\.siso_build C:\Users\Karthik\Desktop\32bitsiso\.siso_build\CMakeFiles\siso.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/siso.dir/depend

