#ifndef BALL_H_
#define BALL_H_

class Ball;

#include "Screen.hpp"
#include "Paddle.hpp"

class Ball {
    private:
        int r;
        int c;
        int r_vel;
        int c_vel;
    public:
        Ball(int _r, int _c, int _r_vel, int _c_vel);
        void draw(Screen& s);
        void move();
        void change_vel(int _r_Vel, int _c_vel);
        bool is_colliding(Paddle& p);
        void flip_horiz_dir();
        void flip_vert_dir();
};

#endif
