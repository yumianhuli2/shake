#ifndef DECORATOR_POINTER_HPP
#define DECORATOR_POINTER_HPP

#include <functional>
#include <memory>

// Uses -> syntax to apply decorators
// You can access member functions via ->
// and a pre function will be called before the member call,
// and a post function will be called after the member call.
// These calls are independent from each other, 
// if you need dependence you can take this code as an exmaple, 
// and implement your cusotm needs by storing dependencies as members. 
// Because -> is called recursively untill a pointer is returned, 
// you must pass your root object as a pointer, 
// while additional nesting decorators are not allowed to be pointers. 
// Adding a pre function is easy, as it can be done in the root operator->,
// however adding a post funciton is more difficult, 
// as we cannot simply insert a function call somewhere after the target member function is called.
// We can create such a location using a proxy object, whose destructor is called after the member call, 
// so that we can do the post function call in the destructor. 
// To keep the pre and post funcitons closer to eachother, 
// we apply the pre function in the constructor of the proxy object.

//----------------------------------------------------------------
using DecoratingFunction = std::function<void()>;

//----------------------------------------------------------------
template<typename Decoratee_T>
class ScopedNonOwningDecoratorPointerInvocation
{
public:
    explicit ScopedNonOwningDecoratorPointerInvocation
    (
        Decoratee_T         decoratee,
        DecoratingFunction  pre_function, 
        DecoratingFunction  post_function
    ) 
        : m_decoratee       { decoratee }
        , m_post_function   { post_function }
    { 
        pre_function(); 
    }

    ~ScopedNonOwningDecoratorPointerInvocation() 
    { 
        m_post_function(); 
    }

    Decoratee_T operator->() const
    { 
        return m_decoratee; 
    }

private:
    DecoratingFunction  m_post_function;
    Decoratee_T         m_decoratee;
};

//----------------------------------------------------------------
template<typename Decoratee_T>
class NonOwningDecoratorPointer
{
public:
    using proxy_type        = ScopedNonOwningDecoratorPointerInvocation< Decoratee_T >;
    using const_proxy_type  = ScopedNonOwningDecoratorPointerInvocation< const Decoratee_T >;

    template<typename... Args>
    NonOwningDecoratorPointer
    ( 
        Decoratee_T         decoratee, 
        DecoratingFunction  pre_function, 
        DecoratingFunction  post_function
    )
        : m_decoratee       { decoratee }
        , m_pre_function    { pre_function }
        , m_post_function   { post_function }        
    { }

    proxy_type          operator->()        { return proxy_type         { m_decoratee, m_pre_function, m_post_function }; }
    const_proxy_type    operator->() const  { return const_proxy_type   { m_decoratee, m_pre_function, m_post_function }; }

private:
    DecoratingFunction  m_pre_function;
    DecoratingFunction  m_post_function;
    Decoratee_T         m_decoratee;
};


// A helper function that makes it easier to create decorators
// You normally need to specify the template type for a template class constructor.
// This function allows you to use template function type deduction.
// So you can simply use 'make_decorator( t )' instead of 'Decorator< T > { t }'.
// The difference becomes even bigger when dealing with complex nested template types such as nested decorators. 
template< typename Decoratee_T >
NonOwningDecoratorPointer< Decoratee_T > make_decorator_pointer
( 
    Decoratee_T         decoratee,
    DecoratingFunction  pre_function, 
    DecoratingFunction  post_function
)
{
    return NonOwningDecoratorPointer< Decoratee_T > { decoratee, pre_function, post_function };
}
    
#endif // DECORATOR_POINTER_HPP