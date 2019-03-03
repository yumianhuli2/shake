#----------------------------------------------------------------
# Specify minimum CMake version and project name
cmake_minimum_required( VERSION 3.4 )

#----------------------------------------------------------------
# The libshake project contains the shake executable

# Create project
set( PROJECT_NAME shake_all )
project( ${PROJECT_NAME} VERSION 0.0.1 )

add_subdirectory( shake_content )
add_subdirectory( shake_core )
add_subdirectory( shake_ecs )
add_subdirectory( shake_graphics )
add_subdirectory( shake_hid )
add_subdirectory( shake_io )
add_subdirectory( shake_main )