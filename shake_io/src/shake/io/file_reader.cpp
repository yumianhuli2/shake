#include "file_reader.hpp"

#include <vector>

#include "shake/core/contracts/contracts.hpp"

namespace shake {
namespace io {

//----------------------------------------------------------------
FileReader::FileReader(const Path& path)
    : m_file_stream { path.get_string().c_str(), std::ifstream::ate | std::ifstream::binary }
    , m_position { 0 }
{
    CHECK(m_file_stream.is_open(), "File does not exists or is not accessible. " + path.get_string() );
    m_size = m_file_stream.tellg();
    m_file_stream.seekg(0, m_file_stream.beg);
    CHECK_GT(m_size, 2, "File is empty, did you forget to save? ");
}

//----------------------------------------------------------------
Path    FileReader::get_path()      const   { return m_path;        }
size_t  FileReader::get_position()  const   { return m_position;    }
size_t  FileReader::get_size()      const   { return m_size;        }

//----------------------------------------------------------------
ByteBuffer FileReader::read_bytes( const size_t count )
{
    EXPECT_LE( m_position + count, m_size, "Could not read the requested number of bytes." );

    auto buffer = ByteBuffer( count );
    m_file_stream.read( reinterpret_cast<char*>( buffer.data() ), count );
    m_position += count;
    return buffer;
}

//----------------------------------------------------------------
ByteBuffer FileReader::read_as_bytes()
{
    return read_bytes( m_size );
}

//----------------------------------------------------------------
std::string FileReader::read_as_string()
{
    return deserialize<std::string>( read_as_bytes() );
}
//----------------------------------------------------------------
void FileReader::advance( const size_t size )
{
    EXPECT_LE( m_position + size, m_size, "Could not advance the requested number of bytes." );
    m_file_stream.ignore( size );
    m_position += size;
}

} // namespace io
} // namespace shake
