#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Player
{
private:
    string name;
    int highScore;
    fstream scoreFile;
    
public:
    static int points;
    static bool isAlive;
    Player();
    void setPlayerName();
    //string getPLayerName();
    static void addPoints();
    void checkAndWriteHighScore();
    void printHighScore();
    void printPoints();
   
};

#endif