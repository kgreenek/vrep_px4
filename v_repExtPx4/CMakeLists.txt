cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)

project(VREPPX4 VERSION 0.1.0 LANGUAGES CXX)

#-------------------------------------------------------------------------------
# Import dependencies
find_package(Boost REQUIRED COMPONENTS system)
if(NOT TARGET boost::system)
  add_library(boost::system INTERFACE IMPORTED)
  set_target_properties(boost::system PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${Boost_SYSTEM_INCLUDE_DIRS}"
    INTERFACE_LINK_LIBRARIES "${Boost_SYSTEM_LIBRARIES}")
endif()

#-------------------------------------------------------------------------------
# Build v_repExtPX4 lib
add_library(v_repExtPX4 SHARED
  "src/mavlink_server.cpp"
  "src/plugin.cpp")
target_include_directories(v_repExtPX4 PRIVATE "src")
target_link_libraries(v_repExtPX4
  # For boost.asio
  boost::system
  mavlink
  vrepplugin)
install(TARGETS v_repExtPX4
  DESTINATION "${CMAKE_INSTALL_PREFIX}"
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
              GROUP_READ GROUP_WRITE GROUP_EXECUTE
              WORLD_READ)
