cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

project(VRepPX4Plugin VERSION 0.1.0 LANGUAGES CXX)

configure_file(
  "${PROJECT_SOURCE_DIR}/vrep_px4_config.h.in"
  "${PROJECT_BINANY_DIR}/vrep_px4_config.h")

#-------------------------------------------------------------------------------
# Build v_repExtPX4 lib
add_library(v_repExtPX4 STATIC
  "src/plugin.cpp")
target_include_directories(v_repExtPX4 PRIVATE
  "src"
  "${PROJECT_BINARY_DIR}")
target_link_libraries(v_repExtPX4 mavlink)
install(TARGETS v_repExtPX4 DESTINATION "${CMAKE_INSTALL_PREFIX}")
