#include <iostream>
#include <windows.h>
#include "player.h"
#include "draw.h"
#include "level2.h"
#include "userinterface.h"

int main()
{
    Draw map = Draw();
    Level2 map2 = Level2();
    Player p = Player();
    
   // p.getHighScore();
    //map.setHeigth(20); 
    //map.setWidth(20);
    //map.setPlayerX(10);
    //map.setPlayerY(15);
    //map.setScoreX();
    //map.setScoreY();
    //map.setEnemy1X();
    //map.setEnemy1Y();
    while(true)
    {
        mainMenu(p,map,map2);
    }

    system("pause");
    return 0;
}