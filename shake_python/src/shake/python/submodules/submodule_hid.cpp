#include "submodule_hid.hpp"


#include "shake/hid/keyboard.hpp"
#include "shake/hid/mouse.hpp"
#include "shake/hid/window.hpp"

#include "macro_def_member.hpp"


namespace shake {
namespace python {

namespace { // anonymous


//----------------------------------------------------------------
void register_keyboard
( 
    pybind11::module& hid_module 
)
{
    auto keyboard_module = hid_module.def_submodule( "Keyboard" );
    using Key = Keyboard::Key;

    keyboard_module.def
    (
        "is_up", 
        []( const Key& key ) 
        { return Keyboard::get_instance().is_up( key ); }
    );

	keyboard_module.def
    (
        "is_down", 
        []( const Key& key ) 
        { return Keyboard::get_instance().is_down( key ); }
    );

    
	DEF_ENUM( keyboard_module, Key )
		DEF_VALUE( Key, A )
		DEF_VALUE( Key, B )
		DEF_VALUE( Key, C )
		DEF_VALUE( Key, D )
		DEF_VALUE( Key, E )
		DEF_VALUE( Key, F )
		DEF_VALUE( Key, G )
		DEF_VALUE( Key, H )
		DEF_VALUE( Key, I )
		DEF_VALUE( Key, J )
		DEF_VALUE( Key, K )
		DEF_VALUE( Key, L )
		DEF_VALUE( Key, M )
		DEF_VALUE( Key, N )
		DEF_VALUE( Key, O )
		DEF_VALUE( Key, P )
		DEF_VALUE( Key, Q )
		DEF_VALUE( Key, R )
		DEF_VALUE( Key, S )
		DEF_VALUE( Key, T )
		DEF_VALUE( Key, U )
		DEF_VALUE( Key, V )
		DEF_VALUE( Key, W )
		DEF_VALUE( Key, X )
		DEF_VALUE( Key, Y )
		DEF_VALUE( Key, Z )
        DEF_VALUE( Key, Left    )
        DEF_VALUE( Key, Right   )
        DEF_VALUE( Key, Up      )
        DEF_VALUE( Key, Down    )
        DEF_VALUE( Key, Escape  );
}

//----------------------------------------------------------------
void register_mouse
( 
    pybind11::module& hid_module 
)
{
    auto mouse_module = hid_module.def_submodule( "Mouse" );
    using Key = Mouse::Key;

	DEF_ENUM( mouse_module, Key )
		DEF_VALUE( Key, Left  )
		DEF_VALUE( Key, Right )
		DEF_VALUE( Key, Alt_1 )
		DEF_VALUE( Key, Alt_2 )
		DEF_VALUE( Key, Alt_3 )
		DEF_VALUE( Key, Alt_4 )
		DEF_VALUE( Key, Alt_5 )
		DEF_VALUE( Key, Alt_6 );

	mouse_module.def
    ( 
        "is_up",   
        []( const Mouse::Key& key ) 
        { return Mouse::get_instance().is_up( key ); }
    );

	mouse_module.def
    ( 
        "is_down", 
        []( const Mouse::Key& key ) 
        { return Mouse::get_instance().is_down( key ); }
    );
}

//----------------------------------------------------------------
void register_window
( 
    pybind11::module& hid_module 
)
{
    using namespace shake;

	DEF_CLASS( hid_module, Window )
        DEF_MEMBER( Window, swap_buffers );

}

} // namespace anonymous


//----------------------------------------------------------------
void register_hid
( 
    pybind11::module& shake_module 
)
{
    auto hid_module = shake_module.def_submodule( "hid" );

	register_keyboard   ( hid_module );
    register_mouse      ( hid_module );
    register_window     ( hid_module );
}


} // namespace python
} // namespace shake