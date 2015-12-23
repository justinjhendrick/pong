#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Screen.hpp"

Screen::Screen() {
    memset(data, ' ', HEIGHT * WIDTH);
}

// draw data to screen
void Screen::flip() {
    // output data
    for (int r = 0; r < HEIGHT; r++) {
        printf("%.*s\n", WIDTH, data[r]);
    }

    // clear for next time
    memset(data, ' ', HEIGHT * WIDTH);
}

// draw sprite at row, col
void Screen::put(char** sprite, int row, int col, int height, int width) {
    // make sure it's within the screen boundary
    assert(row >= 0);
    assert(col >= 0);
    assert(row + height <= HEIGHT);
    assert(col + width <= WIDTH);

    // copy into screen data
    for (int r = 0; r < height; r++) {
        memcpy(data[row + r] + col, sprite[r], width);
    }
}

void Screen::put(char sprite, int row, int col) {
    assert(row >= 0);
    assert(col >= 0);
    assert(row < HEIGHT);
    assert(col < WIDTH);

    data[row][col] = sprite;
}
