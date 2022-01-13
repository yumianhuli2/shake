#ifndef ARRAY_3D_HPP
#define ARRAY_3D_HPP

#include <array>

namespace shake {

template < typename T, size_t width, size_t height, size_t depth >
class Array3D
{
public:
    inline void set ( const size_t x, const size_t y, const size_t z, const T& t )
    {
        m_array[ get_index( x, y, z ) ] = t;
    }

    inline const T& get ( const size_t x, const size_t y, const size_t z ) const
    {
        return m_array[ get_index( x, y, z ) ];
    }

    inline T& get ( const size_t x, const size_t y, const size_t z )
    {
        return m_array[ get_index( x, y, z ) ];
    }

private:
    inline size_t get_index( const size_t x, const size_t y, const size_t z ) const
    {
        return x + ( y * width ) + ( z * ( width * height ) );
    }

private:
    std::array< T, width * height * depth > m_array;
};

} // namespace shake

#endif // ARRAY_3D_HPP
