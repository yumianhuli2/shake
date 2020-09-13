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
# Project: Shake

project( Shake VERSION 4.0 LANGUAGES CXX C )

# ----------------------------------------------------------------
# Import Targets: freetype

add_subdirectory( "C:/Users/Berry/Documents/development/shake3/external//freetype-2.9/" )

# ----------------------------------------------------------------
# New Target: glad

file( GLOB_RECURSE glad_glob_files "C:/Users/Berry/Documents/development/shake3/external//glad/src//*" )
add_library( glad STATIC ${glad_glob_files} )
list( APPEND glad_include_directories
    "C:/Users/Berry/Documents/development/shake3/external//glad/include/"
)
target_include_directories( glad PRIVATE ${glad_include_directories} )
set_target_properties(
    glad
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# Import Targets: glfw

set( BUILD_SHARED_LIBS         ON  )
option( GLFW_INSTALL           OFF )
option( GLFW_BUILD_DOCS        OFF )
option( GLFW_BUILD_EXAMPLES    OFF )
option( GLFW_BUILD_TESTS       OFF )
add_subdirectory( "C:/Users/Berry/Documents/development/shake3/external//glfw/" )

# ----------------------------------------------------------------
# New Target: json11

file( GLOB_RECURSE json11_glob_files "C:/Users/Berry/Documents/development/shake3/external//json11/json11//*" )
add_library( json11 SHARED ${json11_glob_files} )
list( APPEND json11_include_directories
    "C:/Users/Berry/Documents/development/shake3/external//json11/"
)
target_include_directories( json11 PRIVATE ${json11_include_directories} )
set_target_properties(
    json11
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_content

file( GLOB_RECURSE shake_content_glob_files "C:/Users/Berry/Documents/development/shake3/shake_content//src//*" )
add_library( shake_content SHARED ${shake_content_glob_files} )
list( APPEND shake_content_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_content//src/"
    "C:/Users/Berry/Documents/development/shake3/external//freetype-2.9/include/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
    "C:/Users/Berry/Documents/development/shake3/external//json11/"
    "C:/Users/Berry/Documents/development/shake3/external//stb/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_io//src/"
)
target_include_directories( shake_content PRIVATE ${shake_content_include_directories} )
list( APPEND shake_content_link_libraries
    "freetype"
    "json11"
    "shake_core"
    "shake_graphics"
    "shake_io"
)
target_link_libraries( shake_content PRIVATE ${shake_content_link_libraries} )
set_target_properties(
    shake_content
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_core

file( GLOB_RECURSE shake_core_glob_files "C:/Users/Berry/Documents/development/shake3/shake_core//src//*" )
add_library( shake_core SHARED ${shake_core_glob_files} )
list( APPEND shake_core_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
)
target_include_directories( shake_core PRIVATE ${shake_core_include_directories} )
set_target_properties(
    shake_core
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_ecs

file( GLOB_RECURSE shake_ecs_glob_files "C:/Users/Berry/Documents/development/shake3/shake_ecs//src//*" )
add_library( shake_ecs SHARED ${shake_ecs_glob_files} )
list( APPEND shake_ecs_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_ecs//src/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_hid//src/"
)
target_include_directories( shake_ecs PRIVATE ${shake_ecs_include_directories} )
list( APPEND shake_ecs_link_libraries
    "shake_core"
    "shake_graphics"
    "shake_hid"
)
target_link_libraries( shake_ecs PRIVATE ${shake_ecs_link_libraries} )
set_target_properties(
    shake_ecs
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_graphics

file( GLOB_RECURSE shake_graphics_glob_files "C:/Users/Berry/Documents/development/shake3/shake_graphics//src//*" )
add_library( shake_graphics SHARED ${shake_graphics_glob_files} )
list( APPEND shake_graphics_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_graphics//src/"
    "C:/Users/Berry/Documents/development/shake3/external//glad/include/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
)
target_include_directories( shake_graphics PRIVATE ${shake_graphics_include_directories} )
list( APPEND shake_graphics_link_libraries
    "glad"
    "shake_core"
)
target_link_libraries( shake_graphics PRIVATE ${shake_graphics_link_libraries} )
set_target_properties(
    shake_graphics
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_hid

file( GLOB_RECURSE shake_hid_glob_files "C:/Users/Berry/Documents/development/shake3/shake_hid//src//*" )
add_library( shake_hid SHARED ${shake_hid_glob_files} )
list( APPEND shake_hid_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_hid//src/"
    "C:/Users/Berry/Documents/development/shake3/external//glfw/include/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
)
target_include_directories( shake_hid PRIVATE ${shake_hid_include_directories} )
list( APPEND shake_hid_link_libraries
    "glfw"
    "shake_core"
)
target_link_libraries( shake_hid PRIVATE ${shake_hid_link_libraries} )
set_target_properties(
    shake_hid
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_io

file( GLOB_RECURSE shake_io_glob_files "C:/Users/Berry/Documents/development/shake3/shake_io//src//*" )
add_library( shake_io SHARED ${shake_io_glob_files} )
list( APPEND shake_io_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_io//src/"
    "C:/Users/Berry/Documents/development/shake3/external//json11/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
)
target_include_directories( shake_io PRIVATE ${shake_io_include_directories} )
list( APPEND shake_io_link_libraries
    "json11"
    "shake_core"
)
target_link_libraries( shake_io PRIVATE ${shake_io_link_libraries} )
set_target_properties(
    shake_io
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


# ----------------------------------------------------------------
# New Target: shake_main

file( GLOB_RECURSE shake_main_glob_files "C:/Users/Berry/Documents/development/shake3/shake_main//src//*" )
add_executable( shake_main ${shake_main_glob_files} )
list( APPEND shake_main_include_directories
    "C:/Users/Berry/Documents/development/shake3/shake_main//src/"
    "C:/Users/Berry/Documents/development/shake3/external//glm/"
    "C:/Users/Berry/Documents/development/shake3/external//json11/"
    "C:/Users/Berry/Documents/development/shake3/shake_content//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_core//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_ecs//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_graphics//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_hid//src/"
    "C:/Users/Berry/Documents/development/shake3/shake_io//src/"
)
target_include_directories( shake_main PRIVATE ${shake_main_include_directories} )
list( APPEND shake_main_link_libraries
    "json11"
    "shake_content"
    "shake_core"
    "shake_ecs"
    "shake_graphics"
    "shake_hid"
    "shake_io"
)
target_link_libraries( shake_main PRIVATE ${shake_main_link_libraries} )
set_target_properties(
    shake_main
    PROPERTIES
        CXX_STANDARD 20
        UNITY_BUILD OFF
)


