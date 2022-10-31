#include <string>
#include <Windows.h>
#include "userinterface.h"
#include "player.h"
#include "draw.h"
#include "level2.h"


using namespace std;

void mainMenu(Player &p, Draw &map, Level2 &map2) //tässä funktiossa alustetaan peli ja pyöritetään käyttöliittymää.
{
   

    bool menuIsRunning = true;
    while(menuIsRunning)
    {
        p.getHighScore();
        map.setHeigth(20); 
        map.setWidth(25);
        map.setPlayerX(10);
        map.setPlayerY(10);
        map.setScoreX();
        map.setScoreY();
        map.setEnemy1X();
        map.setEnemy1Y();

        map2.setHeigth(20); 
        map2.setWidth(20);
        map2.setPlayerX(10);
        map2.setPlayerY(10);
        map2.setScoreX();
        map2.setScoreY();
        map2.setEnemy1X();
        map2.setEnemy1Y();
        map2.setEnemy2X();
        map2.setEnemy2Y();


        p.isAlive = true;

        system("CLS");
        int selection = 0;

        cout << "Die or Die Game" << endl;

        cout << "1: New game\n2: Instructions\n3: Exit game" << endl;

        cout << "Insert number to select: ";

        cin >> selection;
        system("CLS");
        
        if (selection == 1)
        {

            string str;
            cout << "Give your name: ";
            cin.ignore();
            getline(cin, str);
            p.setPlayerName(str);
            p.points = 0;
            while(p.isAlive && p.points < 5)
            {
                map.draw();
                map.movePlayer();
                map.checkTouch();
                map.input();
                p.printPoints();
                p.printHighScore();
                Sleep(40);
            }

            while(p.isAlive)
            {
                map2.draw();
                map2.checkTouch();
                map2.movePlayer();
                map2.input();
                p.printPoints();
                p.printHighScore();
                Sleep(40);
            }

            if(p.isAlive==false)
            {
                system("CLS");
                cout << "Game over.\n";
                system("pause");
                p.checkAndWriteHighScore();

            }
            
            
        }
        else if (selection == 2)
        {
            system("CLS");
            cout << "You are the hero 'H'.\nUse wasd to move.\nTry to collect points 'O'.\nDon't touch anything else.\n";
            system("pause");

            
        }
        else if (selection == 3)
        {
            exit(0);
        }
        

    }
   

}

