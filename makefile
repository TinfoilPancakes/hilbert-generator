CC := c++

hilbert_plot: hilbert.cpp
	$(CC) -O3 -I ./inc -I . $^ -o $@

draw_lines: draw_lines.cpp 3p/tinypng/TinyPngOut.cpp
	$(CC) -O3 -I . $^ -o $@

clean:
	rm hilbert_plot
	rm draw_lines

re: clean draw_lines hilbert_plot