#include "submodules.hpp"


#include "shake/python/submodules/submodule_application.hpp"
#include "shake/python/submodules/submodule_content.hpp"
#include "shake/python/submodules/submodule_core.hpp"
#include "shake/python/submodules/submodule_ecs.hpp"
#include "shake/python/submodules/submodule_graphics.hpp"
#include "shake/python/submodules/submodule_hid.hpp"


namespace shake {
namespace python {


//----------------------------------------------------------------
void register_submodules
( 
    pybind11::module& shake_module 
)
{
    register_application( shake_module );
    register_content    ( shake_module );
	register_core       ( shake_module );
	register_ecs        ( shake_module );
	register_graphics   ( shake_module );
	register_hid        ( shake_module );
}


} // namespace python
} // namespace shake