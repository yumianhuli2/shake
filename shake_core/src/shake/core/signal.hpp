#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <functional>

#include "shake/core/std/queue.hpp"
#include "shake/core/std/map.hpp"
#include "shake/core/contracts/contracts.hpp"
#include "shake/core/macros/macro_debug_only.hpp"

namespace shake {

template<typename Event_T>
class Signal
{
public:
    using event_type    = Event_T;
    using Token         = uint8_t;
    using function_type = std::function<void(const event_type&)>;

public:

    Token subscribe( const function_type& callback )
    {
        Token token { m_next_token++ };
        m_callbacks.emplace( token, callback );
        return token;
    }

    void unsubscribe( const Token& token )
    {
        DEBUG_ONLY( CHECK( map::has( m_callbacks, token ), "Map does not have expected key" ) );
        m_callbacks.erase( token );
    }

    void enqueue( const event_type& event )
    {
        m_events.push( event );
    }

    void broadcast()
    {
        while( !m_events.empty() )
        {
            const event_type& event = shake::queue::pop( m_events );
            for( const auto& callback : m_callbacks )
            {
                callback.second( event );
            }
        }
    }

private:
    Token                           m_next_token  { 0 };
    std::queue<event_type>          m_events;
    std::map<Token, function_type > m_callbacks;
};

} // namespace shake

#endif // SIGNAL_HPP