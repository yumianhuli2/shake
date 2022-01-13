from enum import auto, Enum
from typing import List, NamedTuple

from cmake_generator.version import Version

# ----------------------------------------------------------------
class Language( Enum ) :
    CXX     = "CXX"
    C       = "C"
    CUDA    = "CUDA"

#----------------------------------------------------------------
class Project( NamedTuple ):
    project_name                        : str
    version                             : Version
    target_definition_file_paths        : List[ str ]
    destination_cmake_lists_file_path   : str
    build_directory_path                : str
    languages                           : List[ Language ]

