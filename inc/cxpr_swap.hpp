#ifndef CXPR_SWAP_HPP
#define CXPR_SWAP_HPP

template <typename T>
constexpr void cxpr_swap( T&& a, T&& b ) {
    auto tmp = a;
    a        = b;
    b        = tmp;
}

#endif