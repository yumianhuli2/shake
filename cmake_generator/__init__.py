from cmake_generator.generate_cmake_file import generate_cmake_file

from cmake_generator.path import abs_path_str_from_rel_to_this_file
absp = abs_path_str_from_rel_to_this_file # alias

from cmake_generator.project import Language, Project

from cmake_generator.target import (
    Executable,
    HeaderOnlyLibrary,
    ImportTarget,
    PythonModule,
    SharedLibrary,
    StaticLibrary,
    Target
)

from cmake_generator.target_type import NewTargetType

from cmake_generator.version import Version