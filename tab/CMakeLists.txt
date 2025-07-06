# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Project declaration
project(tab VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable C++ modules support
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Add compile options for C++ modules
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/experimental:module)
endif()

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add subdirectories
add_subdirectory(tab)

# Fetch Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make googletest available
FetchContent_MakeAvailable(googletest)

# Build tests
message(STATUS "Building tests with FetchContent Google Test")
add_subdirectory(tests)

# Enable testing at root level
enable_testing()
include(CTest)

# Development convenience targets
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # Add a custom target to run all tests
    if(TARGET tab_all_tests)
        add_custom_target(run_tests
                COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
                DEPENDS tab_all_tests
                COMMENT "Running all tests"
        )
    endif()

    # Add a custom target for clean build
    add_custom_target(clean_build
            COMMAND ${CMAKE_COMMAND} --build . --target clean
            COMMAND ${CMAKE_COMMAND} --build .
            COMMENT "Clean and rebuild"
    )
endif()