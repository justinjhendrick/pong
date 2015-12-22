#include "TerminalToggle.hpp"
#include <termios.h>
#include <unistd.h>

TerminalToggle::TerminalToggle() {
    tcgetattr(STDIN_FILENO, &t); 
}
    
void TerminalToggle::off(unsigned int flag) {
    t.c_lflag &= ~flag;
    // apply the new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void TerminalToggle::on(unsigned int flag) {
    t.c_lflag |= flag;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void TerminalToggle::buffer_off() {
    off(ICANON);
}

void TerminalToggle::buffer_on() {
    on(ICANON);
}

void TerminalToggle::echo_off() {
    off(ECHO);
}

void TerminalToggle::echo_on() {
    on(ECHO);
}
