#include "file_json.hpp"

#include "shake/core/contracts/contracts.hpp"

#include "shake/io/file.hpp"

namespace shake {
namespace io    {
namespace file  {
namespace json  {

//----------------------------------------------------------------
Json read(const Path& path)
{
    CHECK( file::exists(path), "json file does not exist. " + path.get_string() );
    CHECK(path.has_file_extension(".json"), "Provided path does not specify a .json file.");
    std::string json_string { file::read_as_string( path ) };
    std::string parse_error { };
    Json json { Json::parse(json_string.c_str(), parse_error, JsonParse::COMMENTS) };
    CHECK(parse_error.empty(), "Could not parse json file. " + parse_error);
    CHECK(!json.is_null(), "Could not parse json file. Object is empty.");
    return json;
}

} // namespace json
} // namespace file
} // namespace io
} // namespace shake
