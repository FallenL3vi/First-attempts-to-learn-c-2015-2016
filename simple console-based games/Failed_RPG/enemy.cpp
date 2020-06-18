#include "enemy.hpp"

Enemy::Enemy(int n_x,int n_y,int level)
: Entity ({n_x, n_y})
{

    m_Type = Entity::ENEMY;

    switch(level)
    {
    case 0:
        {
            m_Level = Level::EASY;

            health = 30;
            damage = 5;

            break;
        }
    case 1:
        {
            m_Level = Level::MEDIUM;

            health = 60;
            damage = 10;

            break;
        }
    case 2:
        {
            m_Level = Level::HARD;

            health = 120;
            damage = 20;

            break;
        }
    default:
        {
            break;
        }
    }
}

void Enemy::draw()
{
    if(m_Level == Level::EASY)
    {
        mvprintw(y,x,"0");
    }
    else if (m_Level == Level::MEDIUM)
    {
        mvprintw(y,x,"1");
    }
    else
    {
        mvprintw(y,x,"2");
    }
}

