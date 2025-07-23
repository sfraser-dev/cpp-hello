# Run `cmake ..` from the build/ folder.
# Meta-build system two step process.
# Cmake generates Makefiles, then use Make with these Makefiles.

# Minimum version of CMake required.
cmake_minimum_required(VERSION 3.20)

# Define the project.
# Set project name and specify using C++ as a language.
project(CppReviewAndReference LANGUAGES CXX)

# Set C++ standard to C++20.
# CMAKE_CXX_STANDARD_REQUIRED ON make build fail if C++20 not supported.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally enable AddressSanitizer.
# Uncomment the line below to enable it.
# This will add the necessary compiler and linker flags for AddressSanitizer.
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Define common include directories.
# CURRENT_SOURCE_DIR is folder where this CMakeLists.txt file resides.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Define Executables ---
# List all source files that are the main entry point for an executable.
# CMake automatically infers exe name from the source file name.
set(EXEC_SOURCES
    src/hello1.cpp
    src/hello2.cpp
    src/moderncpp/lrncpp00p01.cpp
    src/compiler-language-info.cpp
    src/leaky.cpp
)

# Add each single-source executable.
# For each source file in EXEC_SOURCES, create an executable target.
foreach(SRC_FILE ${EXEC_SOURCES})
    # Get the base name of the source file (eg: "hello1" from "hello1.cpp")
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)
    # Add the executable target
    add_executable(${TARGET_NAME} ${SRC_FILE})
endforeach()

# --- Handle test.exe which has multiple source files ---
# Specificallt Define the source files for the 'test' executable.
set(TEST_SOURCES
    src/test.cpp
    src/test-joe.cpp
)

# Add the 'test' executable target.
# CMake automatically resolves dependencies between .cpp and .h files.
add_executable(test ${TEST_SOURCES})

# Link 'test' executable with the PCRE library.
# target_link_libraries specifies libraries an exeor lib depends on.
# PRIVATE means dependency is only for building this target, not for targets that link to it.
target_link_libraries(test PRIVATE pcre)

# --- Optional: Add a custom target for 'all' to explicitly build everything ---
# In CMake, `add_executable` already makes targets part of the default build.
# This 'all_build' target is mostly for demonstration or if you want a single
# explicit target to build everything, though it's often redundant.
add_custom_target(all_build ALL DEPENDS ${EXECUTABLES})

# --- Optional: Add a 'clean' target (CMake handles this automatically too) ---
# CMake's generated build systems (like Makefiles or Ninja files) inherently
# support cleaning. You typically run 'make clean' (for Make) or 'ninja clean'
# (for Ninja) after CMake has generated the build files.
# This custom target is usually not necessary but can be added for familiarity.
# add_custom_target(clean_build
#     COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
#     COMMENT "Cleaning build directory"
# )

# You can also add a target to run all executables, similar to 'make run'
add_custom_target(run_all
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/hello1
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/hello2
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/lrncpp00p01
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/compiler-language-info
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/leaky
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test
    COMMENT "Running all compiled executables"
)
