cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

project(VRepPlugin VERSION 3.3.2 LANGUAGES CXX)

#-------------------------------------------------------------------------------
# Build vrepplugin lib
add_library(vrepplugin
  "src/luaFunctionData.cpp"
  "src/luaFunctionDataItem.cpp"
  "src/scriptFunctionData.cpp"
  "src/scriptFunctionDataItem.cpp"
  "src/socketInConnection.cpp"
  "src/socketOutConnection.cpp"
  "src/v_repLib.cpp")
target_include_directories(vrepplugin
  PUBLIC "include"
  PRIVATE "include/vrep")
set_property(TARGET vrepplugin PROPERTY POSITION_INDEPENDENT_CODE ON)
