#ifndef ENUMERATE_RANGE_HPP
#define ENUMERATE_RANGE_HPP

#include <cstddef>
#include <iterator>

#include "range.hpp"
#include "index_range.hpp"

namespace shake {

template<typename range_t>
auto enumerate( range_t input_range )
{
	const auto size = static_cast<std::size_t>( std::distance( std::begin( input_range ), std::end( input_range ) ) );
	return combine( range( size ), input_range );
}

} // namespace shake

#endif // ENUMERATE_RANGE_HPP