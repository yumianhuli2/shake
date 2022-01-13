#ifndef UNDERLYING_CAST_HPP
#define UNDERLYING_CAST_HPP

#include <type_traits>

namespace shake {

//----------------------------------------------------------------
// Used to cast enums to their underlying type,
// without having to look up what the underlying type is.
template<typename T>
typename std::underlying_type<T>::type underlying_cast( T t )
{
    using underlying_type = typename std::underlying_type<T>::type;
    return static_cast<underlying_type>( t );
}

} // namespace shake

#endif // UNDERLYING_CAST_HPP
