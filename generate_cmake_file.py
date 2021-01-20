import logging

from cmake_generator import Project, Version, absp, generate_cmake_file

# ----------------------------------------------------------------
def main():
    target_definition_file_paths = [
        absp( path ) + "/target_definitions.py" for path in [
            "./external/",
            "./shake_content/",
            "./shake_core/",
            "./shake_ecs/",
            "./shake_graphics/",
            "./shake_hid/",
            "./shake_io/",
            "./shake_main/",
            "./shake_python/",
        ]
    ]

    cmake_project_definition = Project(
        project_name                        = "shake",
        version                             = Version( 4, 0 ),
        destination_cmake_lists_file_path   = absp( "./CMakeLists.txt" ),
        build_directory_path                = absp( "./build/" ),
        target_definition_file_paths        = target_definition_file_paths
    )

    generate_cmake_file( cmake_project_definition )

# ----------------------------------------------------------------
if __name__ == "__main__":
    logging.basicConfig( level = logging.INFO )
    main()
