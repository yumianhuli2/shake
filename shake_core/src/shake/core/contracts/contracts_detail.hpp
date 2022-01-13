#ifndef CONTRACTS_DETAIL_HPP
#define CONTRACTS_DETAIL_HPP

#include <string>

#include "shake/core/log.hpp"
#include "shake/core/type_traits/lexical_cast.hpp"

namespace shake {
namespace contracts_detail {

//----------------------------------------------------------------
inline
void check(const bool condition, const std::string message)
{
    if ( !condition )
    {
        LOG( message );
        std::abort();
    }
}

//----------------------------------------------------------------
inline
void check_fail(const std::string& message)
{
    check(false, message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_eq (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs == rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " == " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_ne (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs != rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " != " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_le (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs <= rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " <= " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_lt (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs < rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " < " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_ge (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs >= rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " >= " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename LT, typename RT> inline
void check_gt (const LT& lhs, const RT& rhs, const std::string& message)
{
    check(lhs > rhs, "Condition failed: '" + shake::lexical_cast(lhs) + " > " + shake::lexical_cast(rhs) + "'. " + message);
}

//----------------------------------------------------------------
template <typename T> inline
void check_not_null (const T& v, const std::string& message)
{
    check(v != nullptr, "Condition failed: 'ptr != nullptr'. " + message);
}

//----------------------------------------------------------------
inline const std::string ffl_string
(
    const std::string&  file,
    const std::string&  function,
    const int           line
)
{
    return "[ File: " + file + ", Function: " + function + ", Line: " + shake::lexical_cast( line ) + " ] ";
}

//----------------------------------------------------------------
inline const std::string expect_string()    { return "Expect precondition failed: ";    }
inline const std::string check_string()     { return "Check condition failed: ";        }
inline const std::string ensure_string()    { return "Ensure postcondition failed: ";   }

} // namespace contracts_detail
} // namespace shake

#endif // CONTRACTS_DETAIL_HPP
