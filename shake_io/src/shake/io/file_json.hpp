#ifndef FILE_JSON_HPP
#define FILE_JSON_HPP

#include <vector>
#include <string>

#include "shake/core/contracts/contracts.hpp"
#include "shake/core/std/map.hpp"

#include <json11/json11.hpp>
#include "path.hpp"


namespace shake {
namespace io    {
namespace file  {
namespace json  {

using namespace json11;

//----------------------------------------------------------------
Json read(const Path& path);

namespace { // anonymous

//----------------------------------------------------------------
// template struct declaration
template<typename T>
struct as_type_getter
{
    static inline T get(const Json& json);
};

//----------------------------------------------------------------
template<>
struct as_type_getter<std::string>
{
    static inline std::string get(const Json& json)
    {
        CHECK(json.is_string(), "Json object is not a string.");
        return json.string_value();
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<Path>
{
    static inline Path get(const Json& json)
    {
        CHECK(json.is_string(), "Json object is not a string.");
        return Path { json.string_value() };
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<double>
{
    static inline double get(const Json& json)
    {
        CHECK(json.is_number(), "Json object is not a number.");
        return json.number_value();
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<float>
{
    static inline float get(const Json& json)
    {
        CHECK(json.is_number(), "Json object is not a number.");
        return static_cast<float>(json.number_value());
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<int>
{
    static inline int get(const Json& json)
    {
        CHECK(json.is_number(), "Json object is not a number.");
        return json.int_value();
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<uint64_t>
{
    static inline int get(const Json& json)
    {
        CHECK(json.is_number(), "Json object is not a number.");
        return static_cast<uint64_t>(json.int_value());
    }
};

//----------------------------------------------------------------
template<>
struct as_type_getter<bool>
{
    static inline bool get(const Json& json)
    {
        CHECK(json.is_bool(), "Json object is not a bool.");
        return json.bool_value();
    }
};

//----------------------------------------------------------------
template<typename E>
struct as_type_getter<std::vector<E>>
{
    static inline std::vector<E> get(const Json& json)
    {
        std::vector<E> result { };
        CHECK( json.is_array(), "Json object is not an array.")
        for (const auto& element : json.array_items())
        { 
            result.emplace_back(as_type_getter<E>::get(element)); 
        }
        return result;
    }
};

} // namespace anonymous

//----------------------------------------------------------------
template<typename T> inline
T read_as( const Json& json, const std::string& attribute_key )
{
    Json attribute { json };
    attribute = attribute[ attribute_key ];
    CHECK( attribute != Json(), "Atribute does not exist in json file." );
    T result { as_type_getter<T>::get(attribute) };
    return result;
}

//----------------------------------------------------------------
template<typename T> inline
T read_as( const Json& json, const std::initializer_list<std::string>& attribute_path )
{
    Json attribute { json };
    for (const auto& attribute_key : attribute_path)
    {
        attribute = attribute[ attribute_key ];
        CHECK( attribute != Json(), "Atribute does not exist in json file." );
    }
    T result { as_type_getter<T>::get(attribute) };
    return result;
}

//----------------------------------------------------------------
template<typename T> inline
T read_as_or( const Json& json, const std::string& attribute_key, const T& default_value )
{
    Json attribute { json };
    attribute = attribute[ attribute_key ];
    if ( attribute != Json() ) { return default_value; }
    T result { as_type_getter<T>::get(attribute) };
    return result;
}

//----------------------------------------------------------------
template<typename T> inline
T read_as_or( const Json& json, const std::initializer_list<std::string>& attribute_path, const T& default_value )
{
    Json attribute { json };
    for (const auto& attribute_key : attribute_path)
    {
        attribute = attribute[ attribute_key ];
        if ( attribute != Json() ) { return default_value; }
    }
    T result { as_type_getter<T>::get(attribute) };
    return result;
}

//----------------------------------------------------------------
inline bool has_key( const Json& json, const std::string& key )
{
    return map::has( json.object_items(), key );
}

} // namespace json
} // namespace file
} // namespace io
} // namespace shake

#endif // FILE_JSON_HPP
