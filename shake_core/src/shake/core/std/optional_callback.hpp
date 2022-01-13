#ifndef OPTIONAL_CALLBACK_HPP
#define OPTIONAL_CALLBACK_HPP

#include <functional>
#include <optional>

namespace shake {

template< typename FunctionType >
using OptionalCallback = std::optional< std::function< FunctionType > >;

//----------------------------------------------------------------
template< typename FunctionType, typename... Args >
inline auto invoke_if_set( const OptionalCallback< FunctionType >& optional_callback, Args... args )
{
    if ( !optional_callback.has_value() ) { return; }
    return optional_callback.value()( args... );
}

} // namespace shake

#endif // OPTIONAL_CALLBACK_HPP
