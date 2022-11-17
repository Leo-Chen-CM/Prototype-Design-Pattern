#pragma once
#include "ShapeNPC.h"

class CircleNPC : public ShapeNPC
{
public:

	CircleNPC()
	{
		m_body.setRadius(ScreenSize::WIDTH / 30);
		m_body.setPosition(m_position);

		sf::Vector2f v = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
		float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
		m_velocity = sf::Vector2f(v.x / mag, v.y / mag);
	};

	~CircleNPC() {};

	virtual ShapeNPC* Clone()
	{
		return new CircleNPC();
	}

	virtual void Update() override;
	virtual void Draw(sf::RenderWindow& t_window) override;
	virtual void Bounds() override;

private:

	sf::CircleShape m_body;
};
