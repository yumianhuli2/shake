#ifndef MACRO_DEBUG_ONLY_HPP
#define MACRO_DEBUG_ONLY_HPP

//----------------------------------------------------------------
#define SHAKE_DEBUG

//----------------------------------------------------------------
#if defined SHAKE_DEBUG
    #define DEBUG_ONLY( code ) code
#else
    #define DEBUG_ONLY()
#endif

#endif // MACRO_DEBUG_ONLY_HPP
