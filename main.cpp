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
    
    while(true)
    {
        mainMenu(p,map,map2);
    }

    system("pause");
    return 0;
}