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
CMAKE_SOURCE_DIR = C:\Users\Karthik\Desktop\SystemC\Interconnect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build

# Include any dependencies generated for this target.
include CMakeFiles/interconnect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interconnect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interconnect.dir/flags.make

CMakeFiles/interconnect.dir/main.cpp.obj: CMakeFiles/interconnect.dir/flags.make
CMakeFiles/interconnect.dir/main.cpp.obj: CMakeFiles/interconnect.dir/includes_CXX.rsp
CMakeFiles/interconnect.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interconnect.dir/main.cpp.obj"
	C:\SCBuilder\mingw32\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\interconnect.dir\main.cpp.obj -c C:\Users\Karthik\Desktop\SystemC\Interconnect\main.cpp

CMakeFiles/interconnect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interconnect.dir/main.cpp.i"
	C:\SCBuilder\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Karthik\Desktop\SystemC\Interconnect\main.cpp > CMakeFiles\interconnect.dir\main.cpp.i

CMakeFiles/interconnect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interconnect.dir/main.cpp.s"
	C:\SCBuilder\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Karthik\Desktop\SystemC\Interconnect\main.cpp -o CMakeFiles\interconnect.dir\main.cpp.s

CMakeFiles/interconnect.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/interconnect.dir/main.cpp.obj.requires

CMakeFiles/interconnect.dir/main.cpp.obj.provides: CMakeFiles/interconnect.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\interconnect.dir\build.make CMakeFiles/interconnect.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/interconnect.dir/main.cpp.obj.provides

CMakeFiles/interconnect.dir/main.cpp.obj.provides.build: CMakeFiles/interconnect.dir/main.cpp.obj


# Object files for target interconnect
interconnect_OBJECTS = \
"CMakeFiles/interconnect.dir/main.cpp.obj"

# External object files for target interconnect
interconnect_EXTERNAL_OBJECTS =

interconnect.exe: CMakeFiles/interconnect.dir/main.cpp.obj
interconnect.exe: CMakeFiles/interconnect.dir/build.make
interconnect.exe: CMakeFiles/interconnect.dir/linklibs.rsp
interconnect.exe: CMakeFiles/interconnect.dir/objects1.rsp
interconnect.exe: CMakeFiles/interconnect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable interconnect.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\interconnect.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interconnect.dir/build: interconnect.exe

.PHONY : CMakeFiles/interconnect.dir/build

CMakeFiles/interconnect.dir/requires: CMakeFiles/interconnect.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/interconnect.dir/requires

CMakeFiles/interconnect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\interconnect.dir\cmake_clean.cmake
.PHONY : CMakeFiles/interconnect.dir/clean

CMakeFiles/interconnect.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Karthik\Desktop\SystemC\Interconnect C:\Users\Karthik\Desktop\SystemC\Interconnect C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build C:\Users\Karthik\Desktop\SystemC\Interconnect\.interconnect_build\CMakeFiles\interconnect.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interconnect.dir/depend

