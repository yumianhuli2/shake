#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <vector>

namespace shake {

template< typename T >
std::size_t get_size_in_bytes( const std::vector< typename T >& v )
{
    return sizeof( T ) * v.size();
}

} // namespace shake

#endif // VECTOR_HPP