#ifndef BALL_H_
#define BALL_H_

class Ball;

#include "Screen.hpp"
#include "Paddle.hpp"
#include "Score.hpp"

class Ball {
    private:
        float r;
        float c;
        float angle; // in radians clockwise from the c axis
        float magnitude; // in blocks per screen flip
        bool is_colliding(Paddle& p);
        // keep angle within 0 .. 2pi
        void normalize_angle();
    public:
        Ball(float _r, float _c, float _angle, float _magnitude);
        void set_pos_vel(float _r, float _c, float _angle, float _magnitude);
        void draw(Screen& s);
        bool move(Paddle& p1, Paddle& p2, Score& score);
        void flip_vert_dir();
        void bounce(Paddle& p);
};

#endif
