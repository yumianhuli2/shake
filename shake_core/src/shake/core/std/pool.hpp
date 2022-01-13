#ifndef POOL_HPP
#define POOL_HPP

#include <array>

#include "core/contracts.hpp"
#include "core/math.hpp"

namespace shake {

//----------------------------------------------------------------
template<typename T, size_t t_capacity>
class Pool
{
public:
    using value_type = T;

private:
    //----------------------------------------------------------------
    class FreelistNode
    {
    public:
        FreelistNode() : next{ nullptr } { }
        FreelistNode* next;
    };

    //----------------------------------------------------------------
    union PoolItem
    {
        // poolitem is initialized as a freelistnode
        PoolItem() : as_freelist_node() { }

        FreelistNode		as_freelist_node;
        T					as_T;
    };

    //----------------------------------------------------------------
    class Freelist
    {
    public:
        T* pop()
        {
            if (first == nullptr) { return nullptr; }

            PoolItem* head = first;
            first = reinterpret_cast<PoolItem*>(head->as_freelist_node.next);
            return &head->as_T;
        }

        void push(T* ptr)
        {
            PoolItem* head = reinterpret_cast<PoolItem*>(ptr);
            head->as_freelist_node.next = &first->as_freelist_node;
            first = head;
        }

        PoolItem* first;
    };

public:
    Pool()
        : m_size { 0 }
    {
        // everything is empty
        // so the freelist starts at index 0
        m_freelist.first = m_elements.data();
        for (auto& element : m_elements)
        {
            // pointer arithmetic adds sizeof(T) to a T*
            // so every element now points to the next element
            element.as_freelist_node.next = (&element.as_freelist_node) + 1;
        }
        // the last element has no element to point to
        m_elements.back().as_freelist_node.next = nullptr;
    }

    T* allocate()
    {
        m_size++;
        T* result = m_freelist.pop();
        core::check_not_null(result, "Could not allocate more elements in pool.");
        return result;
    }

    void free(T* ptr)
    {
        // first make sure the point actually points within the pool
        //core::check(math::points_within_range(ptr, std::begin(m_elements), std::end(m_elements)), "Pointer does not point within the pool.");

        m_size--;
        m_freelist.push(ptr);
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return t_capacity;
    }

private:
    size_t                              m_size;
    Freelist                            m_freelist;
    std::array<PoolItem, t_capacity>	m_elements;
};

} // namespace shake

#endif // POOL_HPP
