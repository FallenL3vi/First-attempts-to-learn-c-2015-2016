#pragma once
#include "entity.hpp"

class Enemy :   public Entity
{
public:

    Enemy(int x, int y, int type);

    int health;

    int damage;

    virtual void draw();

private:

    enum Level
    {
        EASY,
        MEDIUM,
        HARD,
    };

    Level m_Level;

};
