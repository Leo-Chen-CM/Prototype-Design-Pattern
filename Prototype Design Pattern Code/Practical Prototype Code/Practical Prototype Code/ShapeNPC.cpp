#include "ShapeNPC.h"

//Returns a randomises the direct vector
sf::Vector2f ShapeNPC::RandomiseDirection()
{
	sf::Vector2f v = sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10);
	float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
	sf::Vector2f v2 = sf::Vector2f(v.x / mag, v.y / mag);

	return v2;
}