# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/teddy/Dev/Crypto/CRYPTOKATON

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teddy/Dev/Crypto/CRYPTOKATON/build

# Include any dependencies generated for this target.
include CMakeFiles/Blockchain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Blockchain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Blockchain.dir/flags.make

CMakeFiles/Blockchain.dir/src/Blockchain.cc.o: CMakeFiles/Blockchain.dir/flags.make
CMakeFiles/Blockchain.dir/src/Blockchain.cc.o: ../src/Blockchain.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teddy/Dev/Crypto/CRYPTOKATON/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Blockchain.dir/src/Blockchain.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blockchain.dir/src/Blockchain.cc.o -c /home/teddy/Dev/Crypto/CRYPTOKATON/src/Blockchain.cc

CMakeFiles/Blockchain.dir/src/Blockchain.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blockchain.dir/src/Blockchain.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teddy/Dev/Crypto/CRYPTOKATON/src/Blockchain.cc > CMakeFiles/Blockchain.dir/src/Blockchain.cc.i

CMakeFiles/Blockchain.dir/src/Blockchain.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blockchain.dir/src/Blockchain.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teddy/Dev/Crypto/CRYPTOKATON/src/Blockchain.cc -o CMakeFiles/Blockchain.dir/src/Blockchain.cc.s

CMakeFiles/Blockchain.dir/main.cc.o: CMakeFiles/Blockchain.dir/flags.make
CMakeFiles/Blockchain.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teddy/Dev/Crypto/CRYPTOKATON/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Blockchain.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blockchain.dir/main.cc.o -c /home/teddy/Dev/Crypto/CRYPTOKATON/main.cc

CMakeFiles/Blockchain.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blockchain.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teddy/Dev/Crypto/CRYPTOKATON/main.cc > CMakeFiles/Blockchain.dir/main.cc.i

CMakeFiles/Blockchain.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blockchain.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teddy/Dev/Crypto/CRYPTOKATON/main.cc -o CMakeFiles/Blockchain.dir/main.cc.s

# Object files for target Blockchain
Blockchain_OBJECTS = \
"CMakeFiles/Blockchain.dir/src/Blockchain.cc.o" \
"CMakeFiles/Blockchain.dir/main.cc.o"

# External object files for target Blockchain
Blockchain_EXTERNAL_OBJECTS =

Blockchain: CMakeFiles/Blockchain.dir/src/Blockchain.cc.o
Blockchain: CMakeFiles/Blockchain.dir/main.cc.o
Blockchain: CMakeFiles/Blockchain.dir/build.make
Blockchain: CMakeFiles/Blockchain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teddy/Dev/Crypto/CRYPTOKATON/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Blockchain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Blockchain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Blockchain.dir/build: Blockchain

.PHONY : CMakeFiles/Blockchain.dir/build

CMakeFiles/Blockchain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Blockchain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Blockchain.dir/clean

CMakeFiles/Blockchain.dir/depend:
	cd /home/teddy/Dev/Crypto/CRYPTOKATON/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teddy/Dev/Crypto/CRYPTOKATON /home/teddy/Dev/Crypto/CRYPTOKATON /home/teddy/Dev/Crypto/CRYPTOKATON/build /home/teddy/Dev/Crypto/CRYPTOKATON/build /home/teddy/Dev/Crypto/CRYPTOKATON/build/CMakeFiles/Blockchain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Blockchain.dir/depend
