
# ----------------------------------------------------------------
# This CMake file is generated automatically by the Shake3 CMake Generator
# Don't change this file. Reconfigure the generator instead.

cmake_minimum_required( VERSION 3.12 )

# ----------------------------------------------------------------
# CMake configuration

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "C:/Users/Berry/Documents/development/shake3/build" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "C:/Users/Berry/Documents/development/shake3/build" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/Berry/Documents/development/shake3/build" )
set( CMAKE_EXECUTABLE_OUTPUT_PATH   "C:/Users/Berry/Documents/development/shake3/build" )

# this option is necessary to automatically export ALL symbols in a library on Windows, 
# without needing to specify __declspec( export ).
# That means it also creates a .lib file for shared libraries
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

# ----------------------------------------------------------------
# Project: Shake3

project( Shake3 VERSION 0.1 LANGUAGES CXX C )

# ----------------------------------------------------------------
# Import Targets: freetype

add_subdirectory( "C:/Users/Berry/Documents/development/shake3/external/freetype-2.9" )

# ----------------------------------------------------------------
# New Target: glad

file( GLOB_RECURSE glad_glob_files "C:/Users/Berry/Documents/development/shake3/external/glad/src/*" )

add_library( glad STATIC ${glad_glob_files} )

target_include_directories( glad PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/external/glad/include" 
)

set_property( TARGET glad PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# Import Targets: glfw

set( BUILD_SHARED_LIBS ON )
option( GLFW_INSTALL			OFF )
option( GLFW_BUILD_DOCS			OFF )
option( GLFW_BUILD_EXAMPLES		OFF )
option( GLFW_BUILD_TESTS		OFF )

add_subdirectory( "C:/Users/Berry/Documents/development/shake3/external/glfw" )

# ----------------------------------------------------------------
# New Target: json11

file( GLOB_RECURSE json11_glob_files "C:/Users/Berry/Documents/development/shake3/external/json11/json11/*" )

add_library( json11 SHARED ${json11_glob_files} )

target_include_directories( json11 PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/external/json11" 
)

set_property( TARGET json11 PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# Import Targets: pybind11, ${PYTHON_LIBRARIES}

set( PYBIND11_CPP_STANDARD -std=c++17 )        

add_subdirectory( "C:/Users/Berry/Documents/development/shake3/external/pybind11-2.2.3" )

# ----------------------------------------------------------------
# New Target: shake_content

file( GLOB_RECURSE shake_content_glob_files "C:/Users/Berry/Documents/development/shake3/shake_content/src/*" )

add_library( shake_content SHARED ${shake_content_glob_files} )

target_include_directories( shake_content PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_content/src"
    "C:/Users/Berry/Documents/development/shake3/external/freetype-2.9/include"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    "C:/Users/Berry/Documents/development/shake3/external/json11"
    "C:/Users/Berry/Documents/development/shake3/external/stb"
    "C:/Users/Berry/Documents/development/shake3/shake_core/src"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics/src"
    "C:/Users/Berry/Documents/development/shake3/shake_io/src" 
)

target_link_libraries( shake_content PRIVATE 
    freetype
    json11
    shake_core
    shake_graphics
    shake_io 
)

set_property( TARGET shake_content PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_core

file( GLOB_RECURSE shake_core_glob_files "C:/Users/Berry/Documents/development/shake3/shake_core/src/*" )

add_library( shake_core SHARED ${shake_core_glob_files} )

target_include_directories( shake_core PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_core/src"
    "C:/Users/Berry/Documents/development/shake3/external/glm" 
)

set_property( TARGET shake_core PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_ecs

file( GLOB_RECURSE shake_ecs_glob_files "C:/Users/Berry/Documents/development/shake3/shake_ecs/src/*" )

add_library( shake_ecs SHARED ${shake_ecs_glob_files} )

target_include_directories( shake_ecs PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_ecs/src"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    ${PYBIND11_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    "C:/Users/Berry/Documents/development/shake3/shake_core/src"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics/src"
    "C:/Users/Berry/Documents/development/shake3/shake_hid/src" 
)

target_link_libraries( shake_ecs PRIVATE 
    pybind11
    ${PYTHON_LIBRARIES}
    shake_core
    shake_graphics
    shake_hid 
)

set_property( TARGET shake_ecs PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_graphics

file( GLOB_RECURSE shake_graphics_glob_files "C:/Users/Berry/Documents/development/shake3/shake_graphics/src/*" )

add_library( shake_graphics SHARED ${shake_graphics_glob_files} )

target_include_directories( shake_graphics PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_graphics/src"
    "C:/Users/Berry/Documents/development/shake3/external/glad/include"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    "C:/Users/Berry/Documents/development/shake3/shake_core/src" 
)

target_link_libraries( shake_graphics PRIVATE 
    glad
    shake_core 
)

set_property( TARGET shake_graphics PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_hid

file( GLOB_RECURSE shake_hid_glob_files "C:/Users/Berry/Documents/development/shake3/shake_hid/src/*" )

add_library( shake_hid SHARED ${shake_hid_glob_files} )

target_include_directories( shake_hid PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_hid/src"
    "C:/Users/Berry/Documents/development/shake3/external/glfw/include"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    ${PYBIND11_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    "C:/Users/Berry/Documents/development/shake3/shake_core/src" 
)

target_link_libraries( shake_hid PRIVATE 
    glfw
    pybind11
    ${PYTHON_LIBRARIES}
    shake_core 
)

set_property( TARGET shake_hid PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_io

file( GLOB_RECURSE shake_io_glob_files "C:/Users/Berry/Documents/development/shake3/shake_io/src/*" )

add_library( shake_io SHARED ${shake_io_glob_files} )

target_include_directories( shake_io PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_io/src"
    "C:/Users/Berry/Documents/development/shake3/external/json11"
    "C:/Users/Berry/Documents/development/shake3/shake_core/src" 
)

target_link_libraries( shake_io PRIVATE 
    json11
    shake_core 
)

set_property( TARGET shake_io PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_main

file( GLOB_RECURSE shake_main_glob_files "C:/Users/Berry/Documents/development/shake3/shake_main/src/*" )

add_library( shake_main SHARED ${shake_main_glob_files} )

target_include_directories( shake_main PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_main/src"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    "C:/Users/Berry/Documents/development/shake3/external/json11"
    "C:/Users/Berry/Documents/development/shake3/shake_content/src"
    "C:/Users/Berry/Documents/development/shake3/shake_core/src"
    "C:/Users/Berry/Documents/development/shake3/shake_ecs/src"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics/src"
    "C:/Users/Berry/Documents/development/shake3/shake_hid/src"
    "C:/Users/Berry/Documents/development/shake3/shake_io/src" 
)

target_link_libraries( shake_main PRIVATE 
    json11
    shake_content
    shake_core
    shake_ecs
    shake_graphics
    shake_hid
    shake_io 
)

set_property( TARGET shake_main PROPERTY CXX_STANDARD 17 )    

# ----------------------------------------------------------------
# New Target: shake_python

file( GLOB_RECURSE shake_python_glob_files "C:/Users/Berry/Documents/development/shake3/shake_python/src/*" )

add_library( shake_python SHARED ${shake_python_glob_files} )

target_include_directories( shake_python PRIVATE 
    "C:/Users/Berry/Documents/development/shake3/shake_python/src"
    "C:/Users/Berry/Documents/development/shake3/external/glm"
    ${PYBIND11_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    "C:/Users/Berry/Documents/development/shake3/shake_content/src"
    "C:/Users/Berry/Documents/development/shake3/shake_core/src"
    "C:/Users/Berry/Documents/development/shake3/shake_ecs/src"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics/src"
    "C:/Users/Berry/Documents/development/shake3/shake_hid/src"
    "C:/Users/Berry/Documents/development/shake3/shake_io/src"
    "C:/Users/Berry/Documents/development/shake3/shake_main/src" 
)

target_link_libraries( shake_python PRIVATE 
    pybind11
    ${PYTHON_LIBRARIES}
    shake_content
    shake_core
    shake_ecs
    shake_graphics
    shake_hid
    shake_io
    shake_main 
)

set_property( TARGET shake_python PROPERTY CXX_STANDARD 17 )    
