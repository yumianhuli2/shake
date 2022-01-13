#include "submodule_ecs.hpp"


#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include "shake/ecs/component/component.hpp"
#include "shake/ecs/system/system.hpp"
#include "shake/ecs/system/python_system.hpp"
#include "shake/ecs/system/render_system.hpp"
#include "shake/ecs/world.hpp"
#include "shake/graphics/render_pack.hpp"
#include "shake/python/submodules/macro_def_member.hpp"

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_ecs( pybind11::module& shake_module )
{
	auto ecs_module = shake_module.def_submodule( "ecs" );

	using namespace shake::ecs;
	using namespace shake::graphics;

	//----------------------------------------------------------------
	// ENTITY
	{
		//DEF_CLASS( ecs_module, EntityId )
		//	DEF_CTOR( EntityIdInternalType );

	} // ENTITY

    //----------------------------------------------------------------
	// WORLD
    {
//#define DEF_WORLD_MEMBER( member_name ) \
//    DEF_MEMBER( World, member_name )
//
//#define DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT( template_type ) \
//    DEF_TEMPLATE_MEMBER                 ( World, add_component_to_entity,        template_type  ) \
//    DEF_TEMPLATE_MEMBER                 ( World, entity_has_component,           template_type  ) \
//    DEF_TEMPLATE_MEMBER_OVERLOAD        ( World, get_component_from_entity,      template_type, EntityId ) \
//    DEF_TEMPLATE_MEMBER_OVERLOAD_CONST  ( World, get_component_from_entity,      template_type, EntityId ) \
//    DEF_TEMPLATE_MEMBER                 ( World, destroy_component_from_entity,  template_type )
//
//#define DEF_WORLD_TEMPLATE_MEMBERS_SYSTEM( template_type ) \
//    DEF_TEMPLATE_MEMBER( World, add_system, template_type )
//
//		//----------------------------------------------------------------
//		DEF_CLASS( ecs_module, World )
//			DEF_CTOR( const std::string& )
//
//			DEF_WORLD_MEMBER( update_systems    )
//
//			// entities
//			DEF_WORLD_MEMBER( create_entity     )
//			DEF_WORLD_MEMBER( is_valid_entity   )
//			DEF_WORLD_MEMBER( destroy_entity    )
//			DEF_WORLD_MEMBER( get_entity_id_set )
//
//			DEF_WORLD_MEMBER( add_python_system )
//
//			// components
//			DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT( RenderComponent2D     )
//			DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT( RenderComponent3D     )
//			DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT( TransformComponent2D  )
//			DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT( TransformComponent3D  );
    }

			// systems
			// The PythonSystem trampoline should just be interpreted as a System,
			// otherwise the automatic upcasting from Pybind11 will fail.
			//DEF_WORLD_TEMPLATE_MEMBERS_SYSTEM( System       )
			//DEF_WORLD_TEMPLATE_MEMBERS_SYSTEM( RenderSystem );

#undef DEF_WORLD_MEMBER
#undef DEF_WORLD_TEMPLATE_MEMBERS_COMPONENT
#undef DEF_WORLD_TEMPLATE_MEMBERS_SYSTEM
	//} // WORLD

	//----------------------------------------------------------------
	// COMPONENTS
	{
		DEF_CLASS( ecs_module, RenderComponent2D )      DEF_CTOR( const RenderPack2D& );
		DEF_CLASS( ecs_module, RenderComponent3D )      DEF_CTOR( const RenderPack3D& );

		DEF_CLASS( ecs_module, TransformComponent2D )   DEF_CTOR( const shake::Transform2D& );
		DEF_CLASS( ecs_module, TransformComponent3D )   DEF_CTOR( const shake::Transform3D& );

	} // COMPONENTS

	//----------------------------------------------------------------
	// SYSTEMS
	{
		////----------------------------------------------------------------
		//// The trampoline class that enables python code to inherit from C++ classes
		//DEF_CLASS( ecs_module, PythonSystem )
		//	DEF_CTOR()
		//	DEF_CTOR( const System& )
		//	DEF_MEMBER( System, update );

		////----------------------------------------------------------------
		//DEF_CLASS( ecs_module, RenderSystem )
		//	DEF_CTOR()
		//	DEF_MEMBER( RenderSystem, update );

  //      //----------------------------------------------------------------
		//ecs_module.def( "call_update", []( System* system ) -> void
		//{
		//	auto vec = std::vector<EntityId> { };
		//	system->update( 1.3f, nullptr, vec );
		//} );

	} // SYSTEMS
}

} // namespace python
} // namespace shake