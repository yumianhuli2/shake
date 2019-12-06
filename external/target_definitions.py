from pathlib import Path
from typing import Any, Dict, List

from cmake_generator import Target, ImportTarget, HeaderOnlyTarget, NewTarget, TargetType

# ----------------------------------------------------------------
def get_target_definitions() -> List[ Target ] :

    def fix_relative_path( path ):
        return ( Path( __file__ ).resolve().parent / path ).as_posix()

    freetype = ImportTarget(
        name            = 'freetype',
        src_dir_path    = fix_relative_path( 'freetype-2.9/' ),
        include_dirs    = [ fix_relative_path( 'freetype-2.9/include/' ) ]
    )

    glad = NewTarget(
        name            = 'glad',
        target_type     = TargetType.StaticLibrary, # static since only shake_graphics uses it
        src_dir_path    = fix_relative_path( 'glad/src/' ),
        include_dirs    = [ fix_relative_path( 'glad/include/' ) ]
    )

    glfw = ImportTarget(
        name            = 'glfw',
        src_dir_path    = fix_relative_path( 'glfw/' ),
        include_dirs    = [ fix_relative_path( 'glfw/include/' ) ],
        pre_import_inline_cmake = """
set( BUILD_SHARED_LIBS ON )
option( GLFW_INSTALL			OFF )
option( GLFW_BUILD_DOCS			OFF )
option( GLFW_BUILD_EXAMPLES		OFF )
option( GLFW_BUILD_TESTS		OFF )
"""
    )

    glm = HeaderOnlyTarget(
        name            = 'glm',
        include_dirs    = [ fix_relative_path( 'glm/' ) ]
    )

    json11 = NewTarget(
        name            = 'json11',
        target_type     = TargetType.SharedLibrary, # shared because many shake modules use it
        src_dir_path    = fix_relative_path( 'json11/json11/' ),
        include_dirs    = [ fix_relative_path( 'json11/' ) ]
    )

    pybind11 = ImportTarget(
        name            = 'pybind11',
        subtargets      = [ 'pybind11', '${PYTHON_LIBRARIES}' ],
        src_dir_path    = fix_relative_path( 'pybind11-2.2.3/' ),
        include_dirs    = [ '${PYBIND11_INCLUDE_DIR}', '${PYTHON_INCLUDE_DIRS}' ],
        pre_import_inline_cmake = """
set( PYBIND11_CPP_STANDARD -std=c++17 )        
"""
    )

    stb = HeaderOnlyTarget(
        name            = 'stb',
        include_dirs    = [ fix_relative_path( 'stb/' ) ]
    )

    return [
        freetype,
        glad,
        glfw,
        glm,
        json11,
        pybind11,
        stb
    ]
