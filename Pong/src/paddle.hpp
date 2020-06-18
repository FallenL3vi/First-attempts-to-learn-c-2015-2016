#include "entity.hpp"

class Paddle : public Entity, public sf::Drawable
{
	public:
		
		Paddle(float x, float y);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//void move()
	private:
};

