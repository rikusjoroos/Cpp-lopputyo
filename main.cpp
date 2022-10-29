#include <iostream>
#include <windows.h>
#include "player.h"
#include "draw.h"

int main()
{
    Draw map = Draw();
    Player p = Player();
    p.setPlayerName();
    map.setHeigth(20); 
    map.setWidth(20);
    map.setPlayerX(10);
    map.setPlayerY(15);
    map.setScoreX();
    map.setScoreY();
    map.setEnemyX();
    map.setEnemyY();
    while(p.isAlive)
    {
        map.draw();
        map.moveEnemy();
        map.movePlayer();
        map.input();
        map.collectScore();
        p.printPoints();
        p.printHighScore();
        Sleep(40);
    }

    p.checkAndWriteHighScore();
    
    return 0;
}