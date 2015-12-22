#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <boost/lockfree/queue.hpp>
#include "TerminalToggle.hpp"

// Interface for keyboard IO
class Keyboard {
    private:
        TerminalToggle terminal;
        boost::lockfree::queue<int> chars;
        void read();
    public:
        Keyboard();
        void start();
        // non-blocking get
        int get();
        ~Keyboard();
};

#endif
