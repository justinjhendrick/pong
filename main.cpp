#include <unistd.h>
#include "Ball.h"
#include "Paddle.h"
// TODO
//#include "Score.h"
#include "Screen.h"

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

    while (true) {
        // get input
        b.move();
        if (b.isColliding(p1)) {
            p1.bounce(b);
        } else if (b.isColliding(p2)) {
            p2.bounce(b);
        }
            
        // draw
        b.draw(s);
        p1.draw(s);
        p2.draw(s);
        s.flip();
        usleep(100000);
    }
}
