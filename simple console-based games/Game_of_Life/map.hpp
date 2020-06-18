#pragma once
#include <vector>
#include <array>
//#include <iostream>
#include <curses.h>
#include "title.hpp"
#include "keyboard.hpp"


class Map
{
public:
    Keybaord key;

    void fill();
    void print();
    void check();
    void mo();

private:
    const static int width = 30;
    const static int height = 30;

    std::array < std::array<int,width>,height> map;

    std::vector <Title> titles;

};
