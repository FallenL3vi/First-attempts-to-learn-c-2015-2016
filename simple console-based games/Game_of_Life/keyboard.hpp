#pragma once
#include <curses.h>

class Keybaord
{

public:

    int x = 0;
    int y = 0;

    bool pause = false;

    bool move();

private:
};
