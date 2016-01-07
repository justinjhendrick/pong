#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Score.hpp"
#include "Screen.hpp"

#define BOARD_LEN 11

Score::Score() {
    p1 = 0;
    p2 = 0;

    sprite = (char*) malloc(BOARD_LEN);
    sprite[0]  = '0';
    sprite[1]  = '0';
    sprite[2]  = ' ';
    sprite[3]  = 'S';
    sprite[4]  = 'C';
    sprite[5]  = 'O';
    sprite[6]  = 'R';
    sprite[7]  = 'E';
    sprite[8]  = ' ';
    sprite[9]  = '0';
    sprite[10] = '0';
}

void Score::draw(Screen& s) {
    s.put(&sprite,
          0, (Screen::WIDTH - BOARD_LEN) / 2,
          1, BOARD_LEN);
}

void Score::update_sprite() {
    snprintf(sprite, BOARD_LEN + 1, "%02d SCORE %02d", p1, p2);
}

void Score::award_p1() {
    p1++;
    update_sprite();
}

void Score::award_p2() {
    p2++;
    update_sprite();
}

int Score::get_p1() {
    return p1;
}

int Score::get_p2() {
    return p2;
}

Score::~Score() {
    free(sprite);
}
