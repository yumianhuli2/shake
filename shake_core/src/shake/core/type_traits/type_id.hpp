#ifndef TYPE_ID_HPP
#define TYPE_ID_HPP

//#include <cstddef>

#include <typeindex>
#include <typeinfo>

namespace shake {

// TypeId is put into a namespace because you generally never want to use a raw type_id.
// Instead, you probably want to create a strongly typed alias,
// to limit the kinds of types you expect.
namespace type_id {

using TypeId = std::type_index;

//----------------------------------------------------------------
// Used to get a unique identifier for each type.
// Every time the function is called with the same template parameter,
// the same static type id is returned.
template <typename T>
static TypeId get()
{
    return std::type_index { typeid(T) };
}

} // namespace type_id
} // namespace shake

#endif // TYPE_ID_HPP
