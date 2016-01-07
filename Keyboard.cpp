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
    int c = -1;
    int& ref = c;
    chars.pop(ref);
    return c;
}

Keyboard::~Keyboard() {
    terminal.buffer_on();
    terminal.echo_on();
}
