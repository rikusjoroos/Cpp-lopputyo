#include "player.h"

int Player::points = 0;
bool Player::isAlive = true;

Player::Player()
{

}

void Player::addPoints() //lisätään pelaajalle pisteitä
{
    points = points + 1;
}

void Player::setPlayerName(string playername) //asetetaan pelaajalle nimi
{
    this->name = playername;
} 

void Player::printPoints() //tulosetaan pelaajan pisteet
{
    cout << "Score: " << points << "\t";
}

void Player::getHighScore() //haetaan tiedostosta parhaat pisteet
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

void Player::printHighScore() //tulostetaan parhaat pisteet
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

void Player::checkAndWriteHighScore() //tarkastetaan tuliko uudet parhaat pisteet ja korvataan tiedosto mikäli tuli
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

   
