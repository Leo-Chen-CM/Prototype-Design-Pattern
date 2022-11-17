#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"

/// <summary>
/// The prototype/base class all entities derive from
/// </summary>
class Entity
{
public:
	~Entity() {};
	//Entity(sf::Vector2f t_position,sf::Color t_color, int t_size) : 
	//	m_color(t_color),
	//	m_position(t_position),
	//	m_size(t_size)
	//{
	//	sf::Vector2f v = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
	//	float mag = std::sqrtf((v.x * v.x) + (v.y * v.y));
	//	m_velocity = sf::Vector2f(v.x / mag, v.y / mag);s
	//	std::cout << "Velocity: "<< m_velocity.x<< ", "<< m_velocity.y << std::endl;
	//};
	virtual Entity* Clone() = 0;
	void Draw(sf::RenderWindow& t_window);

	void Update();

	sf::Vector2f RandomiseDirection();

	void Bounds();
protected:
	sf::RectangleShape m_body;
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Vector2f m_size;
};

