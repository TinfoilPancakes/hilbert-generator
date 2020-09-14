# **************************************************************************** #
#                                                                              #
#                                                    __                        #
#    makefile                                      <(o )___                    #
#                                                   ( ._> /   - Weh.           #
#    By: prp <tfm357@gmail.com>                    --`---'-------------        #
#                                                  54 69 6E 66 6F 69 6C        #
#    Created: 2020/09/11 16:09:39 by prp              2E 54 65 63 68           #
#    Updated: 2020/09/14 00:17:24 by prp              50 2E 52 2E 50           #
#                                                                              #
# **************************************************************************** #
CC := c++ -std=c++17

all: draw_lines hilbert_plot

hilbert_plot: hilbert.cpp
	$(CC) -O3 -I ./inc -I . $^ -o $@

draw_lines: draw_lines.cpp 3p/tinypng/TinyPngOut.cpp
	$(CC) -O3 -I . $^ -o $@

clean:
	rm hilbert_plot
	rm draw_lines

re: clean draw_lines hilbert_plot