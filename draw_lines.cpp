#include <iostream>
#include <vector>

#include "3p/tinypng/TinyPngOut.hpp"
#include "inc/cart_vec.hpp"
#include "inc/drawing_tools.hpp"

struct s_color {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

using color = struct s_color;

int main( int ac, char* av[] ) {
    // draw lines :)
    if ( ac < 3 ) {
        return 1;
    }

    auto width  = std::stoul( av[1] );
    auto height = std::stoul( av[2] );

    std::vector<color> img_buffer;
    img_buffer.resize( width * height );

    auto plot = [&img_buffer, width, height]( vec2i p ) {
        uint64_t idx      = ( p.x + width * p.y );
        img_buffer[idx].r = 0xFF;
    };

    vec2i last_pos;
    vec2i curr_pos;
    vec2f b;
    bool  is_first = true;
    while ( std::cin.read( (char*)&b.x, sizeof( float ) ) &&
            std::cin.read( (char*)&b.y, sizeof( float ) ) ) {
        curr_pos.x = b.x * width;
        curr_pos.y = b.y * height;

        if ( is_first ) {
            last_pos = curr_pos;
            is_first = false;
            continue;
        }

        plot_line( last_pos, curr_pos, plot );
        last_pos = curr_pos;
    }

    TinyPngOut output( width, height, std::cout );
    output.write( (uint8_t*)img_buffer.data(), width * height );

    return 0;
}
