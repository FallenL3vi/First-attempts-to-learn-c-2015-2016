#include "map.hpp"


void Map::fill()
{

    for(int i = 0; i < 3; i++)
    {
        Title title;
        title.y = 10;
        title.x = 10 + i;

        titles.push_back(title);
    }

    for(int i = 0; i < Map::height; i++)
    {
        for(int j = 0; j < Map::width; j++)
        {
            map[i][j] = 0;

            for(int a = 0; a < titles.size(); a++)
            {
                if(titles[a].x == j && titles[a].y == i)
                {
                    map[i][j]=1;
                }
            }
        }
    }
}

void Map::print()
{
    for(int i = 0; i < Map::height; i++)
    {
        for(int j = 0; j < Map::width; j++)
        {
            if(i == key.y && j == key.x)
            {
                mvprintw(i,j,"x");
            }
            else if(map[i][j] == 1)
            {
                mvprintw(i,j,"*");
            }
            else
            {
                mvprintw(i,j," ");
            }
        }
        refresh();
    }
}

void Map::check()
{
    Map newMap = *this;

    int number;

    for(int i = 0; i < Map::height; i++)
    {
        for(int j = 0; j < Map::width; j++)
        {
           if(map[i][j] == 1)
           {
               number = -1;
           }
           else
           {
               number = 0;
           }

           for(int a = i - 1; a <= i + 1; a++)
           {
               for(int b = j - 1; b <= j + 1; b++)
               {
                 if(a < 0 || a > Map::height - 1 || b < 0 || b > Map::width - 1|| map[a][b] == 0)
                 {
                     number += 0;
                 }
                 else
                 {
                     number +=1;
                 }
               }
           }
           if(number == 3 && map[i][j] == 0)
           {
               newMap.map[i][j] = 1;
           }
           else if((number == 2 || number == 3) && map[i][j] == 1)
           {
               newMap.map[i][j] = 1;
           }
           else
           {
               newMap.map[i][j] = 0;
           }

           //std::cout << number << std::endl;
        }
    }
map = newMap.map;
}

void Map::mo()
{
    key.move();
    if(key.move() == 1)
    {
        if(map[key.y][key.x] == 0)
        {
            map[key.y][key.x] = 1;
        }
        else
        {
            map[key.y][key.x] = 0;
        }
    }
}
