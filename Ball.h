class Ball {
    private:
        int x; //position
        int y;
        int xDir; //direction
        int yDir;
    public:
        Ball(int, int);
        void draw();
        void move();
        void changeDir(int, int);
        void flipX();
        void flipY();
}
