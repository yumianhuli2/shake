#include "path.hpp"

namespace shake {
namespace io {

//----------------------------------------------------------------
Path::Path()
    : m_string { "" }
{ }

Path::Path( const std::string& path )
    : m_string { path }
{ }

//----------------------------------------------------------------
std::string Path::get_string() const
{
    return m_string;
}

//----------------------------------------------------------------
std::string Path::get_file_extension() const
{
    size_t dot_index { m_string.rfind(".") };
    std::string file_extension { m_string.substr( dot_index ) };
    return file_extension;
}

//----------------------------------------------------------------
Path Path::operator/ ( const std::string& rhs ) const
{
    return Path { m_string + "/" + rhs };
}

Path& Path::operator/=( const std::string& rhs )
{
    m_string += "/" + rhs;
    return *this;
}

Path Path::operator/ ( const Path& rhs ) const
{
    return Path { m_string + "/" + rhs.get_string() };
}

Path& Path::operator/=( const Path& rhs )
{
    m_string += "/" + rhs.get_string();
    return *this;
}

//----------------------------------------------------------------
Path Path::operator+ ( const std::string& rhs ) const
{
    return Path { m_string + rhs };
}

Path& Path::operator+=( const std::string& rhs )
{
    m_string += rhs;
    return *this;
}

Path Path::operator+ ( const Path& rhs ) const
{
    return Path { m_string + rhs.get_string() };
}

Path& Path::operator+=( const Path& rhs )
{
    m_string += rhs.get_string();
    return *this;
}

//----------------------------------------------------------------
bool Path::operator< ( const Path& rhs ) const
{
    return m_string < rhs.get_string();
}

//----------------------------------------------------------------
bool Path::has_file_extension ( const std::string& extension ) const
{
    return get_file_extension() == extension;
}

bool Path::has_any_file_extension_of( const std::initializer_list<std::string>& extensions ) const
{
    const std::string& extension { get_file_extension() };
    return shake::string::equals_any_of(extension, extensions);
}

} // namespace io
} // namespace shake
