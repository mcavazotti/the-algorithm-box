# Graphics tests CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Add subdirectories
add_subdirectory(math)

# Create graphics test library as interface (no sources needed)
add_library(graphics_tests INTERFACE)

# Link math tests to graphics tests
target_link_libraries(graphics_tests
        INTERFACE
        math_tests
        tab_cg
        gtest
)

# Set C++ standard
target_compile_features(graphics_tests INTERFACE cxx_std_23)

# Create standalone graphics test executable using math test sources
# Get the math test sources from the math subdirectory
file(GLOB MATH_TEST_SOURCES "math/*.cpp" "math/*.cxx" "math/*.cc")
add_executable(graphics_test_runner ${MATH_TEST_SOURCES})

# Link dependencies for standalone runner
target_link_libraries(graphics_test_runner
        PRIVATE
        graphics_tests
        gtest_main
)

# Add test to CTest
add_test(NAME graphics_unit_tests COMMAND graphics_test_runner)

# Set include directories
target_include_directories(graphics_tests INTERFACE
        ${CMAKE_SOURCE_DIR}/tab
        ${CMAKE_SOURCE_DIR}/tab/graphics
)

# Enable modules support for different compilers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(graphics_test_runner PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(graphics_test_runner PRIVATE -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(graphics_test_runner PRIVATE /experimental:module)
endif()