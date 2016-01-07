#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <cstdio>
#include "Keyboard.hpp"
#include "TerminalToggle.hpp"

Keyboard::Keyboard() : chars(256), reader_thread(&Keyboard::read, this) {
    // disable terminal buffering
    // keyboard input doesn't need to wait for enter
    terminal.buffer_off();
    terminal.echo_off();
}

void Keyboard::read() {
    while (true) {
        int c = std::getchar();
        chars.push(c);
        if (c == 'x') {
            return;
        }
    }
}

int Keyboard::get() {
    int x = -1;
    int& result = x;
    chars.pop(result);
    return x;
}

Keyboard::~Keyboard() {
    //reader_thread.interrupt();
    //// if reader_thread is blocking inside getchar(),
    //// it won't reach the interruption point.
    //// So, we give it another character so it'll break out.
    //std::ungetc('x', stdin);
    //reader_thread.join();
    terminal.buffer_on();
    terminal.echo_on();
}
