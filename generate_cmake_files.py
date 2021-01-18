import os
from pathlib import Path
import runpy
from typing import Any, Dict, List

from cmake_generator import CMakeGenerator, Target

# ----------------------------------------------------------------
def fix_path( path : str ) :
    return Path( __file__ ).resolve().parent / Path( path )

# ----------------------------------------------------------------
def load_python_file_as_module( path_to_file : str ) -> Dict[ str, Any ]:
    module = runpy.run_path( os.path.abspath( path_to_file ) )
    return module

# ----------------------------------------------------------------
def gather_target_definitions( target_definitions_directory_paths : List[ str ] ) -> List[ Target ]:
    target_definitions = []
    for target_definitions_directory_path in target_definitions_directory_paths:
        module_path = fix_path( target_definitions_directory_path ) / 'target_definitions.py'
        module = load_python_file_as_module( module_path )
        module_target_definitions = module[ 'get_target_definitions' ]()
        target_definitions.extend( module_target_definitions )
    return target_definitions

# ----------------------------------------------------------------
def generate_cmake_file() -> None:
    project_definition_module = load_python_file_as_module( "./cmake_project_definition.py" )
    cmake_project_definition = project_definition_module[ "get_project_definition" ]()
    target_specifications = gather_target_definitions( cmake_project_definition.target_definitions_directory_paths )
    cmake = CMakeGenerator(
        project_name            = cmake_project_definition.project_name,
        project_version         = cmake_project_definition.version,
        cmake_destination_path  = fix_path( cmake_project_definition.destination_cmake_lists_file_path ),
        build_dir               = fix_path( cmake_project_definition.build_directory_path )
    )
    cmake.generate( target_specifications )

# ----------------------------------------------------------------
if __name__ == "__main__":
    generate_cmake_file()