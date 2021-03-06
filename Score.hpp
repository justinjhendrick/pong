#ifndef SCORE_H_
#define SCORE_H_

#include "Screen.hpp"

class Score {
    private:
        int p1;
        int p2;
        char* sprite;
        void update_sprite();
    public:
        Score();
        ~Score();
        void draw(Screen& s);
        void award_p1();
        void award_p2();
        int get_p1();
        int get_p2();
};

#endif
