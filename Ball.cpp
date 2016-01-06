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
    float r_down = floor(r);
    wchar_t sprite;
    if (r - r_down < .33) {
        sprite = '\u02D9';
    } else if (r - r_down > .66) {
        sprite = '\u0358';
    } else {
        sprite = '\u00B7';
    }
    
    s.put(sprite, (int) r_down, (int) floor(c));
}

// moves ball. updates score
// returns true if a point was scored
bool Ball::move(Paddle& p1, Paddle& p2, Score& score) {
    float r_vel = magnitude * sin(angle);
    float c_vel = magnitude * cos(angle);
    r += r_vel;
    c += c_vel;
    
    // paddles hit?
    if (is_colliding(p1)) {
        bounce(p1);
        return false;
    } else if (is_colliding(p2)) {
        bounce(p2);
        return false;
    }

    int ir = (int) floor(r);
    int ic = (int) floor(c);
    // point scored?
    if (ic < 0) {
        score.award_p2();
        return true;
    } else if (ic >= Screen::WIDTH) {
        score.award_p1();
        return true;
    }

    // hit wall?
    if (ir < 0 || ir >= Screen::HEIGHT) {
        r -= r_vel;
        flip_vert_dir();
        return false;
    }
    return false;
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
