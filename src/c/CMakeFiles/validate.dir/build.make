# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangxiao/git/sc/src/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangxiao/git/sc/src/c

# Include any dependencies generated for this target.
include CMakeFiles/validate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/validate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/validate.dir/flags.make

CMakeFiles/validate.dir/validator/validator.c.o: CMakeFiles/validate.dir/flags.make
CMakeFiles/validate.dir/validator/validator.c.o: validator/validator.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/wangxiao/git/sc/src/c/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/validate.dir/validator/validator.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/validate.dir/validator/validator.c.o   -c /Users/wangxiao/git/sc/src/c/validator/validator.c

CMakeFiles/validate.dir/validator/validator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/validate.dir/validator/validator.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/wangxiao/git/sc/src/c/validator/validator.c > CMakeFiles/validate.dir/validator/validator.c.i

CMakeFiles/validate.dir/validator/validator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/validate.dir/validator/validator.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/wangxiao/git/sc/src/c/validator/validator.c -o CMakeFiles/validate.dir/validator/validator.c.s

CMakeFiles/validate.dir/validator/validator.c.o.requires:
.PHONY : CMakeFiles/validate.dir/validator/validator.c.o.requires

CMakeFiles/validate.dir/validator/validator.c.o.provides: CMakeFiles/validate.dir/validator/validator.c.o.requires
	$(MAKE) -f CMakeFiles/validate.dir/build.make CMakeFiles/validate.dir/validator/validator.c.o.provides.build
.PHONY : CMakeFiles/validate.dir/validator/validator.c.o.provides

CMakeFiles/validate.dir/validator/validator.c.o.provides.build: CMakeFiles/validate.dir/validator/validator.c.o

CMakeFiles/validate.dir/validator/test.c.o: CMakeFiles/validate.dir/flags.make
CMakeFiles/validate.dir/validator/test.c.o: validator/test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/wangxiao/git/sc/src/c/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/validate.dir/validator/test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/validate.dir/validator/test.c.o   -c /Users/wangxiao/git/sc/src/c/validator/test.c

CMakeFiles/validate.dir/validator/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/validate.dir/validator/test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/wangxiao/git/sc/src/c/validator/test.c > CMakeFiles/validate.dir/validator/test.c.i

CMakeFiles/validate.dir/validator/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/validate.dir/validator/test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/wangxiao/git/sc/src/c/validator/test.c -o CMakeFiles/validate.dir/validator/test.c.s

CMakeFiles/validate.dir/validator/test.c.o.requires:
.PHONY : CMakeFiles/validate.dir/validator/test.c.o.requires

CMakeFiles/validate.dir/validator/test.c.o.provides: CMakeFiles/validate.dir/validator/test.c.o.requires
	$(MAKE) -f CMakeFiles/validate.dir/build.make CMakeFiles/validate.dir/validator/test.c.o.provides.build
.PHONY : CMakeFiles/validate.dir/validator/test.c.o.provides

CMakeFiles/validate.dir/validator/test.c.o.provides.build: CMakeFiles/validate.dir/validator/test.c.o

# Object files for target validate
validate_OBJECTS = \
"CMakeFiles/validate.dir/validator/validator.c.o" \
"CMakeFiles/validate.dir/validator/test.c.o"

# External object files for target validate
validate_EXTERNAL_OBJECTS =

bin/validate: CMakeFiles/validate.dir/validator/validator.c.o
bin/validate: CMakeFiles/validate.dir/validator/test.c.o
bin/validate: CMakeFiles/validate.dir/build.make
bin/validate: CMakeFiles/validate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable bin/validate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/validate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/validate.dir/build: bin/validate
.PHONY : CMakeFiles/validate.dir/build

CMakeFiles/validate.dir/requires: CMakeFiles/validate.dir/validator/validator.c.o.requires
CMakeFiles/validate.dir/requires: CMakeFiles/validate.dir/validator/test.c.o.requires
.PHONY : CMakeFiles/validate.dir/requires

CMakeFiles/validate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/validate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/validate.dir/clean

CMakeFiles/validate.dir/depend:
	cd /Users/wangxiao/git/sc/src/c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangxiao/git/sc/src/c /Users/wangxiao/git/sc/src/c /Users/wangxiao/git/sc/src/c /Users/wangxiao/git/sc/src/c /Users/wangxiao/git/sc/src/c/CMakeFiles/validate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/validate.dir/depend

