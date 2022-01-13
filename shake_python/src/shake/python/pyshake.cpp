#include <pybind11/pybind11.h>

// Needed for opaque types
#include "shake/ecs/entity/entity.hpp"

// Opaque types allow c++ objects to be passed as references through Python code,
// so without the intermediate copying. 
// It's a bit ugly,
// but opaque types have to be declared at top level, 
// and in a shared header file. 
// We therefore define all opaque types here
// even if they are from different submodules.

PYBIND11_MAKE_OPAQUE( std::vector<shake::ecs::EntityId> );


#include "shake/main/application.hpp"
#include "submodules/submodules.hpp"

// This call must be in the global namespace
// However, we want to put all code that registers code,
// to be nicely put into our own namespaces.
// So this macro just delegates to our own functions.
PYBIND11_MODULE( pyshake, shake_module ) 
{
    shake::python::register_submodules( shake_module );
}


