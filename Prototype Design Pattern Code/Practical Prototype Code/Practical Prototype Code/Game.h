#ifndef GAME_HPP
#define GAME_HPP
//Authors: Leo Chen and Danial Nor Azman

/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "SquareEntity.h"
#include "CircleEntity.h"
#include "ScreenSize.h"
#include "NPC_Spawner.h"
#include "SquareNPC.h"
#include "CircleNPC.h"
#include "ShapeNPC.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void addAnotherRandomEntity();
	void cloneTheSameSquareEntity();
	void cloneTheSameCircleEntity();
	void deleteLastMadeEntity();

	void cloneSquareNPC();
	void cloneCircleNPC();

	Entity* m_entitySquare;
	Entity* m_entityCircle;

	std::vector<Entity*> m_entityVectorArray;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_helpMessage; // text used for message on screen
	bool m_exitGame; // control exiting game

	ShapeNPC* squarePrototype = new SquareNPC();
	NPC_Spawner* squareSpawner = new NPC_Spawner(squarePrototype);

	ShapeNPC* circlePrototype = new CircleNPC();
	NPC_Spawner* circleSpawner = new NPC_Spawner(circlePrototype);

	std::vector<ShapeNPC*> m_NPC_VectorArray;
};

#endif // !GAME_HPP

