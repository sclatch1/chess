# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/davidscalais/Desktop/IP /chess"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/davidscalais/Desktop/IP /chess/build"

# Include any dependencies generated for this target.
include CMakeFiles/schaken.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/schaken.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/schaken.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/schaken.dir/flags.make

CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o: schaken_autogen/mocs_compilation.cpp
CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o -MF CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/build/schaken_autogen/mocs_compilation.cpp"

CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/build/schaken_autogen/mocs_compilation.cpp" > CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.i

CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/build/schaken_autogen/mocs_compilation.cpp" -o CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.s

CMakeFiles/schaken.dir/main.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/main.cpp.o: ../main.cpp
CMakeFiles/schaken.dir/main.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/schaken.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/main.cpp.o -MF CMakeFiles/schaken.dir/main.cpp.o.d -o CMakeFiles/schaken.dir/main.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/main.cpp"

CMakeFiles/schaken.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/main.cpp" > CMakeFiles/schaken.dir/main.cpp.i

CMakeFiles/schaken.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/main.cpp" -o CMakeFiles/schaken.dir/main.cpp.s

CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o: ../guicode/ChessWindow.cpp
CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o -MF CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o.d -o CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/guicode/ChessWindow.cpp"

CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/guicode/ChessWindow.cpp" > CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.i

CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/guicode/ChessWindow.cpp" -o CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.s

CMakeFiles/schaken.dir/guicode/chessboard.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/guicode/chessboard.cpp.o: ../guicode/chessboard.cpp
CMakeFiles/schaken.dir/guicode/chessboard.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/schaken.dir/guicode/chessboard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/guicode/chessboard.cpp.o -MF CMakeFiles/schaken.dir/guicode/chessboard.cpp.o.d -o CMakeFiles/schaken.dir/guicode/chessboard.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/guicode/chessboard.cpp"

CMakeFiles/schaken.dir/guicode/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/guicode/chessboard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/guicode/chessboard.cpp" > CMakeFiles/schaken.dir/guicode/chessboard.cpp.i

CMakeFiles/schaken.dir/guicode/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/guicode/chessboard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/guicode/chessboard.cpp" -o CMakeFiles/schaken.dir/guicode/chessboard.cpp.s

CMakeFiles/schaken.dir/game.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/game.cpp.o: ../game.cpp
CMakeFiles/schaken.dir/game.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/schaken.dir/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/game.cpp.o -MF CMakeFiles/schaken.dir/game.cpp.o.d -o CMakeFiles/schaken.dir/game.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/game.cpp"

CMakeFiles/schaken.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/game.cpp" > CMakeFiles/schaken.dir/game.cpp.i

CMakeFiles/schaken.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/game.cpp" -o CMakeFiles/schaken.dir/game.cpp.s

CMakeFiles/schaken.dir/SchaakStuk.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/SchaakStuk.cpp.o: ../SchaakStuk.cpp
CMakeFiles/schaken.dir/SchaakStuk.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/schaken.dir/SchaakStuk.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/SchaakStuk.cpp.o -MF CMakeFiles/schaken.dir/SchaakStuk.cpp.o.d -o CMakeFiles/schaken.dir/SchaakStuk.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/SchaakStuk.cpp"

CMakeFiles/schaken.dir/SchaakStuk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/SchaakStuk.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/SchaakStuk.cpp" > CMakeFiles/schaken.dir/SchaakStuk.cpp.i

CMakeFiles/schaken.dir/SchaakStuk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/SchaakStuk.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/SchaakStuk.cpp" -o CMakeFiles/schaken.dir/SchaakStuk.cpp.s

CMakeFiles/schaken.dir/SchaakGUI.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/SchaakGUI.cpp.o: ../SchaakGUI.cpp
CMakeFiles/schaken.dir/SchaakGUI.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/schaken.dir/SchaakGUI.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/SchaakGUI.cpp.o -MF CMakeFiles/schaken.dir/SchaakGUI.cpp.o.d -o CMakeFiles/schaken.dir/SchaakGUI.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/SchaakGUI.cpp"

CMakeFiles/schaken.dir/SchaakGUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/SchaakGUI.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/SchaakGUI.cpp" > CMakeFiles/schaken.dir/SchaakGUI.cpp.i

CMakeFiles/schaken.dir/SchaakGUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/SchaakGUI.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/SchaakGUI.cpp" -o CMakeFiles/schaken.dir/SchaakGUI.cpp.s

CMakeFiles/schaken.dir/guicode/message.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/guicode/message.cpp.o: ../guicode/message.cpp
CMakeFiles/schaken.dir/guicode/message.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/schaken.dir/guicode/message.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/guicode/message.cpp.o -MF CMakeFiles/schaken.dir/guicode/message.cpp.o.d -o CMakeFiles/schaken.dir/guicode/message.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/guicode/message.cpp"

CMakeFiles/schaken.dir/guicode/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/guicode/message.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/guicode/message.cpp" > CMakeFiles/schaken.dir/guicode/message.cpp.i

CMakeFiles/schaken.dir/guicode/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/guicode/message.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/guicode/message.cpp" -o CMakeFiles/schaken.dir/guicode/message.cpp.s

CMakeFiles/schaken.dir/guicode/fileIO.cpp.o: CMakeFiles/schaken.dir/flags.make
CMakeFiles/schaken.dir/guicode/fileIO.cpp.o: ../guicode/fileIO.cpp
CMakeFiles/schaken.dir/guicode/fileIO.cpp.o: CMakeFiles/schaken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/schaken.dir/guicode/fileIO.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schaken.dir/guicode/fileIO.cpp.o -MF CMakeFiles/schaken.dir/guicode/fileIO.cpp.o.d -o CMakeFiles/schaken.dir/guicode/fileIO.cpp.o -c "/Users/davidscalais/Desktop/IP /chess/guicode/fileIO.cpp"

CMakeFiles/schaken.dir/guicode/fileIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schaken.dir/guicode/fileIO.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/davidscalais/Desktop/IP /chess/guicode/fileIO.cpp" > CMakeFiles/schaken.dir/guicode/fileIO.cpp.i

CMakeFiles/schaken.dir/guicode/fileIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schaken.dir/guicode/fileIO.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/davidscalais/Desktop/IP /chess/guicode/fileIO.cpp" -o CMakeFiles/schaken.dir/guicode/fileIO.cpp.s

# Object files for target schaken
schaken_OBJECTS = \
"CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/schaken.dir/main.cpp.o" \
"CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o" \
"CMakeFiles/schaken.dir/guicode/chessboard.cpp.o" \
"CMakeFiles/schaken.dir/game.cpp.o" \
"CMakeFiles/schaken.dir/SchaakStuk.cpp.o" \
"CMakeFiles/schaken.dir/SchaakGUI.cpp.o" \
"CMakeFiles/schaken.dir/guicode/message.cpp.o" \
"CMakeFiles/schaken.dir/guicode/fileIO.cpp.o"

# External object files for target schaken
schaken_EXTERNAL_OBJECTS =

schaken: CMakeFiles/schaken.dir/schaken_autogen/mocs_compilation.cpp.o
schaken: CMakeFiles/schaken.dir/main.cpp.o
schaken: CMakeFiles/schaken.dir/guicode/ChessWindow.cpp.o
schaken: CMakeFiles/schaken.dir/guicode/chessboard.cpp.o
schaken: CMakeFiles/schaken.dir/game.cpp.o
schaken: CMakeFiles/schaken.dir/SchaakStuk.cpp.o
schaken: CMakeFiles/schaken.dir/SchaakGUI.cpp.o
schaken: CMakeFiles/schaken.dir/guicode/message.cpp.o
schaken: CMakeFiles/schaken.dir/guicode/fileIO.cpp.o
schaken: CMakeFiles/schaken.dir/build.make
schaken: /Users/davidscalais/Qt/5.15.2/clang_64/lib/QtWidgets.framework/QtWidgets
schaken: /Users/davidscalais/Qt/5.15.2/clang_64/lib/QtGui.framework/QtGui
schaken: /Users/davidscalais/Qt/5.15.2/clang_64/lib/QtCore.framework/QtCore
schaken: CMakeFiles/schaken.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable schaken"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/schaken.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/schaken.dir/build: schaken
.PHONY : CMakeFiles/schaken.dir/build

CMakeFiles/schaken.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/schaken.dir/cmake_clean.cmake
.PHONY : CMakeFiles/schaken.dir/clean

CMakeFiles/schaken.dir/depend:
	cd "/Users/davidscalais/Desktop/IP /chess/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/davidscalais/Desktop/IP /chess" "/Users/davidscalais/Desktop/IP /chess" "/Users/davidscalais/Desktop/IP /chess/build" "/Users/davidscalais/Desktop/IP /chess/build" "/Users/davidscalais/Desktop/IP /chess/build/CMakeFiles/schaken.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/schaken.dir/depend

