#pragma once
#include <SFML/Graphics.hpp>
class Shape
{
public:
	Shape();
	Shape(Shape* t_shape)
	{
		this->m_x = t_shape->m_x;
		this->m_y = t_shape->m_y;
		this->m_color = t_shape->m_color;
	};
private:
	int m_x;
	int m_y;
	sf::Color m_color;
};

