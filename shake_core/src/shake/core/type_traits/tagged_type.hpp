#ifndef TAGGED_TYPE_HPP
#define TAGGED_TYPE_HPP

#include "shake/core/macros/macro_property.hpp"

namespace shake {

//----------------------------------------------------------------
// Used to create strongly typed aliases.
// Simply create a tag type like struct FooTag { };
// and use it to tag an already existing type, to avoid accidental mixups
template<typename Value_T, typename Tag_T>
class tagged_type
{
public:
    using value_type        = Value_T;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using tag_type          = Tag_T;
    using ptr               = value_type*;
    using const_ptr         = const value_type*;

public:
    explicit tagged_type( const Value_T& value )
        : m_value { value }
    { }

          reference operator*()             { return m_value;   }
    const_reference operator*()     const   { return m_value;   }

          ptr       operator->()            { return &m_value;  }
    const_ptr       operator->()    const   { return &m_value;  }

          ptr       operator&()             { return &m_value;  }
    const_ptr       operator&()     const   { return &m_value;  }

private:
    value_type m_value;
};

//----------------------------------------------------------------
template<typename Value_T, typename Tag_T>
bool operator == ( const tagged_type<Value_T, Tag_T>& lhs, const tagged_type<Value_T, Tag_T>& rhs)
{
    return *lhs == *rhs;
}

//----------------------------------------------------------------
template<typename Value_T, typename Tag_T>
bool operator != ( const tagged_type<Value_T, Tag_T>& lhs, const tagged_type<Value_T, Tag_T>& rhs)
{
    return *lhs != *rhs;
}


//----------------------------------------------------------------
template<typename Value_T, typename Tag_T>
bool operator < ( const tagged_type<Value_T, Tag_T>& lhs, const tagged_type<Value_T, Tag_T>& rhs)
{
    return *lhs < *rhs;
}

} // namespace shake

#endif // TAGGED_TYPE_HPP
