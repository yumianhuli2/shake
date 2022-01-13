#ifndef BOUNDS_HPP
#define BOUNDS_HPP

#include <limits>

#include "core/math/math.hpp"

namespace shake {

template<typename T>
class Bounds_
{
public:

    static_assert
    (
        std::is_same( T, glm::vec2 )::value ||
        std::is_same( T, glm::vec3 )::value,
        "Template type for Bounds_ not supported"
    );

    Bounds_()
    {
        constexpr auto inf_f = std::numeric_limits<float>::infinity();
        m_min = T{  inf_f };
        m_max = T{ -inf_f };
    }

    Bounds_( const T& min, const T& max )
        : m_min{ min }
        , m_max{ max }
    { }

    inline
    const T& get_min() const { return m_min; }
          T& get_min()       { return m_min; }

    inline
    const T& get_max() const { return m_max; }
          T& get_max()       { return m_max; }

    inline
    void in_place_union( const T& p )
    {
        m_min = math::el_wise_f( std::min, p, m_min );
        m_max = math::el_wise_f( std::max, p, m_max );
    }

    inline
    void in_place_union( const Bounds_<T>& b )
    {
        Union( b.get_min() );
        Union( b.get_max() );
    }

    inline
    void in_place_intersect( const T& p )
    {
        m_min = math::el_wise_f( std::max, p, m_min );
        m_max = math::el_wise_f( std::min, p, m_max );
    }

    inline
    void in_place_intersect( const Bounds_<T>& b )
    {
        Intersect( b.get_min() );
        Intersect( b.get_max() );
    }

    inline
    bool is_valid() const
    {
        return m_min <= m_max;
    }

    inline
    bool has_inside( const T& p )
    {
        return has_inside( this, p );
    }

    inline
    bool has_inside( const Bounds_<T>& b )
    {
        return has_inside( b.get_min() ) && has_inside( b.get_max() );
    }

    inline
    float compute_volume() const
    {
        const auto diagonal = m_max - m_min;
        return diagonal.x * diagonal.y * diagonal.z;
    }

private:
    inline
    static bool has_inside( Bounds_<glm::vec2>& b, const glm::vec2& p )
    {
        return
            math::is_between( p.x, b.get_min().x, b.get_max().x ) &&
            math::is_between( p.y, b.get_min().y, b.get_max().y );
    }

    inline
    static bool has_inside( Bounds_<glm::vec3>& b, const glm::vec3& p )
    {
        return
            math::is_between( p.x, b.get_min().x, b.get_max().x ) &&
            math::is_between( p.y, b.get_min().y, b.get_max().y ) &&
            math::is_between( p.z, b.get_min().z, b.get_max().z );
    }

private:
    T m_min;
    T m_max;
};

using Bounds2 = Bounds_<glm::vec2>;
using Bounds3 = Bounds_<glm::vec3>;

} // namespace shake

#endif // BOUNDS_HPP
