#include "draw.h"
#include <iostream>
#include <windows.h>

int main()
{
    Draw map = Draw();

    map.setHeigth(20);
    map.setWidth(20);
    map.setPlayerX(2);
    map.setPlayerY(15);
    while(true)
    {
        map.draw();
        Sleep(300);
    }
    system("pause");
    return 0;
}