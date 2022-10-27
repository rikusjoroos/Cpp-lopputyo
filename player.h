#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    
public:
    static int points;
    static bool isAlive;
    Player();
    void setPlayerName();
    //string getPLayerName();
    static void addPoints();
    void printPoints();
   
};

#endif