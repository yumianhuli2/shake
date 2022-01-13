from collections.abc import Iterable
import logging
import runpy
from typing import Any, Dict, List

from cmake_generator.project            import Project
from cmake_generator.str_cmake_config   import str_cmake_config
from cmake_generator.str_import_target  import str_import_target
from cmake_generator.str_new_target     import str_new_target
from cmake_generator.str_project        import str_project
from cmake_generator.target             import ImportTarget, NewTarget, Target

# ----------------------------------------------------------------
def generate_cmake_file( cmake_project_definition : Project ) -> None:
    target_definitions = gather_target_definitions( cmake_project_definition.target_definition_file_paths )

    logging.info( "----------------------------------------------------------------" )
    logging.info( "Generating CMake text" )

    cmake_text = ""
    cmake_text += str_cmake_config( cmake_project_definition.build_directory_path )
    cmake_text += str_project( cmake_project_definition.project_name, cmake_project_definition.version, cmake_project_definition.languages )

    logging.info( "----------------------------------------------------------------" )
    logging.info( "Creating registry of targets" )
    target_dictionary = { }
    for target in target_definitions:
        target_dictionary.update( { target.name : target} )
        logging.info( "Added target to registry: {}".format( target.name ) )

    logging.info( "----------------------------------------------------------------" )
    logging.info( "Generating CMake output" )
    for target in target_definitions:
        dispatcher = {
            NewTarget : str_new_target,
            ImportTarget : str_import_target
        }
        # Note: we don't write a specific target for header only libraries
        # You'll see them back in the include directories of the targets that depend on them though
        if target.__class__ in dispatcher :
            cmake_text += dispatcher[ target.__class__ ]( target, target_dictionary ) + "\n"
        logging.info( "Added target to CMake text: {}".format( target.name ) )

    logging.info( "----------------------------------------------------------------" )
    logging.info( "Writing CMake text to: {}".format( cmake_project_definition.destination_cmake_lists_file_path ) )
    with open( cmake_project_definition.destination_cmake_lists_file_path, 'w' ) as file_writer:
        file_writer.write( cmake_text )
    logging.info( "Done!" )

# ----------------------------------------------------------------
def load_python_file_as_module( path_to_file : str ) -> Dict[ str, Any ]:
    module = runpy.run_path( path_to_file )
    return module

# ----------------------------------------------------------------
def gather_target_definitions( target_definitions_directory_paths : List[ str ] ) -> List[ Target ]:
    target_definitions = []
    for target_definitions_directory_path in target_definitions_directory_paths:
        module_path = target_definitions_directory_path
        module = load_python_file_as_module( module_path )
        module_target_definitions = module[ "get_target_definitions" ]()

        if isinstance( module_target_definitions, Iterable ):
            add = lambda target, source : target.extend( source )
        else:
            add = lambda target, source : target.append( source )
        add( target_definitions, module_target_definitions )

    return target_definitions