#pragma once
#include "ShapeNPC.h"

class SquareNPC : public ShapeNPC
{
public:

	SquareNPC() 
	{
		m_body.setSize(sf::Vector2f(ScreenSize::WIDTH / 20, ScreenSize::WIDTH / 20));
		m_body.setPosition(m_position);

		sf::Vector2f v = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
		float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
		m_velocity = sf::Vector2f(v.x / mag, v.y / mag);
	};

	~SquareNPC() {};

	virtual ShapeNPC* Clone()
	{
		return new SquareNPC();
	}

	void Update() override;
	void Draw(sf::RenderWindow& t_window) override;
	void Bounds() override;

	sf::RectangleShape ReturnShape() { return m_body; };
private:

	sf::RectangleShape m_body;
};
