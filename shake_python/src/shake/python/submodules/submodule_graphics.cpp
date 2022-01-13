#include "submodule_graphics.hpp"

#include <pybind11/stl.h>

#include "shake/content/content_manager.hpp"
#include "shake/core/log.hpp"
#include "shake/core/contracts/contracts.hpp"
#include "shake/graphics/camera.hpp"
#include "shake/graphics/context.hpp"
#include "shake/graphics/draw.hpp"
#include "shake/graphics/draw_text.hpp"
#include "shake/graphics/render_pack.hpp"
#include "shake/graphics/material/material.hpp"
#include "shake/io/path.hpp"
#include "shake/python/submodules/macro_def_member.hpp"

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_graphics( pybind11::module& shake_module )
{
    using namespace shake::content;
    using namespace shake::graphics;
    using namespace shake::graphics::gl;
    using namespace shake::io;

    auto graphics_module = shake_module.def_submodule( "graphics" );

    //----------------------------------------------------------------
	DEF_CLASS( graphics_module, Camera )
		DEF_CTOR( size_t, size_t )
        DEF_MEMBER( Camera, update )
        DEF_MEMBER_OVERLOAD( Camera, get_transform );

    graphics_module.def( "set_current_camera", &set_current_camera );
    graphics_module.def( "get_current_camera", &get_current_camera );

    graphics_module.def( "make_rectangle_2D", &make_rectangle_2D );
    graphics_module.def( "make_circle_filled_2D", &make_circle_filled_2D );

    //----------------------------------------------------------------
    DEF_ENUM( graphics_module, PolygonMode )
        DEF_VALUE( PolygonMode, Fill )
        DEF_VALUE( PolygonMode, Line );

    DEF_ENUM( graphics_module, FramebufferBitFlag )
        DEF_VALUE( FramebufferBitFlag, Color )
        DEF_VALUE( FramebufferBitFlag, Depth );


    graphics_module.def( "clear", &gl::clear );

    graphics_module.def( "draw", pybind11::overload_cast< const RenderPack2D&, const Transform2D& >( &graphics::draw ) );

    //graphics_module.def( "draw_text", draw );    
   
    //----------------------------------------------------------------
    DEF_CLASS( graphics_module, Geometry2D );
    DEF_CLASS( graphics_module, Geometry3D );

    DEF_CLASS( graphics_module, Material )
        DEF_CTOR( const std::shared_ptr<Program>& );

    DEF_CLASS( graphics_module, Font );

    DEF_CLASS( graphics_module, Program );

    DEF_CLASS( graphics_module, RenderPack2D )
        DEF_CTOR( 
            const std::shared_ptr<Geometry2D>,
            const std::shared_ptr<Material>
        );
        
    DEF_CLASS( graphics_module, RenderPack3D );
}

} // namespace python
} // namespace shake