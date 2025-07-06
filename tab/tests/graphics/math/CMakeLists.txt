# Math tests CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Collect all test files in this directory
file(GLOB MATH_TEST_SOURCES "*.cpp" "*.cxx" "*.cc")

# Create math test library
add_library(math_tests STATIC ${MATH_TEST_SOURCES})

# Link test dependencies
target_link_libraries(math_tests
        PUBLIC
        tab_cg_math
        gtest
)

# Set C++ standard
target_compile_features(math_tests PUBLIC cxx_std_23)

# Create standalone math test executable
add_executable(math_test_runner ${MATH_TEST_SOURCES})

# Link dependencies for standalone runner
target_link_libraries(math_test_runner
        PRIVATE
        tab_cg_math
        gtest_main
)

# Add test to CTest
add_test(NAME math_unit_tests COMMAND math_test_runner)

# Set include directories
target_include_directories(math_tests PUBLIC
        ${CMAKE_SOURCE_DIR}/tab
        ${CMAKE_SOURCE_DIR}/tab/graphics
        ${CMAKE_SOURCE_DIR}/tab/graphics/math
)

# Enable modules support for different compilers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(math_tests PUBLIC -fmodules-ts)
    target_compile_options(math_test_runner PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(math_tests PUBLIC -fmodules)
    target_compile_options(math_test_runner PRIVATE -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(math_tests PUBLIC /experimental:module)
    target_compile_options(math_test_runner PRIVATE /experimental:module)
endif()