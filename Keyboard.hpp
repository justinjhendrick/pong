#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include "TerminalToggle.hpp"

// Interface for keyboard IO
class Keyboard {
    private:
        TerminalToggle terminal;
        boost::lockfree::queue<int> chars;
        boost::thread reader_thread;
        void read();
    public:
        Keyboard();
        // non-blocking get
        int get();
        ~Keyboard();
};

#endif
