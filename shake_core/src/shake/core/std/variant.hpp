#ifndef VARIANT_HPP
#define VARIANT_HPP

#include <variant>

namespace shake {

//----------------------------------------------------------------
// Implementation copied from https://en.cppreference.com/w/cpp/utility/variant/visit
// Replaced class with typename.
// Added comments are mine. 

// A struct that inherits form the lamdas to bring their operator() in scope
template< typename... Lambda_Ts > struct visitor : Ts... { using Lambda_Ts::operator()...; };

// A user defined deduction guide for class template argument deduction.
// Basically it tells the compiler what the result type of a visitor constructor call should look like
template< typename... Lambda_Ts > visitor( Lambda_Ts... ) -> visitor< Lambda_Ts... >;

} // namespace shake

#endif // VARIANT_HPP