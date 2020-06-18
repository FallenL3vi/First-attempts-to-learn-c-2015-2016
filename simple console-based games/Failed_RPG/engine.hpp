#pragma once
#include <curses.h>
#include <windows.h>
#include <vector>

#include "anchient.hpp"
#include "enemy.hpp"
#include "trap.hpp"
#include "player.hpp"
#include "wall.hpp"


class Engine
{
public:

    void start();

    void input(Player& m_Player);

private:

    std::vector <Entity*> entities;
};
