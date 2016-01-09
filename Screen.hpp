#ifndef SCREEN_H_
#define SCREEN_H_

class Screen {
    public:
        static int HEIGHT;
        static int WIDTH;

    private:
        char** data;
        void clear(); // fill screen with ' '

    public:
        Screen();
        ~Screen();

        // draw data to screen
        void flip();

        // draw sprite at row, col
        void put(char** sprite, int row, int col, int width, int height);

        // draw a one character sprite
        void put(char sprite, int row, int col);
};

#endif
