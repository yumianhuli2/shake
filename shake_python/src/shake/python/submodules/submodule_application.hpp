#ifndef SUBMODULE_APPLICATION_HPP
#define SUBMODULE_APPLICATION_HPP


#include <pybind11/pybind11.h>


namespace shake {
namespace python {


//----------------------------------------------------------------
void register_application
(
	pybind11::module& shake_module
);


} // namespace python
} // namespace shake

#endif // SUBMODULE_APPLICATION_HPP
