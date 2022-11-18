#pragma once
#include "Entity.h"
class CircleEntity : public Entity
{
public:
	CircleEntity(sf::Vector2f t_position, sf::Color t_color)
	{
		m_type = EntityType::Cricle;
		m_color = t_color;
		m_position = t_position;
		m_body.setFillColor(m_color);
		m_body.setPosition(m_position);
		m_body.setRadius(ScreenSize::WIDTH / 30);
		m_body.setPosition(m_position);
		m_body.setOrigin(m_body.getRadius(), m_body.getRadius());
		sf::Vector2f v = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
		float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
		m_velocity = sf::Vector2f(v.x / mag, v.y / mag);
	};

	sf::CircleShape& GetCircle() override { return m_body; };

	//Clones the exact same copy of this enemy
	Entity* Clone() override
	{
		return new CircleEntity(*this);
	}
private:
	sf::CircleShape m_body;

};

