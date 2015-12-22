#include <unistd.h>
#include <cstdio>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Screen.hpp"
#include "Keyboard.hpp"
// TODO
//#include "Score.h"

int main() {
    Screen s;
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
        int c = kb.get();
        if (c == 'x') {
            break;
        }

        b.move();
        if (b.is_colliding(p1)) {
            p1.bounce(b);
        } else if (b.is_colliding(p2)) {
            p2.bounce(b);
        }
            
        // draw
        b.draw(s);
        p1.draw(s);
        p2.draw(s);
        s.flip();
        usleep(100000);
    }
    // TODO: free memory
}
