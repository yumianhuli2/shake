#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

#include <vector>

namespace shake {

template < typename T >
class Vector2D
{
public:
    Vector2D( const size_t width, const size_t height )
        : m_width   { width     }
        , m_height  { height    }
        , m_values  { std::vector<T>( width * height ) }
    { }

    inline void set ( const size_t x, const size_t y, const T& t )
    {
        m_values.at( get_index( x, y ) ) = t;
    }

    inline const T& get ( const size_t x, const size_t y ) const
    {
        return m_values.at( get_index( x, y ) );
    }

    inline T& get ( const size_t x, const size_t y )
    {
        return m_values.at( get_index( x, y ) );
    }

private:
    inline size_t get_index( const size_t x, const size_t y ) const
    {
        return x + ( y * m_width );
    }

private:
    const size_t m_width;
    const size_t m_height;

    std::vector<T> m_values;
};

} // namespace shake

#endif // VECTOR_2D_HPP
