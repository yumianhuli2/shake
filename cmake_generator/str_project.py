from typing import List

from cmake_generator.cmake_format import cmake_format
from cmake_generator.project import Language
from cmake_generator.version import Version

#----------------------------------------------------------------
def str_project(
    project_name    : str,
    version         : Version,
    languages       : List[ Language ]
) -> str:
    set_project_template = (
        "# ----------------------------------------------------------------\n"
        "# Project: {SHAKE_CMAKE_GENERATOR_project_name}\n"
        "\n"
        "project( {SHAKE_CMAKE_GENERATOR_project_name} VERSION {SHAKE_CMAKE_GENERATOR_version_major}.{SHAKE_CMAKE_GENERATOR_version_minor} LANGUAGES {SHAKE_CMAKE_GENERATOR_languages} )\n"
        "\n"
    )

    languages_str = languages[0].value
    for current_language in languages[1:]:
        languages_str += " " + current_language.value

    set_project_str = cmake_format(
        set_project_template,
        project_name    = project_name,
        version_major   = version.major,
        version_minor   = version.minor,
        languages       = languages_str
    )
    return set_project_str