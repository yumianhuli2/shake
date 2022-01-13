#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "shake/core/std/string.hpp"

#include <vector>

namespace shake {
namespace io {

//----------------------------------------------------------------
using ByteBuffer = std::vector<uint8_t>;

//----------------------------------------------------------------
template< typename T >
inline ByteBuffer serialize( const T& data )
{
    static_assert( std::is_pod<T>::value, "T must be a POD." );

    auto p_source = static_cast<uint8_t*>( &data );
    const auto n_bytes = sizeof( T );
    auto bytes = ByteBuffer( n_bytes );
    bytes.insert( std::end( bytes ), p_source, p_source + n_bytes );
    return bytes;
}

//----------------------------------------------------------------
template< typename T >
inline T deserialize( const ByteBuffer& bytes )
{
    static_assert( std::is_pod<T>::value, "T must be a POD." );

    const auto p_t = reinterpret_cast<const T*>( bytes.data() );
    const auto result = T{ *p_t };
    return result;
}

//----------------------------------------------------------------
template<>
inline std::string deserialize<std::string>( const ByteBuffer& bytes )
{
    return std::string( std::begin( bytes ), std::end( bytes ) );
}

} // namespace io
} // namespace shake

#endif // SERIALIZE_HPP
