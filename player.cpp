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
    cout << "Score: " << points << "\t";
}

void Player::printHighScore()
{
    scoreFile.open("highscore.txt", ios::in);

    if(scoreFile.is_open())
    {
        
        scoreFile >> highScore;
        cout << "Highscore: " << highScore;
        scoreFile.close();
    }
    else
        cout << "No highscore.";

   
}

void Player::checkAndWriteHighScore()
{

    scoreFile.open("highscore.txt", ios::in);

    if(!scoreFile.is_open())
    {
        scoreFile.open("highscore.txt", ios::out);
        scoreFile << 0;
        scoreFile.close();
        scoreFile.open("highscore.txt", ios::in);
        
    }

    if(scoreFile.is_open())
    {
        
        int scoreFromFile;
        scoreFile >> scoreFromFile;
        scoreFile.close();

        if(scoreFromFile < points)
        {
             scoreFile.open("highscore.txt", ios::out);
             if (scoreFile.is_open())
             {
                 scoreFile << points;
                 scoreFile.close();
             }
        
        
             
        }

        
    }

  
  
       
}

   
