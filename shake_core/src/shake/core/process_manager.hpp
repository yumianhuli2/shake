#ifndef PROCESS_MANAGER_HPP
#define PROCESS_MANAGER_HPP

#include <functional>
#include <vector>

namespace shake {

//----------------------------------------------------------------
class ProcessManager
{
public:
    using Process = std::function<void(float)>;

    //----------------------------------------------------------------
    ProcessManager& add_process( const Process& process )
    {
        m_processes.emplace_back( process );
        return (*this);
    }

    //----------------------------------------------------------------
    void update( const float dt )
    {
        for( auto& process : m_processes )
        {
            process( dt );
        }
    }

private:
    std::vector<Process> m_processes;
};

} // namespace shake

#endif // PROCESS_MANAGER_HPP
