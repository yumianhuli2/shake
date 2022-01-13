#ifndef MACRO_STRONGLY_TYPED_ALIAS_HPP
#define MACRO_STRONGLY_TYPED_ALIAS_HPP

#include "shake/core/type_traits/tagged_type.hpp"

//----------------------------------------------------------------
// Just a convenience macro that creates the tag type for you,
// and uses the tag to create a tagged type.
#define STRONGLY_TYPED_ALIAS( alias, base_type ) \
    struct alias##_Tag { }; \
    using alias = tagged_type<base_type, alias##_Tag>;

#endif // MACRO_STRONGLY_TYPED_ALIAS_HPP
