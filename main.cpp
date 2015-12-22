#include <unistd.h>
#include <cstdio>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Screen.hpp"
#include "Keyboard.hpp"
// TODO
//#include "Score.h"

#define P1_UP 'w'
#define P1_DOWN 'd'
#define P2_UP 'o'
#define P2_DOWN 'k'

int main() {
    Screen s;
    Score score;
    // start ball at top left moving right
    Ball b(0, 1, 0, 1);
    Paddle p1(0, 0);
    Paddle p2(0, Screen::WIDTH - 1);

    b.draw(s);
    p1.draw(s);
    p2.draw(s);
    s.flip();

    Keyboard kb;
    kb.start();

    while (true) {
        // read all queued keypresses and move paddles
        int c;
        for (c = kb.get(); c != -1; c = kb.get()) {
            if (c == 'x') {
                break;
            }
            if (c == P1_UP) {
                p1.move(-1);
            } else if (c == P1_DOWN) {
                p1.move(1);
            } else if (c == P2_UP) {
                p2.move(-1);
            } else if (c == P2_DOWN) {
                p2.move(1);
            }
        }

        // b.move handles collisions
        bool point_made = b.move(p1, p2, score);
        if (point_made) {
            b.set_pos_vel(0, 1, 0, 1);
        }
            
        // draw
        score.draw(s);
        b.draw(s);
        p1.draw(s);
        p2.draw(s);
        s.flip();
        usleep(100000);
    }
    // TODO: free memory
}
