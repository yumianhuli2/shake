#ifndef EXPECT_HPP
#define EXPECT_HPP

#include "shake/core/contracts/contracts_detail.hpp"

//----------------------------------------------------------------
#define EXPECT( condition, message ) \
do { \
    shake::contracts_detail::check \
    ( \
        condition, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_FAIL( message ) \
do { \
    shake::contracts_detail::check_fail \
    ( \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_EQ( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_eq \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_NE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_ne \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_LE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_le \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_LT( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_lt \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_GE( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_ge \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_GT( lhs, rhs, message ) \
do { \
    shake::contracts_detail::check_gt \
    ( \
        lhs, rhs, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

//----------------------------------------------------------------
#define EXPECT_NOT_NULL( v, message ) \
do { \
    shake::contracts_detail::check_not_null \
    ( \
        v, \
        shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
        + shake::contracts_detail::expect_string() + message \
    ); \
} while(0)

#endif // EXPECT_HPP
