from cmake_generator import Project, Version, abs_path_str_from_rel_to_this_file

# ----------------------------------------------------------------
def get_project_definition() -> Project:

    target_definition_file_paths = [
        ( abs_path_str_from_rel_to_this_file( path ) + "/target_definitions.py" ) for path in [
            "./external/",
            "./shake_content/",
            "./shake_core/",
            "./shake_ecs/",
            "./shake_graphics/",
            "./shake_hid/",
            "./shake_io/",
            "./shake_main/",
        ]
    ]

    return Project(
        project_name                        = "shake",
        version                             = Version( 4, 0 ),
        destination_cmake_lists_file_path   = abs_path_str_from_rel_to_this_file( "./CMakeLists.txt" ),
        build_directory_path                = abs_path_str_from_rel_to_this_file( "./build/" ),
        target_definition_file_paths        = target_definition_file_paths
    )