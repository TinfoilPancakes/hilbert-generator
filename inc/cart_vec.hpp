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