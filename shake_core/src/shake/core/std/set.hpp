#ifndef SET_HPP
#define SET_HPP

#include <set>

#include "shake/core/contracts/contracts.hpp"

namespace shake {
namespace set {

//----------------------------------------------------------------
template<typename Key_T>
inline bool has ( const std::set<Key_T>& set, const Key_T& key )
{
    const auto it = set.find( key );
    return it != std::end( set );
}

//----------------------------------------------------------------
template<typename Key_T>
inline void check_has ( const std::set<Key_T>& set, const Key_T& key )
{
    const std::string message { "Set does not have expected key" };
    CHECK( has( set, key ), message );
}

//----------------------------------------------------------------
template<typename Key_T>
inline void check_not_has ( const std::set<Key_T>& set, const Key_T& key )
{
    const std::string message { "Set has unexpected key" };
    CHECK( !has( set, key ), message );
}

} // namespace set
} // namespace shake

#endif // SET_HPP
