#ifndef PADDLE_H_
#define PADDLE_H_

class Paddle;

#include "Ball.hpp"
#include "Screen.hpp"

class Paddle {
    private:
        int r;
        int c;
        char** sprite;
    public:
        static const int HEIGHT = 8;
        static const int WIDTH = 1;
        Paddle(int, int);
        ~Paddle();
        int row();
        int col();
        void draw(Screen& s);
        void move(int);
};

#endif
