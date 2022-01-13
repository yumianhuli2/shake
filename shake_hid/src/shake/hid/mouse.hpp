#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "shake/core/std/string.hpp"
#include "shake/core/macros/macro_non_copyable.hpp"

#include "shake/hid/window.hpp"

namespace shake {

class Mouse
{
public:

    //----------------------------------------------------------------
    enum class Key
    {
        Left, Right,
        Alt_1, Alt_2, Alt_3, Alt_4, Alt_5, Alt_6
    };

    enum class Action
    {
        Press,
        Release,
        Repeat
    };

    //----------------------------------------------------------------
    inline static Mouse& get_instance()
    {
        static Mouse t { };
        return t;
    }

    //----------------------------------------------------------------
    void    init( const Window& window );

    //----------------------------------------------------------------
    bool    is_up   ( Key key ) const;
    bool    is_down ( Key key ) const;

    //----------------------------------------------------------------
    double  get_position_x() const;
    double  get_position_y() const;
    double  get_diff_x() const;
    double  get_diff_y() const;

    //----------------------------------------------------------------
    double  get_scroll_x() const;
    double  get_scroll_y() const;

    //----------------------------------------------------------------
    void    update( );

    NON_COPYABLE( Mouse )

private:
    Mouse() = default;
};
} // namespace shake

#endif // MOUSE_HPP
