#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "paddle.hpp"
#include "vector.hpp"

class Game
{
	public:
		
		Paddle m_Paddle1;
		sf::RenderWindow m_Window;

		Game();
		void start();
	private:
		bool power = true;

		void input();
		void draw();
		void update(float loopTime);
};
