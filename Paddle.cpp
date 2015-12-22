#include <stdlib.h>
#include "Paddle.hpp"

Paddle::Paddle(int _r, int _c) {
    r = _r;
    c = _c;

    sprite = (char**) malloc(HEIGHT * sizeof(char*));
    // initialize the sprite
    for (int i = 0; i < HEIGHT; i++) {
        sprite[i] = (char*) malloc(sizeof(char));
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
    r += magnitude;
}

void Paddle::bounce(Ball& b) {
    // TODO
    b.flip_horiz_dir();
}
