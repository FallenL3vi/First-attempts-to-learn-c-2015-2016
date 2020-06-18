#include <curses.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>


class Entity
{
public:

    int x;
    int y;
    int types;

    void move(int m_x, int m_y,int map_w, int map_h)
    {
            x += m_x;
            y += m_y;
            if(x == map_w - map_w + 1 || x == map_w - 1 || y == map_h - map_h + 1 || y == map_h -1)
            {
                x -= m_x;
                y -= m_y;
            }
    }

    void r_position(int map_w, int map_h)
    {
        x = (rand() % map_w) + 1;
        y = (rand() % map_h) + 1;
    }

    void r_type()
    {
        types = (rand () % 3) + 1;
    }
};

class World
{
    public:

       const static  int m_height = 1000;
       const static  int m_width = 1000;

        char tile[m_width][m_height];

        World()
        {
            for(int i = 0; i < m_height; i++)
            {
                for(int j = 0; j < m_width; j++)
                {
                    tile[j][i] = ' ';
                }
            }


            for(int i = 0; i < (((m_height * m_width))/5); i++)
            {
                int x = (rand() % m_width) + 1;
                int y = (rand() % m_height) + 1;

                tile[x][y] = '*';
            }
        }
};

class Player    :public Entity
{
public:

    int view_x = 5;
    int view_y = 5;


    Player()
    {
        x = 10;
        y = 10;
    }

    void moving(int w, int h)
    {
            char button = getch();

            switch(button)
            {
            case 'a':
                {
                    move(-1,0,w,h);
                    break;
                }
            case 'd':
                {
                    move(1,0,w,h);
                    break;
                }
            case 's':
                {
                    move(0,1,w,h);
                    break;
                }
            case 'w':
                {
                    move(0,-1,w,h);
                    break;
                }
            default:
                {
                    break;
                }
            }
    }


};

class Game
{

public:

    Player player;
    World world;

    void render()
    {
        for(int i = player.y - player.view_y; i < player.y + player.view_y; i++)
        {
            for(int j = player.x - player.view_x; j < player.x + player.view_x; j++)
            {
                    if(j == player.x && i == player.y)
                    {
                        attron(COLOR_PAIR(1));
                        printw("@");
                        attroff(COLOR_PAIR(1));
                    }
                    else if(i == (0 || world.m_height - 1) || j == (0 || world.m_width - 1))
                    {
                        attron(COLOR_PAIR(6));
                        printw("#");
                        attroff(COLOR_PAIR(6));
                    }
                    else
                    {
                        if(world.tile[j][i] == '*')
                        {
                            attron(COLOR_PAIR(3));
                            printw("*");
                            attroff(COLOR_PAIR(3));
                        }
                        else
                        {
                            attron(COLOR_PAIR(2));
                            printw(" ");
                            attroff(COLOR_PAIR(2));
                        }

                    }
            }
            printw("\n");
        }
        refresh();
        player.moving(world.m_width,world.m_height);

    }
};
int main()
{
    srand(time(NULL));
    initscr();
    noecho();
    Game game;
    if(has_colors() == true)
    {
        start_color();
        init_pair(1,COLOR_RED,COLOR_GREEN);
        init_pair(2,COLOR_GREEN,COLOR_GREEN);
        init_pair(3,COLOR_BLUE,COLOR_GREEN);
        init_pair(4,COLOR_WHITE,COLOR_GREEN);
        init_pair(5,COLOR_MAGENTA,COLOR_GREEN);
        init_pair(6,COLOR_BLACK,COLOR_GREEN);
    }
    while(true)
    {
    game.render();
    clear();
    }
    endwin();
    return 0;
}
