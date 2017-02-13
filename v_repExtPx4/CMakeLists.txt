cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

project(VREPPX4 VERSION 0.1.0 LANGUAGES CXX)

#-------------------------------------------------------------------------------
# Build v_repExtPX4 lib
add_library(v_repExtPX4 STATIC
  "src/plugin.cpp")
target_include_directories(v_repExtPX4 PRIVATE "src")
target_link_libraries(v_repExtPX4 mavlink)
install(TARGETS v_repExtPX4 DESTINATION "${CMAKE_INSTALL_PREFIX}")
