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

void Draw::setScoreX() //tässä arvotaan hedelmälle koordinaatti X
{
    int temp = rand() % width;
    if (temp == 1)
    {
        this->scoreX = temp + 1;
    }
    else if (temp == width)
    {
        this->scoreX = temp - 1 ;
    }
    else
    {
        this->scoreX = temp;
    }
    
}

void Draw::setScoreY() //tässä arvotaan hedelmälle koordinaatti Y
{
    int temp = rand() % heigth;
    if (temp == 1)
    {
        this->scoreY = temp + 1;
    }
    else if (temp == heigth)
    {
        this->scoreY = temp - 1 ;
    }
    else
    {
        this->scoreY = temp;
    }
}

void Draw::setEnemy1X() //tässä arvotaan viholliselle koordinaatti X
{
    int temp;
    temp = rand() % width;
    if (temp < 1)
    {
        this->enemy1X = 2;
    }
    else if (temp >= width)
    {
        this->enemy1X = width - 2;
    }
    else
    {
        this->enemy1X = temp;
    }
    
}

void Draw::setEnemy1Y() //tässä arvotaan viholliselle koordinaatti Y
{
    int temp;
    temp = rand() % heigth;
    if (temp < 1)
    {
        this->enemy1Y = 2;
    }
    else if (temp >= heigth)
    {
        this->enemy1Y = heigth - 2;
    }
    else
    {
        this->enemy1Y = temp;
    }
}

int Draw::getEnemy1X() 
{
    return enemy1X;
}

int Draw::getEnemy1Y()
{
    return enemy1Y;
}

int Draw::getScoreX()
{
    return scoreX;
}

int Draw::getScoreY()
{
    return scoreY;
}

int Draw::getHeigth()
{
    return heigth;
}

int Draw::getWidth()
{
    return width;
}


void Draw::draw() //tällä metodilla piiretään pelaaja, pelikenttä, viholliset ja hedelmät
{
    system("CLS");

    for (int i = 0; i < width+1; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < width ; j++)
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

void Draw::input() //tällä metodilla valvotaan käyttäjän inputtia eli näppäinten painallusta
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

void Draw::movePlayer() //tällä metodilla liikutetaan pelaajaa inputin mukaan
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

void Draw::checkTouch() //tällä metodilla tarkastetaan onko pelaaja saanut hedelmän tai osunut viholliseen
{
    if (playerX == scoreX && playerY == scoreY)
    {
        Player::addPoints();
        setScoreX();
        setScoreY();
        setEnemy1X();
        setEnemy1Y();
    }

    if(enemy1X == playerX && enemy1Y == playerY)
    {
        Player::isAlive = false;
    }

    if(playerX == width || playerY == heigth || playerX == 0 || playerY == 0)
    {
        Player::isAlive = false;
    }
    
}

