from inspect import stack
from pathlib import Path

# ----------------------------------------------------------------
def abs_path_str_from_rel_to_this_file( path : str ) :
    caller_frame = stack()[1]
    caller_file_path = caller_frame.filename
    caller_directory = Path( caller_file_path ).parent
    full_path = caller_directory / path
    abs_path = full_path.resolve()
    abs_path_str = abs_path.as_posix()
    return abs_path_str