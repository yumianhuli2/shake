#ifndef RUNNING_AVERAGE_COUNTER_HPP
#define RUNNING_AVERAGE_COUNTER_HPP

#include <array>

namespace shake {

template<typename T, size_t N_samples>
class RunningAverageCounter
{
public:
    RunningAverageCounter()
        : m_next_index{ static_cast<size_t>( 0 ) }
    {
        m_samples.fill( static_cast<T>( 0 ) );
    }

    void add_sample( const T& sample )
    {
        m_samples.at( m_next_index ) = sample;
        m_next_index = ( m_next_index + 1 ) % N_samples;
    }

    T get_running_average()
    {
        auto sum = static_cast<T>( 0 );
        for ( const auto& v : m_samples ) { sum += v; }
        const auto running_average = sum / N_samples;
        return running_average;
    }

private:
    std::array<T, N_samples>    m_samples;
    size_t                      m_next_index;
};


} // namespace shake

#endif // RUNNING_AVERAGE_COUNTER_HPP
