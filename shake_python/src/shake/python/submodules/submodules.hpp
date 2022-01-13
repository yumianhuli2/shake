#ifndef SUBMODULES_HPP
#define SUBMODULES_HPP


#include <pybind11/embed.h>


namespace shake {
namespace python {


//----------------------------------------------------------------
void register_submodules
( 
    pybind11::module& shake_module 
);


} // namespace python
} // namespace shake


#endif // SUBMODULES_HPP
