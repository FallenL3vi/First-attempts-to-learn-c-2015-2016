#include <iostream>
#include <vector>
#include "map.hpp"
#include <windows.h>

int main()
{
    Map map;
    map.fill();

    initscr();
    noecho();
    timeout(1);

        while(true)
        {
            map.print();
            if(map.key.pause == false)
            {
            map.check();
            }
            map.mo();
            Sleep(200);
           // system("cls");
        }
    endwin();
    return 0;
}
