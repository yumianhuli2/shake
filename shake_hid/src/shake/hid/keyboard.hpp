#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <map>

#include "shake/core/std/string.hpp"
#include "shake/core/signal.hpp"
#include "shake/core/macros/macro_non_copyable.hpp"

#include "shake/hid/window.hpp"

namespace shake {

class Keyboard
{
public:

    //----------------------------------------------------------------
    enum class Key
    {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        Left, Right, Up, Down,
        Escape
    };

    enum class Action
    {
        Press,
        Release,
        Repeat
    };

    //----------------------------------------------------------------
    inline static Keyboard& get_instance()
    {
        static Keyboard t { };
        return t;
    }

    //----------------------------------------------------------------
    void init( const Window& window );

    //----------------------------------------------------------------
    bool is_up      (Key key) const;
    bool is_down    (Key key) const;

    //----------------------------------------------------------------
    void update( );

    NON_COPYABLE( Keyboard )

private:
    Keyboard() = default;
};

} // namespace shake

#endif // KEYBOARD_HPP
