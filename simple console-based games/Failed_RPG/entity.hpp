#pragma once
#include <curses.h>

class Entity
{
public:

    Entity(int new_x, int new_y);

    void move();
    void s_direction(int dir);
    void collision(Entity &entity);

    virtual void draw();

    int x;
    int y;

    int speed = 1;

    enum Type
    {
        NONE,
        TOWER,
        WALL,
        TRAP,
        ANCHIENT,
        ENEMY,
        PLAYER,
    };

    Type m_Type;
private:

    enum Direction
    {
        TOP,
        RIGHT,
        DOWN,
        LEFT,
        STAY,
    };

    Direction m_Direct;

};
