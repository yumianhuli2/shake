#ifndef DUAL_KEY_MAP_HPP
#define DUAL_KEY_MAP_HPP

#include <map>
#include <tuple>

namespace shake {

//----------------------------------------------------------------
template<typename Key_1_T, typename Key_2_T, typename Value_T>
class DualKeyMap
{
public:
    using key_type_1 = Key_1_T;
    using key_type_2 = Key_2_T;
    using value_type = Value_T;
    using tuple_type = std::tuple<const Key_1_T, const Key_2_T, const Value_T>;
    using map_1_type = std::map<key_type_1, value_type>;
    using map_2_type = std::map<key_type_2, value_type>;

public:
    DualKeyMap() { }
    DualKeyMap( std::initializer_list<tuple_type> list ) { for (const auto& pair : list ) { insert( pair ); } }

    void insert (const tuple_type v)
    {
        m_map_1.insert( std::pair<key_type_1, value_type> { std::get<0>(v), std::get<2>(v) } );
        m_map_2.insert( std::pair<key_type_2, value_type> { std::get<1>(v), std::get<2>(v) } );
    }

          value_type& at_map_1 (const key_type_1& key)       { return m_map_1.at(key); }
    const value_type& at_map_1 (const key_type_1& key) const { return m_map_1.at(key); }

          value_type& at_map_2 (const key_type_2& key)       { return m_map_2.at(key); }
    const value_type& at_map_2 (const key_type_2& key) const { return m_map_2.at(key); }

    const map_1_type& inspect_map_1() const { return m_map_1; }
    const map_2_type& inspect_map_2() const { return m_map_2; }

private:
    map_1_type m_map_1;
    map_2_type m_map_2;
};

} // namespace shake

#endif // DUAL_KEY_MAP_HPP
