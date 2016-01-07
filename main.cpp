#include <unistd.h>
#include <cstdio>
#include <cmath>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Screen.hpp"
#include "Keyboard.hpp"
#include "Score.hpp"

#define P1_UP 'w'
#define P1_DOWN 'd'
#define P2_UP 'o'
#define P2_DOWN 'k'

#define INIT_SLEEP 60000
#define SLEEP_DECREMENT 100
#define MIN_SLEEP 20000
#define WINNING_SCORE 10

int main() {
    Screen s;
    Score score;
    Ball b((float) (Screen::HEIGHT / 2), (float) (Screen::WIDTH / 2), 0., 1.);
    int init_paddle_height = Screen::HEIGHT / 2 - Paddle::HEIGHT / 2;
    Paddle p1(init_paddle_height, 0);
    Paddle p2(init_paddle_height, Screen::WIDTH - 1);

    b.draw(s);
    p1.draw(s);
    p2.draw(s);
    s.flip();

    Keyboard kb;

    unsigned int sleep_micros = INIT_SLEEP;

    while (true) {
        // read all queued keypresses and move paddles
        int c;
        for (c = kb.get(); c != -1; c = kb.get()) {
            if (c == 'x') {
                return 0;
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
        int point = b.move(p1, p2);
        if (point != 0) {
            float new_ball_angle = 0.;
            if (point == -1) {
                score.award_p1();
                new_ball_angle = 0.;
            } else if (point == 1) {
                score.award_p2();
                new_ball_angle = M_PI;
            }
            if (score.get_p1() == WINNING_SCORE) {
                printf("P1 WINS!\n");
                return 0;
            } else if (score.get_p2() == WINNING_SCORE) {
                printf("P2 WINS!\n");
                return 0;
            }
            sleep_micros = INIT_SLEEP;
            b.set_pos_vel((float) (Screen::HEIGHT / 2),
                          (float) (Screen::WIDTH / 2),
                          new_ball_angle, 1.);
        }
            
        // draw
        score.draw(s);
        b.draw(s);
        p1.draw(s);
        p2.draw(s);
        s.flip();
        usleep(sleep_micros);

        sleep_micros -= SLEEP_DECREMENT;
        if (sleep_micros < MIN_SLEEP) {
            sleep_micros = MIN_SLEEP;
        }
    }
}
