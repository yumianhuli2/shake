from enum import auto, Enum

#----------------------------------------------------------------
class NewTargetType( Enum ):
    Executable          = auto()
    SharedLibrary       = auto()
    StaticLibrary       = auto()
    PythonModule        = auto()