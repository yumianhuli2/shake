from cmake_generator import Project, Version

# ----------------------------------------------------------------
def get_project_definition() -> Project:
    return Project(
        project_name = "shake",
        version = Version( 4, 0 ),
        destination_cmake_lists_file_path = "./CMakeLists.txt",
        build_directory_path = "./build",
        target_definitions_directory_paths = [
            "./external/",
            "./shake_content/",
            "./shake_core/",
            "./shake_ecs/",
            "./shake_graphics/",
            "./shake_hid/",
            "./shake_io/",
            "./shake_main/",
        ],
    )