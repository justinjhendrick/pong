#ifndef PADDLE_H_
#define PADDLE_H_

class Paddle;

#include "Ball.h"
#include "Screen.h"

class Paddle {
    private:
        int r;
        int c;
        char** sprite;
    public:
        static const int HEIGHT = 10;
        static const int WIDTH = 1;
        Paddle(int, int);
        int getRow();
        int getCol();
        void draw(Screen& s);
        void move(int);
        void bounce(Ball&);
};

#endif
