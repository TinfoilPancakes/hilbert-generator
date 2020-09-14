/* ************************************************************************** */
/*                                                                            */
/*                                                   __                       */
/*   cxpr_swap.hpp                                 <(o )___                   */
/*                                                  ( ._> /   - Weh.          */
/*   By: prp <tfm357@gmail.com>                    --`---'-------------       */
/*                                                 54 69 6E 66 6F 69 6C       */
/*   Created: 2020/09/11 16:09:39 by prp              2E 54 65 63 68          */
/*   Updated: 2020/09/13 23:48:09 by prp              50 2E 52 2E 50          */
/*                                                                            */
/* ************************************************************************** */
#ifndef CXPR_SWAP_HPP
#define CXPR_SWAP_HPP

template <typename T>
constexpr void cxpr_swap( T&& a, T&& b ) {
    auto tmp = a;
    a        = b;
    b        = tmp;
}

#endif