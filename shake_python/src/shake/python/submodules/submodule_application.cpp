#include "submodule_application.hpp"

#include <glm/glm.hpp>

// Enables std::function conversions
#include <pybind11/functional.h> 

#include "shake/main/application.hpp"

#include "shake/core/log.hpp"
#include "shake/core/contracts/contracts.hpp"
#include "shake/core/math/math.hpp"
#include "shake/core/math/transform_2d.hpp"
#include "shake/core/math/transform_3d.hpp"
#include "shake/python/submodules/macro_def_member.hpp"

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_application( pybind11::module& shake_module )
{
    //----------------------------------------------------------------
	DEF_CLASS( shake_module, Application )
		DEF_CTOR
        ( 
            const Application::InitCallback&,
            const Application::UpdateCallback&,
            const Application::DrawCallback&,
            const Application::DestroyCallback&,
            const std::size_t,
            const std::size_t,
            const std::string&
        )
        DEF_MEMBER(         Application, run                    )
        DEF_MEMBER(         Application, update                 )
        DEF_MEMBER(         Application, get_current_fps        )
        DEF_MEMBER(         Application, close                  )   
        DEF_PROPERTY_RW(    Application, window                 )
        DEF_PROPERTY_RW(    Application, content_manager        );    
}

} // namespace python
} // namespace shake