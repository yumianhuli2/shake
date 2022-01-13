#ifndef ENSURE_HPP
#define ENSURE_HPP

#include "shake/core/contracts/contracts_detail.hpp"

//----------------------------------------------------------------
#define ENSURE( condition, message ) \
do { \
    shake::contracts_detail::check \
    ( \
        condition, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_FAIL( message ) \
do { \
    shake::contracts_detail::check_fail \
    ( \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_EQ( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_eq \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_NE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_ne \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_LE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_le \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_LT( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_lt \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_GE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_ge \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_GT( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_gt \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define ENSURE_NOT_NULL( v, message ) \
do { \
    shake::contracts_detail::check_not_null \
    ( \
        v, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::ensure_string() + message \
    ); \
} while(0)

#endif // ENSURE_HPP
