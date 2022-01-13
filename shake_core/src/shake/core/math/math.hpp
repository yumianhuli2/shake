#ifndef MATH_HPP
#define MATH_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>

#include <algorithm>
#include <numeric>
#include <array>
#include <vector>

#include "shake/core/contracts/contracts.hpp"
#include "shake/core/log.hpp"

namespace shake {
namespace math {

constexpr double pi_d = 3.141592653589793238463;
constexpr float  pi_f = 3.14159265358979f;

namespace axis {

const glm::vec3 x = glm::vec3{  1.f,  0.f,  0.f };
const glm::vec3 y = glm::vec3{  0.f,  1.f,  0.f };
const glm::vec3 z = glm::vec3{  0.f,  0.f,  1.f };

} // namespace axis

//----------------------------------------------------------------
template<typename T1, typename T2>
inline
bool is_divisible_by( const T1 t1, const T2 t2 )
{
    return t1 % t2 == 0;
}

//----------------------------------------------------------------
using float_selector = const float&(*)(const float&, const float&);

template<typename T> inline
T el_wise_f( const float_selector& f, const T& lhs, const T& rhs );

template<> inline
glm::vec2 el_wise_f( const float_selector& f, const glm::vec2& lhs, const glm::vec2& rhs )
{
    auto result = glm::vec2{};
    result.x = f( lhs.x, rhs.x );
    result.y = f( lhs.y, rhs.y );
    return result;
}

template<> inline
glm::vec3 el_wise_f( const float_selector& f, const glm::vec3& lhs, const glm::vec3& rhs )
{
    auto result = glm::vec3{};
    result.x = f( lhs.x, rhs.x );
    result.y = f( lhs.y, rhs.y );
    result.y = f( lhs.z, rhs.z );
    return result;
}

//----------------------------------------------------------------
inline
std::vector<float> convert_to_vector_of_floats( const std::vector<glm::vec2>& v )
{
    auto result = std::vector<float>{};
    for ( const auto& e : v )
    {
        result.emplace_back( e.x );
        result.emplace_back( e.y );
    }
    return result;
}

//----------------------------------------------------------------
inline
std::vector<float> convert_to_vector_of_floats( const std::vector<glm::vec3>& v )
{
    auto result = std::vector<float>{};
    for ( const auto& e : v )
    {
        result.emplace_back( e.x );
        result.emplace_back( e.y );
        result.emplace_back( e.z );
    }
    return result;
}

//----------------------------------------------------------------
inline
std::vector<glm::vec3> convert_to_vector_of_vec3( const std::vector<float>& v )
{
    CHECK_EQ( v.size() % 3, 0, "Vector siz emus tbe divisbible by 3." );
    auto result = std::vector<glm::vec3>{};
    for ( std::size_t index = 0; index < v.size(); index += 3 )
    {
        result.emplace_back
        (
            v[index + 0],
            v[index + 1],
            v[index + 2]
        );
    }
    return result;
}

//----------------------------------------------------------------
template <typename T> inline
bool points_within_range( const T* p, const T* begin, const T* end )
{
    return std::greater_equal<T*>()(p, begin) && std::less<T*>()(p, end);
}

//----------------------------------------------------------------
// can be replaced by std::clamp in c++17
template <typename T> inline
T clamp(const T& value, const T& min, const T& max)
{
    return std::max(min, std::min(value, max));
}

//----------------------------------------------------------------
template <typename T> inline
bool is_even( const T& t )
{
    return t % 2 == 0;
}

template <typename T> inline
bool is_odd( const T& t )
{
    return !is_even( t );
}

//----------------------------------------------------------------
template <typename T> inline
bool is_between(const T& value, const T& min, const T& max)
{
    return ( value >= min ) && ( value <= max );
}

//----------------------------------------------------------------
template<typename T> inline
std::vector<T> integer_sequence(const size_t& size)
{
    std::vector<T> result ( size );
    std::iota(std::begin(result), std::end(result), 0);
    return result;
}

} // namespace math
} // namespace shake

#endif // MATH_HPP
