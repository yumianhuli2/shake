#ifndef MACRO_MOVABLE_HPP
#define MACRO_MOVABLE_HPP

//----------------------------------------------------------------
#define MOVABLE(classname) \
    classname(classname&&) = default; \
    classname& operator=(classname&&) = default;

#endif // MACRO_MOVABLE_HPP
