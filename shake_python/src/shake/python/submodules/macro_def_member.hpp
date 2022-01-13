#ifndef MACRO_DEF_MEMBER_HPP
#define MACRO_DEF_MEMBER_HPP

//----------------------------------------------------------------
#define DEF_ENUM( module_to_add_to, enum_to_add ) \
    pybind11::enum_< enum_to_add >( module_to_add_to, #enum_to_add )

//----------------------------------------------------------------
#define DEF_VALUE( enum_name, value_to_add ) \
    .value( #value_to_add, enum_name::value_to_add )

//----------------------------------------------------------------
// Okat this is super hacky....
// By default, objects will be wrapped in a unique pointer, 
// However, it is impossible for python to transfer ownership to c++,
// when passing a unique pointer to c++.
// Therefore, for classes that could be managed by both c++ and Python,
// it is better to use a shared pointer as the holder type.
// Because most of our classes should be able to be transferred between the two languages, 
// I'd rather have shared pointers by default,
// instead of having to make a per-class consideration on this issue. 
// If this turns out to be a performance issue later, 
// we can always change it back. 
// For now the performance hit is negligible, while the joy of programming increases a lot. 

#define DEF_CLASS( module_to_add_to, class_to_add ) \
    pybind11::class_< class_to_add, std::shared_ptr<class_to_add>>( module_to_add_to, #class_to_add )

#define DEF_CLASS_NAMED( module_to_add_to, class_to_add, classname ) \
    pybind11::class_< class_to_add, std::shared_ptr<class_to_add>>( module_to_add_to, classname )

#define DEF_SUBCLASS( module_to_add_to, class_to_add, super_class ) \
    pybind11::class_< class_to_add, super_class, std::shared_ptr<class_to_add> >( module_to_add_to, #class_to_add )

//----------------------------------------------------------------
#define DEF_CTOR( ... ) \
    .def( pybind11::init<__VA_ARGS__>() )

//----------------------------------------------------------------
// Use this to disambiguate between overloads

// Use this version if no overloads exist
#define DEF_MEMBER( classname, member_name ) \
    .def( #member_name, &classname::member_name )

#define DEF_PROPERTY_RW( classname, member_name, /* member_argument_types */ ... ) \
    .def( #member_name, pybind11::overload_cast<__VA_ARGS__>( &classname::member_name ),                    pybind11::return_value_policy::reference ) \
    .def( #member_name, pybind11::overload_cast<__VA_ARGS__>( &classname::member_name, pybind11::const_ ),  pybind11::return_value_policy::reference )


// Use this version to disambiguate overloads based on arguments
#define DEF_MEMBER_OVERLOAD( classname, member_name, /* member_argument_types */ ... ) \
    .def( #member_name, pybind11::overload_cast<__VA_ARGS__>( &classname::member_name ) )

// Use this version to disambiguate overloads based on constness
#define DEF_MEMBER_OVERLOAD_CONST( classname, member_name, /* member_argument_types */ ... ) \
    .def( #member_name, pybind11::overload_cast<__VA_ARGS__>( &classname::member_name, pybind11::const_ ) )

//----------------------------------------------------------------
// Use with template functions, unless you can disamiguate on parameters alone! Then use the above!
// The template type will be postfixed to the name of the function.

// Use this version if no overloads exist
#define DEF_TEMPLATE_MEMBER( classname, member_name, template_type ) \
    .def( ( std::string( #member_name ) + "__" + #template_type ).c_str(), &classname::member_name<template_type> )

// Use this version to disambiguate overloads based on arguments
#define DEF_TEMPLATE_MEMBER_OVERLOAD( classname, member_name, template_type, ... ) \
    .def( ( std::string( #member_name ) + "__" + #template_type ).c_str(), \
    pybind11::overload_cast<__VA_ARGS__>( &classname::member_name<template_type> ) )

// Use this version to disambiguate overloads based on constness
#define DEF_TEMPLATE_MEMBER_OVERLOAD_CONST( classname, member_name, template_type, ... ) \
    .def( ( std::string( #member_name ) + "__" + #template_type ).c_str(), \
    pybind11::overload_cast<__VA_ARGS__>( &classname::member_name<template_type>, pybind11::const_ ) )

#endif // MACRO_DEF_MEMBER_HPP
