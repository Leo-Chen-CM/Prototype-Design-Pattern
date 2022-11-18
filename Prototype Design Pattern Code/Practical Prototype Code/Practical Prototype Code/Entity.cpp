#include "Entity.h"
//Do I really have to explain this?
void Entity::Draw(sf::RenderWindow& t_window, sf::RectangleShape t_square)
{
	t_window.draw(t_square);
}

void Entity::Draw(sf::RenderWindow& t_window, sf::CircleShape t_circle)
{
	t_window.draw(t_circle);
}

//You know what this is.
void Entity::Update(sf::RectangleShape& t_square)
{
	m_position += m_velocity * 5.0f;

	t_square.setPosition(m_position);
	Bounds(t_square);
}

void Entity::Update(sf::CircleShape& t_circle)
{
	m_position += m_velocity * 5.0f;

	t_circle.setPosition(m_position);
	Bounds(t_circle);
}


//Returns a randomises the direct vector
sf::Vector2f Entity::RandomiseDirection()
{
	sf::Vector2f v = sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10);
	float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
	sf::Vector2f v2 = sf::Vector2f(v.x / mag, v.y / mag);

	return v2;
}



//Checks bounds and moves the square if  it goes out of bounds
void Entity::Bounds(sf::RectangleShape t_square)
{
	if (m_position.x < 0 - m_size.x || m_position.x > ScreenSize::WIDTH + m_size.x || m_position.y < 0 - m_size.y || m_position.y > ScreenSize::HEIGHT + m_size.y)
	{
		m_position = sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1);
		m_velocity = RandomiseDirection();
		t_square.setPosition(m_position);
	}
}

//Same thing but with a circle
void Entity::Bounds(sf::CircleShape t_circle)
{
	if (m_position.x < 0 - m_size.x || m_position.x > ScreenSize::WIDTH + m_size.x || m_position.y < 0 - m_size.y || m_position.y > ScreenSize::HEIGHT + m_size.y)
	{
		m_position = sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1);
		m_velocity = RandomiseDirection();
		t_circle.setPosition(m_position);
	}
}

