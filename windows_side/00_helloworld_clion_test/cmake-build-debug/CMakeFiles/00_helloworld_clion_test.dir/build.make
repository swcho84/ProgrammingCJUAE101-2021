# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\00_helloworld_clion_test.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\00_helloworld_clion_test.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\00_helloworld_clion_test.dir\flags.make

CMakeFiles\00_helloworld_clion_test.dir\main.cpp.obj: CMakeFiles\00_helloworld_clion_test.dir\flags.make
CMakeFiles\00_helloworld_clion_test.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/00_helloworld_clion_test.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\00_helloworld_clion_test.dir\main.cpp.obj /FdCMakeFiles\00_helloworld_clion_test.dir\ /FS -c C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\main.cpp
<<

CMakeFiles\00_helloworld_clion_test.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/00_helloworld_clion_test.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\00_helloworld_clion_test.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\main.cpp
<<

CMakeFiles\00_helloworld_clion_test.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/00_helloworld_clion_test.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\00_helloworld_clion_test.dir\main.cpp.s /c C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\main.cpp
<<

# Object files for target 00_helloworld_clion_test
00_helloworld_clion_test_OBJECTS = \
"CMakeFiles\00_helloworld_clion_test.dir\main.cpp.obj"

# External object files for target 00_helloworld_clion_test
00_helloworld_clion_test_EXTERNAL_OBJECTS =

00_helloworld_clion_test.exe: CMakeFiles\00_helloworld_clion_test.dir\main.cpp.obj
00_helloworld_clion_test.exe: CMakeFiles\00_helloworld_clion_test.dir\build.make
00_helloworld_clion_test.exe: CMakeFiles\00_helloworld_clion_test.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 00_helloworld_clion_test.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\00_helloworld_clion_test.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\00_helloworld_clion_test.dir\objects1.rsp @<<
 /out:00_helloworld_clion_test.exe /implib:00_helloworld_clion_test.lib /pdb:C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug\00_helloworld_clion_test.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\00_helloworld_clion_test.dir\build: 00_helloworld_clion_test.exe
.PHONY : CMakeFiles\00_helloworld_clion_test.dir\build

CMakeFiles\00_helloworld_clion_test.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\00_helloworld_clion_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles\00_helloworld_clion_test.dir\clean

CMakeFiles\00_helloworld_clion_test.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug C:\Users\user\source\repos\ProgrammingCJUAE101-2021\windows_side\00_helloworld_clion_test\cmake-build-debug\CMakeFiles\00_helloworld_clion_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\00_helloworld_clion_test.dir\depend

