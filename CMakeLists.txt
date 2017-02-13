cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

#-------------------------------------------------------------------------------
# Import dependencies
add_library(mavlink INTERFACE)
target_include_directories(mavlink INTERFACE "vendor/mavlink/include")

#-------------------------------------------------------------------------------
# Build sub-directories
add_subdirectory(v_repExtPx4)
