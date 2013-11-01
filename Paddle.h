class Paddle {
    private:
        int x;
        int y;
    public:
        Paddle(int, int);
        void draw();
        void move(int);
        void Bounce(Ball);
}
