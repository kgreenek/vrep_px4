cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#-------------------------------------------------------------------------------
# Import dependencies
add_library(mavlink INTERFACE)
target_include_directories(mavlink INTERFACE "vendor/mavlink/include")

add_subdirectory("vendor/vrep")

#-------------------------------------------------------------------------------
# Build sub-directories
add_subdirectory(v_repExtPx4)

#-------------------------------------------------------------------------------
# Install models
install(FILES "models/PX4 Quadricopter.ttm"
  DESTINATION "models/robots/mobile"
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ)
