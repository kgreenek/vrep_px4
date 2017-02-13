cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#-------------------------------------------------------------------------------
# Import dependencies
add_library(mavlink INTERFACE)
target_include_directories(mavlink INTERFACE "vendor/mavlink/include")

#-------------------------------------------------------------------------------
# Build sub-directories
add_subdirectory(v_repExtPx4)

#-------------------------------------------------------------------------------
# Install models
install(FILES "models/PX4 Quadricopter.ttm" DESTINATION "models/robots/mobile")
