#include "Entity.h"
//Do I really have to explain this?
void Entity::Draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

//You know what this is.
void Entity::Update()
{
	m_position += m_velocity * 5.0f;

	m_body.setPosition(m_position);
	Bounds();
}

//Returns a randomises the direct vector
sf::Vector2f Entity::RandomiseDirection()
{
		sf::Vector2f v = sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10);
		float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
		sf::Vector2f v2 = sf::Vector2f(v.x / mag, v.y / mag);
	
		return v2;
}

//Checks the bounds of the entity
void Entity::Bounds()
{
	if (m_position.x < 0 - m_size.x || m_position.x > ScreenSize::WIDTH + m_size.x || m_position.y < 0 - m_size.y || m_position.y > ScreenSize::HEIGHT + m_size.y)
	{
		m_position = sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1);
		m_velocity = RandomiseDirection();
		m_body.setPosition(m_position);
	}
}