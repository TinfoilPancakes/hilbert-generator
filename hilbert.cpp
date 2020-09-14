/* ************************************************************************** */
/*                                                                            */
/*                                                   __                       */
/*   hilbert.cpp                                   <(o )___                   */
/*                                                  ( ._> /   - Weh.          */
/*   By: prp <tfm357@gmail.com>                    --`---'-------------       */
/*                                                 54 69 6E 66 6F 69 6C       */
/*   Created: 2020/09/11 21:56:28 by prp              2E 54 65 63 68          */
/*   Updated: 2020/09/13 23:47:49 by prp              50 2E 52 2E 50          */
/*                                                                            */
/* ************************************************************************** */
#include <cmath>
#include <iostream>

// #include "hilbert_curve.hpp"
#include "hilbert.hpp"

constexpr auto argument_text = R"--(
Descirption:
    Maps a given number of indices evenly over a hilbert curve of specified
    order. By default outputs 32-bit IEEE-754 floats to stdout.

Arguments:
    indices: Number of coordinates to generate.
    order: The square grid dimension of the pseudo-hilbert curve to map.

Options:
    -json: Output coordinates as json formatted text.
           eg: {"x": 0.25, "y": 0.75}

     -csv: Output coordinates as comma seperated values (CSV).
           eg: 0.25,0.75

     -f64: Output as 64-bit IEEE-754 floats.
)--";

void print_usage( char** av ) {
    std::cerr << "Usage: " << av[0] << " <indices> <order> [options]\n";
    std::cerr << argument_text;
}

void write_f32( vec2d c ) {
    vec2f output = {float( c.x ), float( c.y )};
    // std::cerr << output.x << " x " << output.y << "\n";
    std::cout.write( (char*)&output.x, sizeof( output.x ) );
    std::cout.write( (char*)&output.y, sizeof( output.y ) );
}

void write_f64( vec2d c ) {
    std::cout.write( (char*)&c.x, sizeof( c.x ) );
    std::cout.write( (char*)&c.y, sizeof( c.y ) );
}

void write_csv( vec2d c ) { std::cout << c.x << "," << c.y << "\n"; }

void write_json( vec2d c ) {
    std::cout << "{\"x\":" << c.x << ",\"y\":" << c.y << "}\n";
}

int main( int ac, char* av[] ) {
    if ( ac < 3 ) {
        print_usage( av );
        return 0;
    }

    auto indices = std::stoi( av[1] );
    auto order   = std::stoi( av[2] );

    auto print_fn = &write_f32;

    if ( ac > 3 ) {
        std::string arg( av[3] );
        if ( arg == "-json" ) {
            print_fn = &write_json;
        } else if ( arg == "-csv" ) {
            print_fn = &write_csv;
        } else if ( arg == "-f64" ) {
            print_fn = &write_f64;
        } else {
            std::cerr << "Unknown option: " << arg << "\n";
            std::cerr << "Falling back to default...\n";
        }
    }

    auto side_len    = std::pow( 2, order );
    auto max_indices = side_len * side_len;

    if ( indices > max_indices )
        std::cerr << "Warning: indices will overlap due to low order curve.\n";

    for ( int i = 0; i < indices; ++i ) {
        double   d     = double( i ) / double( indices );
        uint64_t iter  = d * max_indices;
        auto     coord = hilbert_idx_to_pos( iter, order );
        print_fn( coord );
    }

    return 0;
}