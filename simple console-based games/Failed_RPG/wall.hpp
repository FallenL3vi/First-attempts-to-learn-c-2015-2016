#pragma once
#include "entity.hpp"

class Wall : public Entity
{
public:

    Wall(int x, int y);

    virtual void draw();
};
