#include "anchient.hpp"

Anchient::Anchient(int n_x, int n_y)
: Entity ({n_x, n_y})
{
    m_Type = Entity::ANCHIENT;

    health = 100;
}


void Anchient::draw()
{
    mvprintw(y,x,"A");
}
