#ifndef STRING_HPP
#define STRING_HPP

#include <algorithm>
#include <string>
#include <cctype>

namespace shake     {
namespace string    {

//----------------------------------------------------------------
inline std::string to_upper(const std::string& string)
{
    std::string result = string;
    for (auto& c : result)
        { c = std::toupper(c); }
    return result;
}

//----------------------------------------------------------------
inline std::string to_lower(const std::string& string)
{
    std::string result = string;
    for (auto& c : result)
        { c = std::tolower(c); }
    return result;
}

//----------------------------------------------------------------
inline bool equals_any_of(const std::string& lhs, const std::initializer_list<std::string>& rhs )
{
    return std::any_of(std::begin(rhs), std::end(rhs), [& lhs](const std::string& s) { return lhs == s; });
}

} // namespace string
} // namespace shake


#endif // STRING_HPP
