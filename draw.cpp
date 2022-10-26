#include <iostream>
#include "draw.h"

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