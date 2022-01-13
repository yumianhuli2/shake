#ifndef TYPE_KEY_MAP_HPP
#define TYPE_KEY_MAP_HPP

#include <unordered_map>

#include "shake/core/type_traits/type_id.hpp"

namespace shake {

//----------------------------------------------------------------
template<typename Value_T>
class TypeKeyMap
{
public:
    using key_type          = type_id::TypeId;
    using value_type        = Value_T;
    using inner_map         = std::unordered_map<key_type, value_type>;
    using iterator          = typename inner_map::iterator;
    using const_iterator    = typename inner_map::const_iterator;

public:

    template<typename Key_T>
    void emplace( const value_type& value )
    {
        m_map.emplace( type_id::get<Key_T>(), value );
    }

    template<typename Key_T>
    void try_emplace( const Key_T& value )
    {
        m_map.try_emplace( type_id::get<Key_T>(), value );
    }

    template<typename Key_T>
    Value_T& at()
    {
        return m_map.at( type_id::get<Key_T>() );
    }
    
    template<typename Key_T>
    const Value_T& at() const
    {
        return m_map.at( type_id::get<Key_T>() );
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

    inner_map& get_inner_map()
    {
        return m_map;
    }

    const inner_map& get_inner_map() const
    {
        return m_map;
    }


private:
    inner_map m_map;
};

} // namespace shake

#endif // TYPE_KEY_MAP_HPP
