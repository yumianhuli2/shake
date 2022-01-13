#ifndef ARRAY_2D_HPP
#define ARRAY_2D_HPP

#include <array>

namespace shake {

template < typename T, size_t width, size_t height >
class Array2D
{
public:
    inline void set ( const size_t x, const size_t y, const T& t )
    {
        m_array[ get_index( x, y ) ] = t;
    }

    inline const T& get ( const size_t x, const size_t y ) const
    {
        return m_array[ get_index( x, y ) ];
    }

    inline T& get ( const size_t x, const size_t y )
    {
        return m_array[ get_index( x, y ) ];
    }

private:
    inline size_t get_index( const size_t x, const size_t y ) const
    {
        return x + ( y * width );
    }

private:
    std::array< T, width * height> m_array;
};

} // namespace shake

#endif // ARRAY2_HPP
