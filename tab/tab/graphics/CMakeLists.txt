# Graphics module CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Add subdirectories
add_subdirectory(math)

# Create graphics library target
add_library(tab_cg INTERFACE)

# Link math module to graphics
target_link_libraries(tab_cg INTERFACE tab_cg_math)

# Set include directories
target_include_directories(tab_cg INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)