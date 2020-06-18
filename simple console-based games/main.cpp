#include <iostream>
#include <conio.h>
#include <windows.h>

class World
{
public:

    static const int height = 20;
    static const int width = 20;

    int sandbox[width][height];

    World()
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                sandbox[j][i] = 0;
            }
        }
    }
};

class Player
{

char button;

bool grav = false;
int f_grav = 1;
int f_jump = 3;
int speed = 1;
bool side;

public:

    int pos_x = 10;
    int pos_y = 10;

    World &mWorld;
    Player(World &world) :
        mWorld(world)
    {
    }

    void gravit()
    {
        if(pos_y < mWorld.height-1 && !(mWorld.sandbox[pos_x][pos_y + 1] == 1))
        {
            grav = true;
            pos_y += f_grav;
        }
        else
        {
            grav = false;
        }
    }

    void j_collision()
    {
        int j_size = 0;

        for(int i = 0; i < f_jump; i++)
        {
            if(mWorld.sandbox[pos_x][pos_y - (i + 1)] == 1)
            {
                break;
            }
            else
            {
                j_size ++;
            }
        }
        pos_y -= j_size;
    }

    bool collision(bool side)
    {
        switch(side)
        {
        case 0:
            {
                if(mWorld.sandbox[pos_x - speed][pos_y] == 1 || mWorld.sandbox[pos_x][pos_y + 1] == 1 && grav == true || pos_x == mWorld.width-mWorld.width)
                {
                    return 1;
                    break;
                }
                else
                {
                    return 0;
                    break;
                }
            }
        case 1:
            {
                if(mWorld.sandbox[pos_x + speed][pos_y] == 1 || mWorld.sandbox[pos_x][pos_y + 1] == 1 && grav == true || pos_x == mWorld.width-1)
                {
                    return 1;
                    break;
                }
                else
                {
                    return 0;
                    break;
                }
            }
        default:
            {
                break;
            }
        }
    }
    void move()
    {
        gravit();

        button = getch();

        switch(button)
        {
        case 'w':
            {
                if(grav == true)
                {
                    break;
                }
                else
                {
                    j_collision();

                    break;
                }
            }
        case 'a':
            {
                side = 0;

                if(collision(side) == true)
                {
                    break;
                }
                else
                {
                pos_x -= speed;
                }
                break;
            }
        case 'd':
            {
                side = 1;
                if(collision(side) == true)
                {
                    break;
                }
                else
                {
                pos_x += speed;
                }
                break;
            }
        case 'k':
            {
                if(pos_y < mWorld.height)
                {
                    mWorld.sandbox[pos_x][pos_y - 1] = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
        default:
            {
                break;
            }
        }
    }
};

class Render
{

public:

    Player &mPlayer;

    Render(Player &player) :
        mPlayer(player)
        {

        }

    void draw()
    {
        for(int i = 0; i < mPlayer.mWorld.height; i++)
        {
            for(int j = 0; j < mPlayer.mWorld.width; j++)
            {
                if(j == mPlayer.pos_x && i == mPlayer.pos_y)
                {
                    std::cout << "@";
                }
                else
                {
                    switch(mPlayer.mWorld.sandbox[j][i])
                    {
                    case 0:
                        {
                            std::cout <<".";
                            break;
                        }
                    case 1:
                        {
                            std::cout <<"#";
                            break;
                        }
                    default:
                        {
                            break;
                        }
                    }
                }
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    World world;
    Player player(world);
    Render render(player);

    while(true)
    {
    render.draw();
    player.move();
    system("cls");
    }
    return 0;
}
