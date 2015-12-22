#ifndef BALL_H_
#define BALL_H_

class Ball;

#include "Screen.hpp"
#include "Paddle.hpp"
#include "Score.hpp"

class Ball {
    private:
        int r;
        int c;
        int r_vel;
        int c_vel;
        bool is_colliding(Paddle& p);
    public:
        Ball(int _r, int _c, int _r_vel, int _c_vel);
        void set_pos_vel(int _r, int _c, int _r_vel, int _c_vel);
        void draw(Screen& s);
        bool move(Paddle& p1, Paddle& p2, Score& score);
        void change_vel(int _r_Vel, int _c_vel);
        void flip_horiz_dir();
        void flip_vert_dir();
        void bounce(Paddle& p);
};

#endif
