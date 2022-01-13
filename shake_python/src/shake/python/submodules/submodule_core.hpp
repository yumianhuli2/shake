#ifndef MODULE_CORE_HPP
#define MODULE_CORE_HPP


#include <pybind11/pybind11.h>


namespace shake {
namespace python {


//----------------------------------------------------------------
void register_core
(
	pybind11::module& shake_module
);


} // namespace python
} // namespace shake

#endif // MODULE_CORE_HPP
