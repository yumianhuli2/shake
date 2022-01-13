#include "submodule_core.hpp"

#include <glm/glm.hpp>

#include "shake/core/log.hpp"
#include "shake/core/contracts/contracts.hpp"
#include "shake/core/math/math.hpp"
#include "shake/core/math/transform_2d.hpp"
#include "shake/core/math/transform_3d.hpp"
#include "shake/python/submodules/macro_def_member.hpp"

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_core(pybind11::module& shake_module)
{
	auto core_module = shake_module.def_submodule("core");

	core_module.def
    ( 
        "log",     
        []( std::string& s )            
        { LOG(s); }         
    );

	core_module.def
    ( 
        "check",   
        []( bool b, std::string& s )    
        { CHECK(b, s); }    
    );

	//----------------------------------------------------------------
	DEF_CLASS( core_module, Transform2D )
		DEF_CTOR()
    ;

	DEF_CLASS( core_module, Transform3D )
		DEF_CTOR()
        DEF_MEMBER( Transform3D, translate );

    DEF_CLASS_NAMED( core_module, glm::vec2, "Vec2" )
        DEF_CTOR( float, float );

    DEF_CLASS_NAMED( core_module, glm::vec3, "Vec3" )
        DEF_CTOR( float, float, float );
}


} // namespace python
} // namespace shake