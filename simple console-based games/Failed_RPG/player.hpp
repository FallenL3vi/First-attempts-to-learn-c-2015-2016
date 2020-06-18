#pragma once
#include "entity.hpp"

class Player : public Entity
{
public:

    Player(int x, int y);

    void input();

    virtual void draw();

private:

};
