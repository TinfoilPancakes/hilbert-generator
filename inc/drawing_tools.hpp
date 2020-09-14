#ifndef DRAWING_TOOLS_HPP
#define DRAWING_TOOLS_HPP

#include <functional>

#include "inc/cart_vec.hpp"

using plot_fn = std::function<void( vec2i )>;

void plot_line( vec2i p0, vec2i p1, const plot_fn& plot ) {
    vec2f s;
    vec2i delta;
    bool  inverted = false;

    delta = { p1.x - p0.x, p1.y - p0.y };
    if ( abs( delta.x ) < abs( delta.y ) ) {
        delta    = { delta.y, delta.x };
        inverted = true;
        p0       = { p0.y, p0.x };
    }
    s = { -1, (float)delta.y / delta.x };
    while ( delta.x != 0 ) {
        s.x += ( s.y < 0 ) ? -s.y : s.y;
        if ( s.x >= 0 ) {
            s.x -= 1;
            p0.y += ( delta.y < 0 ) ? -1 : 1;
        }
        if ( inverted )
            plot( { p0.y, p0.x } );
        else
            plot( p0 );
        p0.x += ( delta.x < 0 ) ? -1 : 1;
        delta.x += ( delta.x < 0 ) ? 1 : -1;
    }
}

#endif