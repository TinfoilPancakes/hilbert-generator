/* ************************************************************************** */
/*                                                                            */
/*                                                   __                       */
/*   hilbert.hpp                                   <(o )___                   */
/*                                                  ( ._> /   - Weh.          */
/*   By: prp <tfm357@gmail.com>                    --`---'-------------       */
/*                                                 54 69 6E 66 6F 69 6C       */
/*   Created: 2020/09/13 23:40:49 by prp              2E 54 65 63 68          */
/*   Updated: 2020/09/13 23:45:59 by prp              50 2E 52 2E 50          */
/*                                                                            */
/* ************************************************************************** */
#ifndef TFPC_HILBERT_HPP
#define TFPC_HILBERT_HPP

#include <iostream>
#include <utility>

#include "inc/cart_vec.hpp"
#include "inc/cxpr_swap.hpp"

struct s_curve {
    // clang-format off
    vec2d map[4] = {
    	{ -0.25, -0.25 },
    	{ -0.25,  0.25 },
    	{  0.25,  0.25 },
    	{  0.25, -0.25 }
    };
    // clang-format on
    int current_iter = 1;

    constexpr void rotate_first() { cxpr_swap( map[1], map[3] ); }

    constexpr void rotate_last() { cxpr_swap( map[0], map[2] ); };

    constexpr vec2d step( uint8_t id ) {
        id &= 3;
        vec2d val = {map[id].x / current_iter, map[id].y / current_iter};
        current_iter *= 2;
        if ( id == 3 ) {
            rotate_last();
        } else if ( id == 0 ) {
            rotate_first();
        }
        return val;
    }
};

using hcurve = struct s_curve;

constexpr vec2d hilbert_idx_to_pos( uint64_t idx, uint32_t order ) {
    vec2d  pos = {0.5, 0.5};
    hcurve h;
    while ( order ) {
        uint64_t mask = 3 << ( ( order - 1 ) * 2 );
        uint64_t id   = ( idx & mask ) >> ( ( order - 1 ) * 2 );
        auto     step = h.step( id );
        pos.x += step.x;
        pos.y += step.y;
        order -= 1;
    }

    return pos;
}

#endif