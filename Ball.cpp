#include "Ball.hpp"

Ball::Ball(int _r, int _c, int _r_vel, int _c_vel) {
    r = _r;
    c = _c;
    r_vel = _r_vel;
    c_vel = _c_vel;
}

void Ball::draw(Screen& s) {
    s.put('X', r, c);
}

void Ball::move() {
    r += r_vel;
    c += c_vel;
}

void Ball::change_vel(int _r_vel, int _c_vel) {
    r_vel = _r_vel;
    c_vel = _c_vel;
}

bool Ball::is_colliding(Paddle& p) {
    int pr = p.row();
    int pc = p.col();
    return c == pc && r >= pr && r < pr + Paddle::HEIGHT;
}

void Ball::flip_horiz_dir() {
    c_vel = -c_vel;
}

void Ball::flip_vert_dir() {
    r_vel = -r_vel;
}
