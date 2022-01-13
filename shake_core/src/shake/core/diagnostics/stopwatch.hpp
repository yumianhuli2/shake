#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

namespace shake {

//----------------------------------------------------------------
class Stopwatch
{
public:
    Stopwatch()
        : m_begin   ( std::chrono::high_resolution_clock::now() )
        , m_end     ( std::chrono::high_resolution_clock::now() )
    { }

    ~Stopwatch() = default;

    inline void reset()
    {
        m_begin = std::chrono::high_resolution_clock::now();
    }

    inline double get()
    {
        m_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms = m_end - m_begin;
        return ms.count();
    }

    inline double get_and_reset()
    {
        const auto result = get();
        reset();
        return result;
    }

private:
    std::chrono::high_resolution_clock::time_point m_begin;
    std::chrono::high_resolution_clock::time_point m_end;
};

} // namespace shake

#endif // STOPWATCH_HPP

