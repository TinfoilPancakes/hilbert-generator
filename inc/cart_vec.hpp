/* ************************************************************************** */
/*                                                                            */
/*                                                   __                       */
/*   cart_vec.hpp                                  <(o )___                   */
/*                                                  ( ._> /   - Weh.          */
/*   By: prp <tfm357@gmail.com>                    --`---'-------------       */
/*                                                 54 69 6E 66 6F 69 6C       */
/*   Created: 2020/09/11 16:09:39 by prp              2E 54 65 63 68          */
/*   Updated: 2020/09/13 23:48:13 by prp              50 2E 52 2E 50          */
/*                                                                            */
/* ************************************************************************** */
#ifndef CART_VEC_HPP
#define CART_VEC_HPP

#include <cstdint>

template <typename T>
struct s_vec2 {
    T x = 0;
    T y = 0;
};

using vec2i = struct s_vec2<int>;

using vec2u8 = struct s_vec2<uint64_t>;

using vec2f = struct s_vec2<float>;

using vec2d = struct s_vec2<double>;

#endif