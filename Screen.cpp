// C headers
#include <string.h>
#include <stdio.h>
#include <assert.h>

// CPP headers
#include "Screen.h"

Screen::Screen() {
    memset(data, ' ', HEIGHT * WIDTH);
}

// draw data to screen
void Screen::flip() {
    // clear previous screen
    for (int i = 0; i < HEIGHT; i++) {
        printf("\n");
    }

    // output data
    for (int r = 0; r < HEIGHT; r++) {
        printf("%.*s\n", WIDTH, data[r]);
    }

    // clear for next time
    memset(data, ' ', HEIGHT * WIDTH);
}

// draw sprite at row, col
void Screen::put(char** sprite, int row, int col, int height, int width) {
    // TODO: special empty character (maybe)
    // make sure it's within the bounds
    assert(row >= 0);
    assert(col >= 0);
    assert(row + height <= HEIGHT);
    assert(col + width <= WIDTH);

    for (int r = 0; r < height; r++) {
        memcpy(&data[row + r][col], sprite[r], width);
    }
}

void Screen::put(char sprite, int row, int col) {
    data[row][col] = sprite;
}
