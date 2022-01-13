#ifndef HIERARCHICAL_CAST_HPP
#define HIERARCHICAL_CAST_HPP

#include "shake/core/std/string.hpp"

namespace shake {

//----------------------------------------------------------------
// Simple up cast, that clearly demonstrates intent.
// It also does some type checking to make sure the intended cast is valid.
template
<
    typename Base_T,
    typename Derived_T
>
inline Base_T up_cast( const Derived_T& v )
{
    static_assert( std::is_base_of<Base_T, Derived_T>::value, "The requested base class is not a base of the provided derived class." );
    return static_cast<Base_T>( v );
}

//----------------------------------------------------------------
// Down cast that clearly demonstrates intent.
// It is, however, only safe if v is indeed a Derived_T
// It also does some type checking to make sure the intended cast is valid.
template
<
    typename Derived_T,
    typename Base_T
>
inline Derived_T& unsafe_down_cast( Base_T& v )
{
    static_assert( std::is_base_of<Base_T, Derived_T>::value, "The requested derived class is not a derived from the provided base class." );
    return static_cast<Derived_T&>( v ); // static_cast for unsafe version, make this a dynamic_cast to make it safe
}

} // namespace shake

#endif // HIERARCHICAL_CAST_HPP
