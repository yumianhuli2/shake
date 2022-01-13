#ifndef MACRO_DEFINE_MAPPING_HPP
#define MACRO_DEFINE_MAPPING_HPP

//----------------------------------------------------------------
#define DEFINE_MAPPING( type_to, function_name, type_from, ... ) \
inline type_to function_name ( const type_from value ) \
{ \
    return Map<type_from, type_to> \
    { \
        __VA_ARGS__ \
    } \
    .at( value ); \
}

#endif // MACRO_DEFINE_MAPPING_HPP