#ifndef MACRO_NON_COPYABLE_HPP
#define MACRO_NON_COPYABLE_HPP

//----------------------------------------------------------------
#define NON_COPYABLE(classname) \
    classname(const classname&) = delete; \
    void operator=(const classname&) = delete;

//----------------------------------------------------------------
//#define NON_COPYABLE_BUT_MOVEABLE(classname) \
//    classname(const classname&) = delete; \
//    void operator=(const classname&) = delete; \
//\
//    classname(classname&&) = default; \
//    classname& operator=(classname&&) = default;

#endif // MACRO_NON_COPYABLE_HPP
