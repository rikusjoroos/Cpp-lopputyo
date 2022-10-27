#ifndef DRAW_H
#define DRAW_H

class Draw
{
    private:
    int heigth;
    int width;
    int playerX;
    int playerY;
    int scoreX;
    int scoreY;
    int enemy1X;
    int enemy1Y;

    public:
    enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
    Direction dir;
    Draw();
    void setHeigth(int height);
    void setWidth(int width);
    void setPlayerX(int x);
    void setPlayerY(int y);
    int getPlayerX();
    int getPlayerY();
    void setScoreX();
    void setScoreY();
    int getScoreX();
    int getScoreY();
    void draw();
    void input();
    void movePlayer();
    void collectScore();
    void setEnemyX();
    void setEnemyY();
    void moveEnemy();
};

#endif