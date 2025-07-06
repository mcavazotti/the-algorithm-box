# Tab module CMakeLists.txt
cmake_minimum_required(VERSION 3.31)

# Add subdirectories
add_subdirectory(graphics)

# Create tab library target
add_library(tab INTERFACE)

# Link graphics module to tab
target_link_libraries(tab INTERFACE tab_cg)

# Set include directories
target_include_directories(tab INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)