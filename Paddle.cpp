#include <stdlib.h>
#include "Paddle.h"

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

int Paddle::getRow() {
    return r;
}

int Paddle::getCol() {
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
    b.flipHorizDir();
}
