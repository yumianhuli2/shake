#ifndef MACRO_GLOBAL_PROPERTY_HPP
#define MACRO_GLOBAL_PROPERTY_HPP

//----------------------------------------------------------------
#define DECLARE_GLOBAL_PROPERTY( type, var ) \
type& var();

//----------------------------------------------------------------
#define DEFINE_GLOBAL_PROPERTY( type, var ) \
namespace { \
    type var; \
} \
\
type& var() \
{ \
    return var; \
}

#endif // MACRO_GLOBAL_PROPERTY_HPP
