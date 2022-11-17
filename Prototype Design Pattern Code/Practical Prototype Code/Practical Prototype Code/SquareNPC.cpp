#include "SquareNPC.h"

void SquareNPC::Update()
{
	m_position += m_velocity * 5.0f;

	m_body.setPosition(m_position);
	Bounds();
}

void SquareNPC::Draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void SquareNPC::Bounds()
{
	if (m_position.x < 0 - m_size.x || m_position.x > ScreenSize::WIDTH + m_size.x || m_position.y < 0 - m_size.y || m_position.y > ScreenSize::HEIGHT + m_size.y)
	{
		m_position = sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1);
		m_velocity = RandomiseDirection();
		m_body.setPosition(m_position);
	}
}
