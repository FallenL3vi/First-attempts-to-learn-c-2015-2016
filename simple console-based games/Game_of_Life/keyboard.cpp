#include "keyboard.hpp"
#include "curses.h"

bool Keybaord::move()
{
    char button;
    button = getch();

        switch(button)
        {
        case 'w':
            {
                y--;
                break;
            }
        case 's':
            {
                y++;
                break;
            }
        case 'a':
            {
                x--;
                break;
            }
        case 'd':
            {
                x++;
                break;
            }
        case 'q':
            {
                if(pause == true)
                {
                    pause = false;
                }
                else if(pause == false)
                {
                    pause = true;
                }

                break;
            }
        case 'k':
            {
                return 1;
            }
        default:
            {
                break;
            }
    }
    return 0;
}
