#ifndef CXPR_SQRT_HPP
#define CXPR_SQRT_HPP

#include <limits>

namespace dtl {
template <typename T>
constexpr T sqrtNewtonRaphson( T x, T curr, T prev ) {
    return curr == prev
               ? curr
               : sqrtNewtonRaphson( x, 0.5 * ( curr + x / curr ), curr );
}
} // namespace dtl

/*
 * Constexpr version of the square root
 * Return value:
 *   - For a finite and non-negative value of "x", returns an approximation for
 * the square root of "x"
 *   - Otherwise, returns NaN
 */
template <typename T>
constexpr T cxpr_sqrt( T x ) {
    return x >= 0 && x < std::numeric_limits<T>::infinity()
               ? dtl::sqrtNewtonRaphson<T>( x, x, 0 )
               : std::numeric_limits<T>::quiet_NaN();
}

#endif