#include <iostream>
#include <conio.h>
#include "draw.h"
#include "player.h"

using namespace std;

Draw::Draw()
{

}

void Draw::setHeigth(int height)
{
    this->heigth = height;
}

void Draw::setWidth(int width)
{
    this->width = width;
}

void Draw::setPlayerX(int x)
{
    this->playerX = x;
}

void Draw::setPlayerY(int y)
{
    this->playerY = y;
}

int Draw::getPlayerX()
{
    return playerX;
}

int Draw::getPlayerY()
{
    return playerY;
}

void Draw::setScoreX()
{
    int temp = rand() % width;
    if (temp == 1)
    {
        this->scoreX = temp + 1;
    }
    else if (temp == width)
    {
        this->scoreX = temp -1 ;
    }
    else
    {
        this->scoreX = temp;
    }
    
}

void Draw::setScoreY()
{
    int temp = rand() % heigth;
    if (temp == 1)
    {
        this->scoreY = temp + 1;
    }
    else if (temp == heigth)
    {
        this->scoreY = temp -1 ;
    }
    else
    {
        this->scoreY = temp;
    }
}

void Draw::setEnemyX()
{
    this->enemy1X = rand() % width;
}

void Draw::setEnemyY()
{
    this->enemy1Y = 0;
}

int Draw::getScoreX()
{
    return scoreX;
}

int Draw::getScoreY()
{
    return scoreY;
}


void Draw::draw()
{
    system("CLS");

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }
            else if (i == playerY && j == playerX)
            {
                cout << "H";
            }
            else if(i == scoreY && j == scoreX)
            {
                cout << "O";
            }
            else if(i == enemy1Y && j == enemy1X)
            {
                cout << "X";
            }
            else
            {
                cout << " ";
            }

            if (j == width-1)
            {
                cout << "#";
            }

            
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;


}

void Draw::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;
        
        case 'w':
             dir = UP;
             break;

        case 's':
            dir = DOWN;
            break;
    
        }
    }
}

void Draw::movePlayer()
{
    switch (dir)
    {
        case LEFT:
        setPlayerX(getPlayerX() - 1);
        break;

        case RIGHT:
        setPlayerX(getPlayerX() + 1);
        break;

        case UP:
        setPlayerY(getPlayerY() - 1);
        break;

        case DOWN:
        setPlayerY(getPlayerY() + 1);
        break;
    }
}

void Draw::collectScore()
{
    if (playerX == scoreX && playerY == scoreY)
    {
        Player::addPoints();
        setScoreX();
        setScoreY();
    }
    
}

void Draw::moveEnemy()
{
  
    enemy1Y++;
    if(enemy1Y == heigth)
    {
        enemy1Y = 0;
        enemy1X = rand() % width;
    }
    else if(enemy1X == playerX && enemy1Y == playerY)
    {
        Player::isAlive = false;
    }
    else if(playerX == heigth || playerY == width || playerX == 0 || playerY == 0)
    {
        Player::isAlive = false;
    }
    
    
}