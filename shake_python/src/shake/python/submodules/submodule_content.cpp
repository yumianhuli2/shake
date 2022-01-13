#include "submodule_content.hpp"

#include "shake/content/content_manager.hpp"
#include "shake/io/path.hpp"

#include "macro_def_member.hpp"

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_content
( 
    pybind11::module& shake_module 
)
{
    using namespace shake::content;
    using namespace shake::graphics;
    using namespace shake::io;

    auto content_module = shake_module.def_submodule( "content" );


#define DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( content_type ) \
    DEF_TEMPLATE_MEMBER( ContentManager, preload,      content_type ) \
    DEF_TEMPLATE_MEMBER( ContentManager, get_or_load,  content_type ) \
    DEF_TEMPLATE_MEMBER( ContentManager, get,          content_type ) \
    DEF_TEMPLATE_MEMBER( ContentManager, unload,       content_type )

    DEF_CLASS( content_module, ContentManager ) 
        DEF_MEMBER( ContentManager, host_content_directory )
        DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( CubeMap      )
        DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( Font         )
        DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( Material     )
        DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( Program      )
        DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE( Texture      );

    DEF_CLASS( content_module, Path )
        DEF_CTOR( std::string );

#undef DEF_CONTENT_MANAGER_TEMPLATE_MEMBERS_CONTENT_TYPE
}

} // namespace python
} // namespace shake