#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "ScreenSize.h"

class ShapeNPC
{
public:
	virtual ~ShapeNPC() {};
	virtual ShapeNPC* Clone() = 0;

	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& t_window) = 0;

	sf::Vector2f RandomiseDirection();

	virtual void Bounds() = 0;

protected:
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Vector2f m_size;
};