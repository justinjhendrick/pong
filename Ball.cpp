#include "Ball.hpp"
#include "Score.hpp"
#include "Paddle.hpp"

Ball::Ball(int _r, int _c, int _r_vel, int _c_vel) {
    set_pos_vel(_r, _c, _r_vel, _c_vel);
}
    
void Ball::set_pos_vel(int _r, int _c, int _r_vel, int _c_vel) {
    r = _r;
    c = _c;
    r_vel = _r_vel;
    c_vel = _c_vel;
}

void Ball::draw(Screen& s) {
    s.put('X', r, c);
}

// moves ball. updates score
// returns true if a point was scored
bool Ball::move(Paddle& p1, Paddle& p2, Score& score) {
    r += r_vel;
    c += c_vel;
    if (is_colliding(p1)) {
        bounce(p1);
        return false;
    } else if (is_colliding(p2)) {
        bounce(p2);
        return false;
    }

    if (c < 0) {
        score.award_p2();
        return true;
    } else if (c >= Screen::WIDTH) {
        score.award_p1();
        return true;
    }

    if (r >= 0 || r <= Screen::HEIGHT) {
        flip_vert_dir();
        return false;
    }
    return false;
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

void Ball::bounce(Paddle& p) {
    // TODO
    flip_horiz_dir();
}
