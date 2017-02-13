cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

project(VREPPX4 VERSION 1.0.0 LANGUAGES CXX)

add_library(v_repExtPX4 STATIC
  "src/plugin.cpp")
target_include_directories(v_repExtPX4 PRIVATE "src")
