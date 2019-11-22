from pathlib import Path
import runpy
from typing import Any, Dict, List

from cmake_generator import (
    CMakeGenerator,
    Target,
    Version
)

# ----------------------------------------------------------------
def fix_relative_path( path ) :
    return ( Path( __file__ ).resolve().parent / path ).as_posix()

# ----------------------------------------------------------------
def load_dynamic_file( path_to_file : str ) -> Dict[ str, Any ]:
    module = runpy.run_path( path_to_file )
    return module

# ----------------------------------------------------------------
def gather_target_definitions() -> List[ Target ]:
    directory_names = [
        'external',
        'shake_content',
        'shake_core',
        'shake_ecs',
        'shake_graphics',
        'shake_hid',
        'shake_io',
        'shake_main',
        'shake_python'
    ]
    target_definitions = []
    for directory_name in directory_names:
        module = load_dynamic_file( fix_relative_path( Path( directory_name ) / 'target_definitions.py' ) )
        module_target_definitions = module[ 'get_target_definitions' ]()
        target_definitions.extend( module_target_definitions )
    return target_definitions

# ----------------------------------------------------------------
def generate_cmake_file() -> None:
    target_specifications = gather_target_definitions()
    cmake = CMakeGenerator(
        project_name            = 'Shake3',
        project_version         = Version( 0, 1 ),
        cmake_destination_path  = fix_relative_path( 'CMakeLists.txt' ),
        build_dir               = fix_relative_path( 'build/' )
    )
    cmake.generate( target_specifications )

# ----------------------------------------------------------------
if __name__ == "__main__":
    generate_cmake_file()