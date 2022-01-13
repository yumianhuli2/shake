#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <iostream>

#include "shake/core/macros/macro_debug_only.hpp"

namespace shake {
namespace log_detail {

//----------------------------------------------------------------
inline
void log (const std::string& message)
{
    std::cout << message << std::endl;
}

//----------------------------------------------------------------
inline
void log_if (const bool condition, const std::string& message)
{
    if ( condition ) { log( message ); }
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_eq (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs == rhs, message );
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_ne (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs != rhs, message );
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_le (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs <= rhs, message );
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_lt (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs < rhs, message );
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_ge (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs >= rhs, message );
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void log_if_gt (const LT& lhs, const RT& rhs, const std::string& message)
{
    log_if( lhs > rhs, message );
}

//----------------------------------------------------------------
template <typename T> inline
void log_if_null (const T& v, const std::string& message)
{
    log_if( v == nullptr, message );
}

//----------------------------------------------------------------
inline const std::string prefix_ffl
(
    const std::string&  file,
    const std::string&  function,
    const int           line,
    const std::string&  message
)
{
    auto result = std::string { "" };
    result += "[ File: " + file + ", Function: " + function + ", Line: " + std::to_string( line ) + " ] ";
    result += message;
    return result;
}

} // namespace log_detail
} // namespace shake

// Too bad macro's cannot define new macro's.
// That would have required a lot less typing...

#define LOG( message ) do { \
    shake::log_detail::log( shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF( condition, message ) do { \
    shake::log_detail::log_if( condition, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_EQ( lhs, rhs, message ) do { \
    shake::log_detail::log_if_eq( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_NE( lhs, rhs, message ) do { \
    shake::log_detail::log_if_ne( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_LE( lhs, rhs, message ) do { \
    shake::log_detail::log_if_le( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_LT( lhs, rhs, message ) do { \
    shake::log_detail::log_if_lt( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_GE( lhs, rhs, message ) do { \
    shake::log_detail::log_if_ge( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_GT( lhs, rhs, message ) do { \
    shake::log_detail::log_if_gt( lhs, rhs, shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#define LOG_IF_NULL  ( v, message )  do { \
    shake::log_detail::log_if_null( v,  shake::log_detail::prefix_ffl( __FILE__, __func__, __LINE__, message ) ); \
} while(0)

#endif // LOG_HPP
