#include "Ball.hpp"
#include "Score.hpp"
#include "Paddle.hpp"
#include <cmath>
#include <stdio.h>

Ball::Ball(float _r, float _c, float _angle, float _magnitude) {
    set_pos_vel(_r, _c, _angle, _magnitude);
}
    
void Ball::set_pos_vel(float _r, float _c, float _angle, float _magnitude) {
    r = _r;
    c = _c;
    angle = _angle;
    magnitude = _magnitude;
}

void Ball::draw(Screen& s) {
    float decimal = r - floor(r);
    char sprite;
    if (decimal < .33) {
        sprite = '\'';
    } else if (decimal > .66) {
        sprite = '.';
    } else {
        sprite = '-';
    }

    s.put(sprite, (int) floor(r), (int) floor(c));
}

// returns -1 if p1 scored,
//         0  if nobody scored,      
//         1  if p2 scored
int Ball::move(Paddle& p1, Paddle& p2) {
    float r_vel = magnitude * sin(angle);
    float c_vel = magnitude * cos(angle);
    r += r_vel;
    c += c_vel;
    
    // paddles hit?
    if (is_colliding(p1)) {
        bounce(p1);
        return 0;
    } else if (is_colliding(p2)) {
        bounce(p2);
        return 0;
    }

    int ir = (int) floor(r);
    int ic = (int) floor(c);
    // hit wall?
    if (ir < 0 || ir >= Screen::HEIGHT) {
        r -= r_vel;
        c -= c_vel;
        flip_vert_dir();
        r_vel = magnitude * sin(angle);
        c_vel = magnitude * cos(angle);
        r += r_vel;
        c += c_vel;
        return 0;
    }

    // point scored?
    if (ic < 0) {
        return 1;
    } else if (ic >= Screen::WIDTH) {
        return -1;
    }
    return 0;
}

bool Ball::is_colliding(Paddle& p) {
    int pr = p.row();
    int pc = p.col();
    int ir = (int) floor(r);
    int ic = (int) floor(c);
    return ic == pc && ir >= pr && ir < pr + Paddle::HEIGHT;
}

void Ball::flip_vert_dir() {
    angle = 2 * M_PI - angle;
}

void Ball::normalize_angle() {
    if (angle < 0.) {
        angle += 2 * M_PI;
    } else if (angle > 2 * M_PI) {
        angle -= 2 * M_PI;
    }
}

void Ball::bounce(Paddle& p) {
    int pr = p.row();
    int pc = p.col();
    angle = -M_PI_4 + M_PI_2 / Paddle::HEIGHT * (r - pr);
    normalize_angle();

    if (pc != 0) {
        angle = M_PI - angle;
    }
    normalize_angle();

    //magnitude += .25;
}
