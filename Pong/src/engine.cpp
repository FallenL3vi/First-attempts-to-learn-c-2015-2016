#include "engine.hpp"

Game::Game()
:	m_Paddle1({10,10})
{
	m_Window.create(sf::VideoMode(600,800),"Pong",sf::Style::Resize);
}

void Game::start()
{
	m_Window.setFramerateLimit(60);
	while(m_Window.isOpen())
	{

		sf::Clock m_Clock;
		sf::Event m_Event;
		
		while(power)
		{
			while(m_Window.pollEvent(m_Event))
			{
				switch(m_Event.type)
				{
					case sf::Event::KeyPressed:
					{
						if(m_Event.key.code == sf::Keyboard::Escape)
						{
							m_Window.close();
							power = false;
							break;
						}
					}

					default:
						break;
				}
			}
		sf::Time m_Time = m_Clock.restart();
		float loopT = m_Time.asSeconds();
		input();
		update(loopT);
		draw();
		}
	}
}

void Game::input()
{
//	std::cout << loopT << std::endl;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Paddle1.move({1,0});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Paddle1.move({-1,0});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Paddle1.move({0,-1});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Paddle1.move({0,1});
	}
}

void Game::draw()
{
	m_Window.clear(sf::Color::White);
	m_Window.draw(m_Paddle1);//.m_Box);
	m_Window.display();
}

void Game::update(float loopTime)
{
	m_Paddle1.update(loopTime);
}
