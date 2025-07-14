
# Tests CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(graphics)

# Create main test executable using sources from subdirectories
# Get all test sources from graphics/math subdirectory
file(GLOB_RECURSE ALL_TEST_SOURCES "graphics/math/*.cpp" "graphics/math/*.cxx" "graphics/math/*.cc")

# Create main test executable that includes all tests
add_executable(tab_all_tests ${ALL_TEST_SOURCES})

# Link main test dependencies
target_link_libraries(tab_all_tests
        PRIVATE
        gtest
        gtest_main
        tab
        graphics_tests
)

# Set C++ standard
target_compile_features(tab_all_tests PRIVATE cxx_std_23)

# Add test to CTest
add_test(NAME tab_all_unit_tests COMMAND tab_all_tests)

# Set include directories
target_include_directories(tab_all_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/tab
)

# Enable modules support for different compilers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(tab_all_tests PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(tab_all_tests PRIVATE -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(tab_all_tests PRIVATE /experimental:module)
endif()