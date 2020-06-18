#pragma once
#include "entity.hpp"

class Anchient : public Entity
{
public:


    Anchient(int x, int y);

    int health;

    virtual void draw() override;

private:

};
