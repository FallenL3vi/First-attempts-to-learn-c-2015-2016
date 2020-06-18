#include "player.hpp"

Player::Player(int x, int y)
:   Entity  ({x,y})
{
    m_Type = Type::PLAYER;
    s_direction(0);
    speed = 1;
}

void Player::input()
{


    move();
}

void Player::draw()
{
    mvprintw(y,x,"2");
}
