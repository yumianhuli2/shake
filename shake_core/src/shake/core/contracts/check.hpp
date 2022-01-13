#ifndef CHECK_HPP
#define CHECK_HPP

#include "shake/core/contracts/contracts_detail.hpp"

//----------------------------------------------------------------
#define CHECK( condition, message ) \
shake::contracts_detail::check \
( \
    condition, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_FAIL( message ) \
shake::contracts_detail::check_fail \
( \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_EQ( lhs, rhs, message ) \
shake::contracts_detail::check_eq \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_NE( lhs, rhs, message ) \
shake::contracts_detail::check_ne \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_LE( lhs, rhs, message ) \
shake::contracts_detail::check_le \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_LT( lhs, rhs, message ) \
shake::contracts_detail::check_lt \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_GE( lhs, rhs, message ) \
shake::contracts_detail::check_ge \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_GT( lhs, rhs, message ) \
shake::contracts_detail::check_gt \
( \
    lhs, rhs, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

//----------------------------------------------------------------
#define CHECK_NOT_NULL( v, message ) \
shake::contracts_detail::check_not_null \
( \
    v, \
    shake::contracts_detail::ffl_string( __FILE__, __func__, __LINE__ ) \
    + shake::contracts_detail::check_string() + message \
);

#endif // CHECK_HPP
