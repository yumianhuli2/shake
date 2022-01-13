#ifndef PATH_HPP
#define PATH_HPP

#include <string>
#include <functional>

#include "shake/core/std/string.hpp"

namespace shake {
namespace io {

class Path
{
public:
    Path();
    explicit Path( const std::string& path );

    Path    operator/ ( const std::string& rhs ) const;
    Path&   operator/=( const std::string& rhs );

    Path    operator/ ( const Path& rhs ) const;
    Path&   operator/=( const Path& rhs );

    Path    operator+ ( const std::string& rhs ) const;
    Path&   operator+=( const std::string& rhs );

    Path    operator+ ( const Path& rhs ) const;
    Path&   operator+=( const Path& rhs );

    bool    operator< ( const Path& rhs ) const;

    std::string get_file_extension() const;
    std::string get_string() const;
    const char* c_str() const { return m_string.c_str(); }

    bool has_file_extension ( const std::string& extension ) const;
    bool has_any_file_extension_of( const std::initializer_list<std::string>& extensions ) const;

private:
    std::string m_string;
};


} // namespace io
} // namespace shake


#endif // PATH_HPP
