#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

#include <vector>

namespace shake {

template < typename T >
class Vector3D
{
public:
    Vector3D( const size_t width, const size_t height, const size_t depth )
        : m_width   { width     }
        , m_height  { height    }
        , m_depth   { depth     }
        , m_values  { std::vector<T>( width * height * depth ) }
    { }

    inline void set ( const size_t x, const size_t y, const size_t z, const T& t )
    {
        m_values.at( get_index( x, y, z ) ) = t;
    }

    inline const T& get ( const size_t x, const size_t y, const size_t z ) const
    {
        return m_values.at( get_index( x, y, z ) );
    }

    inline T& get ( const size_t x, const size_t y, const size_t z )
    {
        return m_values.at( get_index( x, y, z ) );
    }

private:
    inline size_t get_index( const size_t x, const size_t y, const size_t z ) const
    {
        return x + ( y * m_width ) + ( z * ( m_width * m_height ) );
    }

private:
    const size_t m_width;
    const size_t m_height;
    const size_t m_depth;

    std::vector<T> m_values;
};

} // namespace shake

#endif // VECTOR_3D_HPP
