# Math module CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Enable C++ modules support
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create math library with C++ module
add_library(tab_cg_math STATIC)

# Add C++ module interface file
target_sources(tab_cg_math
        PUBLIC
        FILE_SET CXX_MODULES FILES
        "vector2.ixx" "vector3.ixx" "vector4.ixx")

# Set compiler features
target_compile_features(tab_cg_math PUBLIC cxx_std_23)

# Set include directories
target_include_directories(tab_cg_math INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Enable modules support for different compilers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(tab_cg_math PUBLIC -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(tab_cg_math PUBLIC -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(tab_cg_math PUBLIC /experimental:module)
endif()
