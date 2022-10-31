#include "level2.h"
#include "player.h"
#include <iostream>

using namespace std;

Level2::Level2()
{

}

void Level2::setEnemy2X() //tällä arvotaan toisen vihollisen paikka X
{
    int temp;
    temp = rand() % getWidth();
    if (temp < 1)
    {
        this->enemy2X = 2;
    }
    else if (temp >= getWidth())
    {
        this->enemy2X = getWidth() - 2;
    }
    else
    {
        this->enemy2X = temp;
    }
    
}

void Level2::setEnemy2Y() //tällä arvotaan toisen vihollisen paikka Y
{
    int temp;
    temp = rand() % getHeigth();
    if (temp < 1)
    {
        this->enemy2Y = 2;
    }
    else if (temp >= getHeigth())
    {
        this->enemy2Y = getHeigth() - 2;
    }
    else
    {
        this->enemy2Y = temp;
    }
}

void Level2::draw() //tässä piirretään kenttä kahdella vihollisella.
{
    system("CLS");

    for (int i = 0; i < getWidth() + 1; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth(); j++)
        {
            if (j == 0)
            {
                cout << "#";
            }
            else if (i == getPlayerY() && j == getPlayerX())
            {
                cout << "H";
            }
            else if(i == getScoreY() && j == getScoreX())
            {
                cout << "O";
            }
            else if(i == getEnemy1Y() && j == getEnemy1X())
            {
                cout << "X";
            }
            else if(i == enemy2Y && j == enemy2X)
            {
                cout << "X";
            }
            else
            {
                cout << " ";
            }

            if (j == getWidth()-1)
            {
                cout << "#";
            }

            
        }
        cout << endl;
    }

    for (int i = 0; i < getWidth() + 1; i++)
    {
        cout << "#";
    }
    cout << endl;


}

void Level2::checkTouch() //tässä testataan onko pelaaja osunbut viholliseen tai hedelmään.
{
    if (getPlayerX() == getScoreX() && getPlayerY() == getScoreY())
    {
        Player::addPoints();
        setScoreX();
        setScoreY();
        setEnemy1X();
        setEnemy1Y();
        setEnemy2X();
        setEnemy2Y();
    }

    if(getEnemy1X() == getPlayerX() && getEnemy1Y() == getPlayerY())
    {
        Player::isAlive = false;
    }

    if(getPlayerX() == getWidth() || getPlayerY() == getHeigth() || getPlayerX() == 0 || getPlayerY() == 0)
    {
        Player::isAlive = false;
    }
    
}