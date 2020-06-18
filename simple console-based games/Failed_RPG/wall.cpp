#include "wall.hpp"

Wall::Wall(int x, int y)
: Entity ({x,y})
{
    m_Type = Type::WALL;
}


void Wall::draw()
{
    mvprintw(x,y,"#");
}
