#ifndef TYPE_ERASED_MAP_HPP
#define TYPE_ERASED_MAP_HPP

#include <any>

#include "shake/core/std/type_key_map.hpp"

namespace shake {

//----------------------------------------------------------------
class TypeErasedMap
{
public:
    using inner_map         = TypeKeyMap<std::any>;
    using iterator          = typename inner_map::iterator;
    using const_iterator    = typename inner_map::const_iterator;

public:

    template<typename Key_T>
    void emplace( const Key_T& value )
    {
        m_map.emplace<Key_T>( std::any{ value } );
    }

    template<typename Key_T>
    void try_emplace( const Key_T& value )
    {
        m_map.try_emplace<Key_T>( std::any{ value } );
    }

    template<typename Key_T>
    Key_T& at()
    {
        return std::any_cast<Key_T&>( m_map.at<Key_T>() );
    }

    template<typename Key_T>
    const Key_T& at() const
    {
        return std::any_cast<const Key_T&>( m_map.at<Key_T>() );
    }

    iterator        begin()         { return std::begin( m_map ); }
    const_iterator  begin() const   { return std::begin( m_map ); }
    iterator        end()           { return std::end( m_map );   }
    const_iterator  end()   const   { return std::end( m_map );   }

    template<typename Key_T>
    iterator find()
    {
        return m_map.find( type_id::get<Key_T>() );
    }

    template<typename Key_T>
    const_iterator find() const
    {
        return m_map.find( type_id::get<Key_T>() );
    }

    void erase( iterator it )
    {
        m_map.erase( it );
    }

    void clear() noexcept { m_map.clear(); }

    typename inner_map::inner_map& get_inner_map()
    {
        return m_map.get_inner_map();
    }

    const typename inner_map::inner_map& get_inner_map() const
    {
        return m_map.get_inner_map();
    }

private:
    inner_map m_map;
};

} // namespace shake

#endif // TYPE_ERASED_MAP_HPP
