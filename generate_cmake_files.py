import os
import logging
import runpy
from typing import Any, Dict, List

from cmake_generator import CMakeGenerator, Target, abs_path_str_from_rel_to_this_file

# ----------------------------------------------------------------
def load_python_file_as_module( path_to_file : str ) -> Dict[ str, Any ]:
    module = runpy.run_path( os.path.abspath( path_to_file ) )
    return module

# ----------------------------------------------------------------
def gather_target_definitions( target_definitions_directory_paths : List[ str ] ) -> List[ Target ]:
    target_definitions = []
    for target_definitions_directory_path in target_definitions_directory_paths:
        module_path = target_definitions_directory_path
        module = load_python_file_as_module( module_path )
        module_target_definitions = module[ 'get_target_definitions' ]()
        target_definitions.extend( module_target_definitions )
    return target_definitions

# ----------------------------------------------------------------
def generate_cmake_file() -> None:
    project_definition_file_path = abs_path_str_from_rel_to_this_file( "./cmake_project_definition.py" )
    project_definition_module = load_python_file_as_module( project_definition_file_path )
    cmake_project_definition = project_definition_module[ "get_project_definition" ]()
    target_specifications = gather_target_definitions( cmake_project_definition.target_definition_file_paths )
    cmake = CMakeGenerator(
        project_name            = cmake_project_definition.project_name,
        project_version         = cmake_project_definition.version,
        cmake_destination_path  = cmake_project_definition.destination_cmake_lists_file_path,
        build_dir               = cmake_project_definition.build_directory_path
    )
    cmake.generate( target_specifications )

# ----------------------------------------------------------------
if __name__ == "__main__":
    logging.basicConfig( level = logging.INFO )
    generate_cmake_file()