#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include "shake/core/math/math.hpp"

namespace shake {
namespace coordinates {

//----------------------------------------------------------------
inline
float convert_degrees_to_radians( const float degrees )
{
    return degrees * ( math::pi_f / 180.f );
}

//----------------------------------------------------------------
inline
float convert_radians_to_degrees( const float radians )
{
    return radians * ( 180.f / math::pi_f );
}

//----------------------------------------------------------------
inline
glm::vec2 convert_cartesian_to_polar( const float x, const float y )
{
    auto r = std::sqrt( std::pow( x, 2 ) + std::pow( y, 2 ) );
    auto a = std::atan( x / y );
    return { r, a };
}

//----------------------------------------------------------------
inline
glm::vec2 convert_cartesian_to_polar( const glm::vec2& cartesian )
{
    return convert_cartesian_to_polar( cartesian.x, cartesian.y );
}

//----------------------------------------------------------------
inline
glm::vec2 convert_polar_to_cartesian( const float radius, const float angle )
{
    auto x = std::cos( angle ) * radius;
    auto y = std::sin( angle ) * radius;
    return { x, y };
}

//----------------------------------------------------------------
inline
glm::vec2 convert_polar_to_cartesian( const glm::vec2& polar )
{
    return convert_polar_to_cartesian( polar.x, polar.y );
}

} // namespace coordinates
} // namespace shake


#endif // COORDINATES_HPP
