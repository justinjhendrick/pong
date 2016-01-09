#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "Screen.hpp"

int Screen::HEIGHT = 0;
int Screen::WIDTH = 0;

Screen::Screen() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    HEIGHT = w.ws_row - 1;
    WIDTH = w.ws_col;

    data = (char**) malloc(HEIGHT * sizeof(char*));
    for (int i = 0; i < HEIGHT; i++) {
        data[i] = (char*) malloc(WIDTH * sizeof(char));
    }
    clear();
}

void Screen::clear() {
    for (int i = 0; i < HEIGHT; i++) {
        memset(data[i], ' ', WIDTH);
    }
}

// draw data to screen
void Screen::flip() {
    // output data to terminal
    for (int r = 0; r < HEIGHT; r++) {
        printf("%.*s\n", WIDTH, data[r]);
    }
    // reset for next frame
    clear();
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

Screen::~Screen() {
    for (int i = 0; i < HEIGHT; i++) {
        free(data[i]);
    }
    free(data);
}
