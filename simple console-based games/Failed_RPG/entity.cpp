#include "entity.hpp"

Entity::Entity(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

void Entity::move()
{
    if(m_Direct == Direction::TOP)
    {
        y -= speed;
    }
    else if(m_Direct == Direction::RIGHT)
    {
        x += speed;
    }
    else if(m_Direct == Direction::DOWN)
    {
        y += speed;
    }
    else if(m_Direct == Direction::LEFT)
    {
        x -= speed;
    }
}

void Entity::s_direction(int dir)
{
    switch(dir)
    {
    case 0:
        {
            m_Direct = Direction::TOP;
            break;
        }
    case 1:
        {
            m_Direct = Direction::RIGHT;
            break;
        }
    case 2:
        {
            m_Direct = Direction::DOWN;
            break;
        }
    case 3:
        {
            m_Direct = Direction::LEFT;
            break;
        }
    case 4:
        {
            m_Direct = Direction::STAY;
            break;
        }
    default:
        {
            break;
        }
    }
}

void Entity::collision(Entity &entity)
{

}

void Entity::draw()
{
    mvprintw(x,y,"|");
}
