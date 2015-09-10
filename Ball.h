#ifndef BALL_H_
#define BALL_H_

class Ball;

#include "Screen.h"
#include "Paddle.h"

class Ball {
    private:
        int r;
        int c;
        int rVel;
        int cVel;
    public:
        Ball(int _r, int _c, int _rVel, int _Vel);
        void draw(Screen& s);
        void move();
        void changeVel(int _rVel, int _cVel);
        bool isColliding(Paddle& p);
        void flipHorizDir();
        void flipVertDir();
};

#endif
