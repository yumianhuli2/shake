#ifndef SCRIPT_SYSTEM_MODULE_GRAPHICS_HPP
#define SCRIPT_SYSTEM_MODULE_GRAPHICS_HPP


#include <pybind11/pybind11.h>


namespace shake {
namespace python {


//----------------------------------------------------------------
void register_graphics
( 
    pybind11::module& shake_module 
);


} // namespace python
} // namespace shake

#endif // SCRIPT_SYSTEM_MODULE_GRAPHICS_HPP
