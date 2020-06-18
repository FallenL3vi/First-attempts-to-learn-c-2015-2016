#include "engine.hpp"

void Engine::start()
{
    initscr();
    noecho();

    Enemy m_Enemy(10,10,2);
    Anchient m_Anchient(20,20);
    Player m_Player(11,10);

    entities.push_back(&m_Anchient);
    entities.push_back(&m_Enemy);

    while(true)
    {
        m_Player.draw();
        //m_Enemy.draw();
        }
        //m_Anchient.draw();

        for(int i = 0; i < entities.size(); i++)
        {
            entities[i]->draw();
            entities[i]->move();
        input(m_Player);
       // m_Enemy.move();
        refresh();
        clear();
        m_Enemy.s_direction(2);
    }

    endwin();
}

void Engine::input(Player& m_Player)
{
    char button;

    button = getch();

        switch(button)
        {
        case 'w':
            {
                m_Player.s_direction(0);

                break;
            }
        case 'd':
            {
                m_Player.s_direction(1);
                break;
            }
        case 's':
            {
                m_Player.s_direction(2);
                break;
            }
        case 'a':
            {
                m_Player.s_direction(3);
                break;
            }
        case 'k':
            {
                Wall m_Wall(m_Player.y,m_Player.x);

                entities.push_back(&m_Wall);

                m_Player.s_direction(4);

                break;
            }
        default:
            {
                m_Player.s_direction(4);
                break;
            }
        }

        m_Player.move();
}
