#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <fstream>

#include "shake/io/path.hpp"
#include "shake/io/serialize.hpp"

namespace shake {
namespace io {

class FileReader
{
public:
    FileReader(const Path& path);

    ByteBuffer read_bytes( const size_t count );

    //----------------------------------------------------------------
    template< typename T >
    T read( const size_t size = sizeof( T ) )
    {
        return deserialize<T>( read_bytes( size ) );
    }

    std::string read_as_string();
    ByteBuffer  read_as_bytes();

    void advance( const size_t size );

    Path        get_path()      const;
    size_t      get_size()      const;
    size_t      get_position()  const;

private:
    std::ifstream   m_file_stream;
    Path            m_path;
    size_t          m_size;
    size_t          m_position;
};

} // namespace io
} // namespace shake

#endif // FILE_READER_HPP
