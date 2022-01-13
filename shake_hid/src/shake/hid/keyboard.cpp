#include "keyboard.hpp"

#include <GLFW/glfw3.h>

#include "shake/core/contracts/contracts.hpp"
#include "shake/core/signal.hpp"
#include "shake/core/std/string.hpp"

namespace shake {

namespace { // anonymous

//----------------------------------------------------------------
Keyboard::Key glfw_key_to_shake_key( int key )
{
    switch ( key )
    {
    case GLFW_KEY_A: return Keyboard::Key::A;
    case GLFW_KEY_B: return Keyboard::Key::B;
    case GLFW_KEY_C: return Keyboard::Key::C;
    case GLFW_KEY_D: return Keyboard::Key::D;
    case GLFW_KEY_E: return Keyboard::Key::E;
    case GLFW_KEY_F: return Keyboard::Key::F;
    case GLFW_KEY_G: return Keyboard::Key::G;
    case GLFW_KEY_H: return Keyboard::Key::H;
    case GLFW_KEY_I: return Keyboard::Key::I;
    case GLFW_KEY_J: return Keyboard::Key::J;
    case GLFW_KEY_K: return Keyboard::Key::K;
    case GLFW_KEY_L: return Keyboard::Key::L;
    case GLFW_KEY_M: return Keyboard::Key::M;
    case GLFW_KEY_N: return Keyboard::Key::N;
    case GLFW_KEY_O: return Keyboard::Key::O;
    case GLFW_KEY_P: return Keyboard::Key::P;
    case GLFW_KEY_Q: return Keyboard::Key::Q;
    case GLFW_KEY_R: return Keyboard::Key::R;
    case GLFW_KEY_S: return Keyboard::Key::S;
    case GLFW_KEY_T: return Keyboard::Key::T;
    case GLFW_KEY_U: return Keyboard::Key::U;
    case GLFW_KEY_V: return Keyboard::Key::V;
    case GLFW_KEY_W: return Keyboard::Key::W;
    case GLFW_KEY_X: return Keyboard::Key::X;
    case GLFW_KEY_Y: return Keyboard::Key::Y;
    case GLFW_KEY_Z: return Keyboard::Key::Z;

    case GLFW_KEY_LEFT:     return Keyboard::Key::Left;
    case GLFW_KEY_RIGHT:    return Keyboard::Key::Right;
    case GLFW_KEY_UP:       return Keyboard::Key::Up;
    case GLFW_KEY_DOWN:     return Keyboard::Key::Down;

    case GLFW_KEY_ESCAPE:   return Keyboard::Key::Escape;

    // ignore unsupported keys to prevent crashing unnecessarily
    // --default:
    // --CHECK_FAIL( "Unsupported keyboard key" );
    // --break;
    }
};

//----------------------------------------------------------------
Keyboard::Action glfw_action_to_shake_action( int action )
{
    switch ( action )
    {
    case GLFW_PRESS:    return Keyboard::Action::Press;
    case GLFW_RELEASE:  return Keyboard::Action::Release;
    case GLFW_REPEAT:   return Keyboard::Action::Repeat;

    default:
        CHECK_FAIL( "Unsupported keyboard action" );
        break;
    }
}

//----------------------------------------------------------------
struct KeyEvent
{
    Keyboard::Key       key;
    Keyboard::Action    action;
};

using KeySignal = Signal<KeyEvent>;
using KeyStates = std::map<Keyboard::Key, bool>;

KeySignal   key_signal  { };
KeyStates   key_states  { };

//----------------------------------------------------------------
void glfw_key_callback( GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // get glfw key event and move to shake event queue
    key_signal.enqueue( { glfw_key_to_shake_key( key ), glfw_action_to_shake_action( action ) } );
}

//----------------------------------------------------------------
void shake_key_callback( const KeyEvent& key_event )
{
    switch ( key_event.action )
    {
    case Keyboard::Action::Press:       { key_states[key_event.key] = true;  } break;
    case Keyboard::Action::Release:     { key_states[key_event.key] = false; } break;
    }
}

} // namespace anonymous

//----------------------------------------------------------------
void Keyboard::init( const Window& window )
{
    // register the callback for glfw key events
    glfwSetKeyCallback( window.get_glfw_window_ptr(), glfw_key_callback );

    // register the callback for shake key_events
    key_signal.subscribe( shake_key_callback );
}

//----------------------------------------------------------------
bool Keyboard::is_up  ( Key key ) const { return !key_states[key]; }
bool Keyboard::is_down( Key key ) const { return  key_states[key]; }

//----------------------------------------------------------------
void Keyboard::update( )
{
    key_signal.broadcast();
}

} // namespace shake
