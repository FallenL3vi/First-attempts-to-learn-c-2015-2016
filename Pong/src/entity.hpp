#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include <iostream>
#include <cmath>
class Entity
{
	public:
		
		sf::RectangleShape m_Box;
		
		Entity(float size_x, float size_y, float pos_x, float pos_y);
		
		bool collision(Entity& m_Entity);

		void move(Vector2D <float>direction);
		
		void update(float loopTime);

	private:
	Vector2D <float>position;
	Vector2D <float>direction;
	Vector2D <float>acceleration;
	Vector2D <float>velocity;

	float size = 2;
};
