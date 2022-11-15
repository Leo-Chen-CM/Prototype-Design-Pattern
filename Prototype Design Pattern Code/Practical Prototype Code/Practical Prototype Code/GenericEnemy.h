#pragma once
#include "Entity.h"

class GenericEnemy :  public Entity
{
public:
	GenericEnemy(sf::Vector2f t_position, sf::Color t_color)
	{
		m_color = t_color;
		m_position = t_position;
		m_body.setFillColor(m_color);
		m_body.setPosition(m_position);
		m_size = sf::Vector2f(ScreenSize::WIDTH / 20, ScreenSize::WIDTH / 20);
		m_body.setSize(m_size);
		m_body.setOrigin(m_size.x / 2, m_size.y / 2);
		sf::Vector2f v = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
		float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
		m_velocity = sf::Vector2f(v.x / mag, v.y / mag);
	};

	//Clones the exact same copy of this enemy
	Entity * Clone() override
	{
		return new GenericEnemy(*this);
	}
};
