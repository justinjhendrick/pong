#include <stdlib.h>
#include "Paddle.hpp"

Paddle::Paddle(int _r, int _c) {
    r = _r;
    c = _c;

    sprite = (wchar_t**) malloc(HEIGHT * sizeof(wchar_t*));
    // initialize the sprite
    for (int i = 0; i < HEIGHT; i++) {
        sprite[i] = (wchar_t*) malloc(sizeof(wchar_t));
        sprite[i][0] = '|';
    }
}

int Paddle::row() {
    return r;
}

int Paddle::col() {
    return c;
}

void Paddle::draw(Screen& s) {
    s.put(sprite, r, c, HEIGHT, WIDTH);
}

void Paddle::move(int magnitude) {
    int new_r = r + magnitude;
    if (new_r >= 0 && new_r + HEIGHT <= Screen::HEIGHT) {
        r = new_r;
    }
}

Paddle::~Paddle() {
    for (int i = 0; i < HEIGHT; i++) {
        free(sprite[i]);
    }
    free(sprite);
}
