#ifndef FILE_HPP
#define FILE_HPP

#include "shake/io/path.hpp"
#include "shake/io/serialize.hpp"

namespace shake {
namespace io    {
namespace file  {

bool            exists          ( const Path& path );
std::string     read_as_string  ( const Path& path );
ByteBuffer      read_as_bytes   ( const Path& path );

} // namespace file
} // namespace io
} // namespace shake

#endif // FILE_HPP
