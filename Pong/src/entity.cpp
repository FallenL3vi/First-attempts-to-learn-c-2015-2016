#include "entity.hpp"

Entity::Entity(float size_x, float size_y, float pos_x, float pos_y)
: m_Box ({size_x,size_y}),
position (pos_x,pos_y),
direction (0,0),
acceleration (0,0),
velocity(0,0)
{
	m_Box.setFillColor(sf::Color::Black);
	m_Box.setOrigin(position.x/2,position.y/2);
	m_Box.setPosition(position.x,position.y);
	std::cout << position.x << std::endl;
}

bool Entity::collision(Entity& m_Entity)
{
	if(this->m_Box.getGlobalBounds().intersects(m_Entity.m_Box.getGlobalBounds()))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Entity::move(Vector2D <float>n_direction)
{
	
	direction = direction + n_direction;
}

void Entity::update(float loopTime)
	{
		
		if(direction.lenght() !=0)
		{
			direction = direction.normalize();
		}
		
		acceleration = direction * loopTime * size;

		//acceleration = direction * size * loopTime;
		//acceleration = acceleration - (acceleration * 0.5); 
		velocity = velocity + acceleration;
		position = position + velocity;
		std::cout << acceleration.lenght()<< std::endl;
		m_Box.setPosition(position.x,position.y);
	}


