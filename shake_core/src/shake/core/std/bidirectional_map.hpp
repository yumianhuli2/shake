#ifndef BIMAP_HPP
#define BIMAP_HPP

#include <map>

namespace shake {

//----------------------------------------------------------------
template<typename Left_T, typename Right_T>
class BidirectionalMap
{
public:
    using left_type     = Left_T;
    using right_type    = Right_T;
    using pair_type     = std::pair<const left_type, const right_type>;

public:
    BidirectionalMap() { }
    BidirectionalMap( std::initializer_list<pair_type> list )           { for (const auto& pair : list ) { insert( pair ); } }

          void      insert      (const pair_type v)                     { m_l_to_r.insert(v); m_r_to_l.insert( std::pair{ v.second, v.first } ); }

          right_type&  left_at     (const left_type& key)               { return m_l_to_r.at(key); }
    const right_type&  left_at     (const left_type& key)     const     { return m_l_to_r.at(key); }

          left_type&   right_at    (const right_type& key)              { return m_r_to_l.at(key); }
    const left_type&   right_at    (const right_type& key)    const     { return m_r_to_l.at(key); }

private:
    std::map<left_type, right_type>   m_l_to_r;
    std::map<right_type, left_type>   m_r_to_l;
};

} // namespace shake

#endif // BIMAP_HPP
