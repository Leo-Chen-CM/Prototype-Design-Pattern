#include "GenericEnemy.h"
//
//void GenericEnemy::Draw(sf::RenderWindow& t_window)
//{
//	t_window.draw(m_body);
//}
//
//void GenericEnemy::Update()
//{
//	m_position += m_velocity;
//
//	m_body.setPosition(m_position);
//	Bounds();
//}
//
//sf::Vector2f GenericEnemy::RandomiseDirection()
//{
//	sf::Vector2f v = sf::Vector2f(rand() % 20 -10, rand() % 20 - 10);
//	float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
//	sf::Vector2f v2 = sf::Vector2f(v.x / mag, v.y / mag);
//
//	return v2;
//}
//
//void GenericEnemy::Bounds()
//{
//	if (m_position.x < 0 - 50 ||m_position.x > 1800U + 50)
//	{
//		m_position = sf::Vector2f(1800U/2, 1600U/2);
//		m_velocity = RandomiseDirection();
//		m_body.setPosition(m_position);
//	}
//
//	if (m_position.y < 0 - 50 || m_position.y > 1600U + 50)
//	{
//		m_position = sf::Vector2f(1800U / 2, 1600U / 2);
//		m_velocity = RandomiseDirection();
//		m_body.setPosition(m_position);
//	}
//}
