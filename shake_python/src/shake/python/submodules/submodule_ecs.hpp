#ifndef SCRIPT_SYSTEM_MODULE_ECS_HPP
#define SCRIPT_SYSTEM_MODULE_ECS_HPP


#include <pybind11/pybind11.h>


namespace shake {
namespace python {
	

//----------------------------------------------------------------
void register_ecs
( 
	pybind11::module& shake_module 
);


} // namespace python
} // namespace cf

#endif // SCRIPT_SYSTEM_MODULE_ECS_HPP
