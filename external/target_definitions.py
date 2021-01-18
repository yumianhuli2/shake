from pathlib import Path
from typing import Any, Dict, List

from cmake_generator import Target, ImportTarget, HeaderOnlyTarget, NewTarget, TargetType

# ----------------------------------------------------------------
def get_target_definitions() -> List[ Target ] :

    freetype = ImportTarget(
        name            = 'freetype',
        src_dir_path    = './freetype-2.9/',
        include_dirs    = [ './freetype-2.9/include/' ]
    )

    glad = NewTarget(
        name            = 'glad',
        target_type     = TargetType.StaticLibrary, # static since only shake_graphics uses it
        src_dir_path    = './glad/src/',
        include_dirs    = [ './glad/include/' ]
    )

    glfw = ImportTarget(
        name            = 'glfw',
        src_dir_path    = './glfw/',
        include_dirs    = [ './glfw/include/' ],
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
        include_dirs    = [ './glm/' ]
    )

    json11 = NewTarget(
        name            = 'json11',
        target_type     = TargetType.SharedLibrary, # shared because many shake modules use it
        src_dir_path    = './json11/json11/',
        include_dirs    = [ './json11/' ]
    )

    pybind11 = ImportTarget(
        name            = 'pybind11',
        subtargets      = [ 'pybind11', '${PYTHON_LIBRARIES}' ],
        src_dir_path    = './pybind11-2.2.3/',
        include_dirs    = [ '${PYBIND11_INCLUDE_DIR}', '${PYTHON_INCLUDE_DIRS}' ],
    )

    stb = HeaderOnlyTarget(
        name            = 'stb',
        include_dirs    = [ './stb/' ]
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