#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>

#include "shake/core/contracts/contracts.hpp"

namespace shake {
namespace queue {

//----------------------------------------------------------------
template<typename Element_T>
inline Element_T pop ( std::queue<Element_T>& queue )
{
    const Element_T& event = queue.front();
    queue.pop();
    return event;
}

} // namespace queue
} // namespace shake

#endif // QUEUE_HPP
