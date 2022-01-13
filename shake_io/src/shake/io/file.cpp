#include "file.hpp"

#include <fstream>

#include "shake/core/contracts/contracts.hpp"

#include "shake/io/file_reader.hpp"

namespace shake {
namespace io    {
namespace file  {

//----------------------------------------------------------------
bool exists( const Path& path )
{
    std::ifstream file_stream { path.get_string() };
    return file_stream.is_open();
    // destructor will close the stream if required
}

//----------------------------------------------------------------
std::string read_as_string( const Path& path )
{
    FileReader file_reader { path };
    return file_reader.read_as_string();
}

//----------------------------------------------------------------
ByteBuffer read_as_bytes( const Path& path )
{
    FileReader file_reader { path };
    return file_reader.read_as_bytes();
}

} // namespace file
} // namespace io
} // namespace shake
