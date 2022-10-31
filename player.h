#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Player    //tässä luokassa luodaan pelaaja ja pelaajalle olennaiset parametrit
{
private:
    string name;
    int highScore;
    fstream scoreFile;
    string highScoreName ="";
    
public:
    static int points;
    static bool isAlive;
    Player();
    void setPlayerName(string playername);
    //string getPLayerName();
    static void addPoints();
    void checkAndWriteHighScore();
    void printHighScore();
    void printPoints();
    void getHighScore();
   
};

#endif