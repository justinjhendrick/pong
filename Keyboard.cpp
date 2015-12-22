#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <cstdio>
#include "Keyboard.hpp"
#include "TerminalToggle.hpp"

Keyboard::Keyboard() : chars(256) {
    // disable terminal buffering
    // keyboard input doesn't need to wait for enter
    terminal.buffer_off();
    terminal.echo_off();
    //chars(256);
}

void Keyboard::start() {
    boost::thread reader_thread(&Keyboard::read, this);
}

void Keyboard::read() {
    while (true) {
        int c = std::getchar();
        chars.push(c);
    }
}

int Keyboard::get() {
    int x = -1;
    int& result = x;
    chars.pop(result);
    return x;
}

Keyboard::~Keyboard() {
    // TODO
    terminal.buffer_on();
    terminal.echo_on();
}
