#include "paddle.hpp"

Paddle::Paddle(float x, float y)
:	Entity({32,64,x,y})
{

}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Box);
}
