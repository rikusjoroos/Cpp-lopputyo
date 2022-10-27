#include "player.h"

int Player::points = 0;
bool Player::isAlive = true;

Player::Player()
{

}

void Player::addPoints()
{
    points = points + 1;
}

void Player::setPlayerName()
{
    string playername;
    cout << "Enter player name: ";
    getline(cin, playername);
    this->name = playername;
} 

void Player::printPoints()
{
    cout << "Score: " << points;
}