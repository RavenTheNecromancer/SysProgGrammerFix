# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/findandfix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/findandfix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/findandfix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/findandfix.dir/flags.make

CMakeFiles/findandfix.dir/main.c.obj: CMakeFiles/findandfix.dir/flags.make
CMakeFiles/findandfix.dir/main.c.obj: C:/Users/dimit/Desktop/SP\ AAAAAAAAA/SysProgGrammerFix/main.c
CMakeFiles/findandfix.dir/main.c.obj: CMakeFiles/findandfix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/findandfix.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/findandfix.dir/main.c.obj -MF CMakeFiles\findandfix.dir\main.c.obj.d -o CMakeFiles\findandfix.dir\main.c.obj -c "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\main.c"

CMakeFiles/findandfix.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/findandfix.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\main.c" > CMakeFiles\findandfix.dir\main.c.i

CMakeFiles/findandfix.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/findandfix.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\main.c" -o CMakeFiles\findandfix.dir\main.c.s

# Object files for target findandfix
findandfix_OBJECTS = \
"CMakeFiles/findandfix.dir/main.c.obj"

# External object files for target findandfix
findandfix_EXTERNAL_OBJECTS =

findandfix.exe: CMakeFiles/findandfix.dir/main.c.obj
findandfix.exe: CMakeFiles/findandfix.dir/build.make
findandfix.exe: CMakeFiles/findandfix.dir/linkLibs.rsp
findandfix.exe: CMakeFiles/findandfix.dir/objects1.rsp
findandfix.exe: CMakeFiles/findandfix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable findandfix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\findandfix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/findandfix.dir/build: findandfix.exe
.PHONY : CMakeFiles/findandfix.dir/build

CMakeFiles/findandfix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\findandfix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/findandfix.dir/clean

CMakeFiles/findandfix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix" "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix" "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug" "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug" "C:\Users\dimit\Desktop\SP AAAAAAAAA\SysProgGrammerFix\cmake-build-debug\CMakeFiles\findandfix.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/findandfix.dir/depend
