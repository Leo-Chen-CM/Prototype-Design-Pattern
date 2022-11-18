#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"	
/// <summary>
/// The prototype/base class all entities derive from
/// </summary>

enum class EntityType
{
	Square,
	Cricle
};

class Entity
{
public:
	~Entity() {};
	virtual Entity* Clone() = 0;
	//void Draw(sf::RenderWindow& t_window);
	void Draw(sf::RenderWindow& t_window, sf::RectangleShape t_square);
	void Draw(sf::RenderWindow& t_window, sf::CircleShape t_circle);

	//void Update();
	void Update(sf::RectangleShape& t_square);
	void Update(sf::CircleShape& t_circle);

	sf::Vector2f RandomiseDirection();

	//void Bounds();
	void Bounds(sf::RectangleShape t_square);
	void Bounds(sf::CircleShape t_circle);


	virtual sf::RectangleShape& GetSquare() { return sf::RectangleShape(); };
	virtual sf::CircleShape& GetCircle() { return sf::CircleShape(); };

	EntityType ReturnType() { return m_type; };
protected:
	EntityType m_type;
	//sf::RectangleShape m_body;
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Vector2f m_size;
};

