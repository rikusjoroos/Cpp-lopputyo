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

void Player::setPlayerName(string playername)
{
    this->name = playername;
} 

void Player::printPoints()
{
    cout << "Score: " << points << "\t";
}

void Player::getHighScore()
{
    scoreFile.open("highscore.csv", ios::in);

    if(scoreFile.is_open())
    {
        
        string line = "";
        getline(scoreFile, line, ',');
        this->highScoreName = line;
        line = "";
        getline(scoreFile, line, ',');
        this->highScore = stoi(line);
    }
    

    scoreFile.close();
}

void Player::printHighScore()
{
    if(highScoreName != "")
    {
        cout <<"Highscore: " << highScoreName << ": " << highScore;
    }
    else
    {
        cout << "No highscore.";
    }
   
   
}

void Player::checkAndWriteHighScore()
{

    scoreFile.open("highscore.csv", ios::in);

    if(!scoreFile.is_open())
    {
        scoreFile.open("highscore.csv", ios::out);
        scoreFile <<"Unknown,0";
        scoreFile.close();
        scoreFile.open("highscore.csv", ios::in);
        
    }

    if(scoreFile.is_open())
    {
        
        int scoreFromFile;
        string strScoreFromFile;
        string nameFromfile;
        string line = "";
        getline(scoreFile, line, ',');
        nameFromfile = line;
        line = "";
        getline(scoreFile, line, ',');
        strScoreFromFile = line;
        scoreFromFile = stoi(strScoreFromFile);
        
        scoreFile.close();

        if(scoreFromFile < points)
        {
             scoreFile.open("highscore.csv", ios::out);
             if (scoreFile.is_open())
             {
                 scoreFile << name <<","<< points << endl;
                 scoreFile.close();
             }
        
        
             
        }

        
    }

  
  
       
}

   
