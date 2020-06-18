#include <iostream>
#include <curses.h>
#include <time.h>
#include <cstdlib>
#include <vector>

class Entity
{
public:

    int x;
    int y;

    void move(int m_x, int m_y)
    {
        x += m_x;
        y += m_y;
    }

    bool collision(int m_y)
    {

        if(y == m_y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void r_position(int map_w, int map_h)
    {
        x = (rand() % map_w);
        y =  map_h - map_h;
    }
};

class World
{
public:

    int map_width = 40;
    int map_height = 50;

    std::vector <Entity> entities;

    void create()
    {
        Entity entity;

        for(int i = 0; i < 1; i++)
        {
            entity.r_position(map_width,map_height);
            entities.push_back(entity);
        }
    }

    void drop()
    {
        int speed = 1;
        for(int i = 0; i < entities.size(); i++)
        {
            if(entities[i].collision(map_height) == false)
            {
            entities[i].move(0,speed);
            }
            else
            {
                entities.erase(entities.begin() + i);
            }
        }
    }
};

class Render
{
public:

    World &world;

    Render(World &w)
    :   world(w)
    {}

    bool rain_check(int x, int y)
    {
        for(int i = 0; i < world.entities.size(); i++)
        {
            if(world.entities[i].x == x && world.entities[i].y == y)
            {
                return true;
            }
        }
        return false;
    }

    void redering()
    {
        for(int i = 0; i < world.map_height; i++)
        {
            for(int j = 0; j < world.map_width; j++)
            {
                if(rain_check(j,i) == true)
                {
                    mvprintw(i,j,".");
                }
                else
                {
                    mvprintw(i,j," ");
                }
                refresh();
            }
        }
    }
};
int main()
{
    World w;
    Render r(w);
    srand(time(NULL));
    initscr();
    noecho();
    while(true)
    {
        r.world.create();
        r.world.drop();
        r.redering();
    }
    endwin();
    return 0;
}
