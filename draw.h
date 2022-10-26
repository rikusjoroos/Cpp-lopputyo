#ifndef DRAW_H
#define DRAW_H

class Draw
{
    private:
    int heigth;
    int width;
    int playerX;
    int playerY;

    public:
    Draw();
    void setHeigth(int height);
    void setWidth(int width);
    void setPlayerX(int x);
    void setPlayerY(int y);
    int getPlayerX();
    int getPlayerY();
    void draw();
};

#endif