#include "mouse.hpp"

#include <GLFW/glfw3.h>

#include "shake/core/contracts/contracts.hpp"
#include "shake/core/std/dual_key_map.hpp"
#include "shake/core/signal.hpp"
#include "shake/core/std/string.hpp"

namespace shake {

namespace { // anonymous

//----------------------------------------------------------------
Mouse::Key glfw_key_to_shake_key( int glfw_key )
{
    switch ( glfw_key )
    {
    case GLFW_MOUSE_BUTTON_1: return Mouse::Key::Left;
    case GLFW_MOUSE_BUTTON_2: return Mouse::Key::Right;
    case GLFW_MOUSE_BUTTON_3: return Mouse::Key::Alt_1;
    case GLFW_MOUSE_BUTTON_4: return Mouse::Key::Alt_2;
    case GLFW_MOUSE_BUTTON_5: return Mouse::Key::Alt_3;
    case GLFW_MOUSE_BUTTON_6: return Mouse::Key::Alt_4;
    case GLFW_MOUSE_BUTTON_7: return Mouse::Key::Alt_5;
    case GLFW_MOUSE_BUTTON_8: return Mouse::Key::Alt_6;

    // ignore unsupported keys to prevent crashing unnecessarily
    // --default:
    // --CHECK_FAIL( "Unsupported mouse button" );
    // --break;
    }
}

//----------------------------------------------------------------
Mouse::Action glfw_action_to_shake_action( int action )
{
    switch ( action )
    {
    case GLFW_PRESS:    return Mouse::Action::Press;
    case GLFW_RELEASE:  return Mouse::Action::Release;
    case GLFW_REPEAT:   return Mouse::Action::Repeat;

    default:
        CHECK_FAIL( "Unsupported mouse action" );
        break;
    }
}

//----------------------------------------------------------------
struct KeyEvent     { Mouse::Key    key;        Mouse::Action   action;     };
struct CursorEvent  { double        position_x; double          position_y; };
struct ScrollEvent  { double        offset_x;   double          offset_y;   };

using KeySignal     = shake::Signal<KeyEvent>;
using CursorSignal  = shake::Signal<CursorEvent>;
using ScrollSignal  = shake::Signal<ScrollEvent>;
using KeyStates     = std::map<Mouse::Key, bool>;

KeySignal       key_signal          { };
CursorSignal    cursor_signal       { };
ScrollSignal    scroll_signal       { };

KeyStates       key_states          { };

double          cursor_position_x   { 0.0 };
double          cursor_position_y   { 0.0 };
double          cursor_diff_x       { 0.0 };
double          cursor_diff_y       { 0.0 };
double          scroll_offset_x     { 0.0 };
double          scroll_offset_y     { 0.0 };

//----------------------------------------------------------------
void glfw_key_callback(GLFWwindow* window, int key, int action, int mods)
{
    // get glfw and move to shake event queue
    key_signal.enqueue( { glfw_key_to_shake_key( key ), glfw_action_to_shake_action( action ) } );
}

//----------------------------------------------------------------
void glfw_cursor_callback(GLFWwindow* window, double position_x, double position_y)
{
    // get glfw and move to shake event queue
    cursor_signal.enqueue( { position_x, position_y } );
}

//----------------------------------------------------------------
void glfw_scroll_callback(GLFWwindow* window, double offset_x, double offset_y)
{
    // get glfw and move to shake event queue
    scroll_signal.enqueue( { offset_x, offset_y } );
}

//----------------------------------------------------------------
void shake_key_callback( const KeyEvent& key_event )
{
    switch ( key_event.action )
    {
    case Mouse::Action::Press:     { key_states[key_event.key] = true;  }  break;
    case Mouse::Action::Release:   { key_states[key_event.key] = false; }  break;
    }
}

//----------------------------------------------------------------
void shake_cursor_callback( const CursorEvent& cursor_event )
{
    cursor_diff_x       = cursor_event.position_x - cursor_position_x;
    cursor_diff_y       = cursor_event.position_y - cursor_position_y;
    cursor_position_x   = cursor_event.position_x;
    cursor_position_y   = cursor_event.position_y;
}

//----------------------------------------------------------------
void shake_scroll_callback( const ScrollEvent& scroll_event )
{
    scroll_offset_x = scroll_event.offset_x;
    scroll_offset_y = scroll_event.offset_y;
}

} // namespace anonymous

//----------------------------------------------------------------
void Mouse::init( const Window& window )
{
    // register the callbacks for glfw events
    glfwSetCursorPosCallback    ( window.get_glfw_window_ptr(), glfw_cursor_callback );
    glfwSetMouseButtonCallback  ( window.get_glfw_window_ptr(), glfw_key_callback    );
    glfwSetScrollCallback       ( window.get_glfw_window_ptr(), glfw_scroll_callback );

    // register the callbacks for shake events
    key_signal.subscribe   ( shake_key_callback    );
    cursor_signal.subscribe( shake_cursor_callback );
    scroll_signal.subscribe( shake_scroll_callback );
}

//----------------------------------------------------------------
bool    Mouse::is_up  ( Mouse::Key key )        const   { return !key_states[ key ];    }
bool    Mouse::is_down( Mouse::Mouse::Key key ) const   { return  key_states[ key ];    }

//----------------------------------------------------------------
double  Mouse::get_position_x()     const   { return cursor_position_x;     }
double  Mouse::get_position_y()     const   { return cursor_position_y;     }
double  Mouse::get_diff_x()         const   { return cursor_diff_x;         }
double  Mouse::get_diff_y()         const   { return cursor_diff_y;         }

//----------------------------------------------------------------
double  Mouse::get_scroll_x()       const   { return scroll_offset_x;       }
double  Mouse::get_scroll_y()       const   { return scroll_offset_y;       }

//----------------------------------------------------------------
void Mouse::update()
{
    // Key events
    key_signal.broadcast();

    // Cursor events
    cursor_diff_x = 0.0;
    cursor_diff_y = 0.0;
    cursor_signal.broadcast();

    // Scroll events
    scroll_offset_x = 0.0;
    scroll_offset_y = 0.0;
    scroll_signal.broadcast();
}

} // namespace shake
