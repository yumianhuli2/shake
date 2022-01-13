from typing import Dict, List, Union

from cmake_generator.target_type import NewTargetType

#----------------------------------------------------------------
class HeaderOnlyLibrary:
    """
    For existing header only targets,
    we only need to include the correct directories
    """

    def __init__(
        self,
        name            : str,
        include_dirs    : List[ str ]
    ) :
        self.name           = name
        self.include_dirs   = include_dirs

#----------------------------------------------------------------
class NewTarget:
    """
    For new targets the rules are simple:
    A target can be one of [ header only, static, shared ]
    The cmake for this will be generated.

    The source is globbed recursively from the root src_dir_path.
    It is assumed that the include directories are exactly the same tree.
    """
    def __init__(
        self,
        name            : str,
        target_type     : NewTargetType,
        src_dir_path    : str,
        include_dirs    : List[ str ]       = None,
        dependencies    : List[ str ]       = None,
        properties      : Dict[ str, str ]  = None
    ):
        self.name           = name
        self.target_type    = target_type
        self.src_dir_path   = src_dir_path
        self.include_dirs   = include_dirs  or [ src_dir_path ]
        self.dependencies   = dependencies  or []
        self.properties     = properties    or {}

#----------------------------------------------------------------
def Executable(
    name            : str,
    src_dir_path    : str,
    include_dirs    : List[ str ]       = None,
    dependencies    : List[ str ]       = None,
    properties      : Dict[ str, str ]  = None
):
    return NewTarget(
        name            = name,
        target_type     = NewTargetType.Executable,
        src_dir_path    = src_dir_path,
        include_dirs    = include_dirs,
        dependencies    = dependencies,
        properties      = properties
    )

#----------------------------------------------------------------
def SharedLibrary(
    name            : str,
    src_dir_path    : str,
    include_dirs    : List[ str ]       = None,
    dependencies    : List[ str ]       = None,
    properties      : Dict[ str, str ]  = None
):
    return NewTarget(
        name            = name,
        target_type     = NewTargetType.SharedLibrary,
        src_dir_path    = src_dir_path,
        include_dirs    = include_dirs,
        dependencies    = dependencies,
        properties      = properties
    )

#----------------------------------------------------------------
def StaticLibrary(
    name            : str,
    src_dir_path    : str,
    include_dirs    : List[ str ]       = None,
    dependencies    : List[ str ]       = None,
    properties      : Dict[ str, str ]  = None
):
    return NewTarget(
        name            = name,
        target_type     = NewTargetType.StaticLibrary,
        src_dir_path    = src_dir_path,
        include_dirs    = include_dirs,
        dependencies    = dependencies,
        properties      = properties
    )

#----------------------------------------------------------------
def PythonModule(
    name            : str,
    src_dir_path    : str,
    include_dirs    : List[ str ]       = None,
    dependencies    : List[ str ]       = None,
    properties      : Dict[ str, str ]  = None
):
    return NewTarget(
        name            = name,
        target_type     = NewTargetType.PythonModule,
        src_dir_path    = src_dir_path,
        include_dirs    = include_dirs,
        dependencies    = dependencies,
        properties      = properties
    )

#----------------------------------------------------------------
class ImportTarget:
    """
    For existing targets we simply import their cmake script
    Because a single cmake script can create multiple targets,
    we need all their names and include directories specified.
    """
    def __init__(
        self,
        name                        : str,
        src_dir_path                : str,
        include_dirs                : List[ str ],
        pre_import_inline_cmake     : str           = '',
        post_import_inline_cmake    : str           = '',
        subtargets                  : List[ str ]   = None
    ) :
        self.name                       = name
        self.src_dir_path               = src_dir_path
        self.include_dirs               = include_dirs or [ src_dir_path + "include" ]
        self.pre_import_inline_cmake    = pre_import_inline_cmake
        self.post_import_inline_cmake   = post_import_inline_cmake
        self.subtargets                 = subtargets or [ name ]

#----------------------------------------------------------------
Target = Union[ HeaderOnlyLibrary, ImportTarget, NewTarget ]