#include "Ball.h"

Ball::Ball(int _r, int _c, int _rVel, int _cVel) {
    r = _r;
    c = _c;
    rVel = _rVel;
    cVel = _cVel;
}

void Ball::draw(Screen& s) {
    s.put('X', r, c);
}

void Ball::move() {
    r += rVel;
    c += cVel;
}

void Ball::changeVel(int _rVel, int _cVel) {
    rVel = _rVel;
    cVel = _cVel;
}

bool Ball::isColliding(Paddle& p) {
    int pr = p.getRow();
    int pc = p.getCol();
    return c == pc && r >= pr && r < pr + Paddle::HEIGHT;
}

void Ball::flipHorizDir() {
    cVel = -cVel;
}

void Ball::flipVertDir() {
    rVel = -rVel;
}
