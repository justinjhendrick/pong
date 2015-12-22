#ifndef TERMINALTOGGLE_H_
#define TERMINALTOGGLE_H_

#include <termios.h>
class TerminalToggle {
    private:
        struct termios t;
        void off(unsigned int flag);
        void on(unsigned int flag);

    public:
        TerminalToggle();
        void buffer_off();
        void buffer_on();
        void echo_off();
        void echo_on();
};

#endif
