#ifndef SCREEN_H_
#define SCREEN_H_

class Screen {
    public:
        static const int HEIGHT = 24;
        static const int WIDTH = 80;

    private:
        wchar_t data[HEIGHT][WIDTH];

    public:
        Screen();

        // draw data to screen
        void flip();

        // draw sprite at row, col
        void put(wchar_t** sprite, int row, int col, int width, int height);

        // draw a one character sprite
        void put(wchar_t sprite, int row, int col);
};

#endif
