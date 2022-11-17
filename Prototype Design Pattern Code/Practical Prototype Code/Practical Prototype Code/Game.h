#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "GenericEnemy.h"
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
	void addAnotherEnemy();
	void cloneTheSameEnemy();
	void deleteLastEnemy();

	void cloneSquareNPC();
	void cloneCircleNPC();

	Entity* m_enemy;

	std::vector<Entity*> m_enemyVectorArray;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	ShapeNPC* squarePrototype = new SquareNPC();
	NPC_Spawner* squareSpawner = new NPC_Spawner(squarePrototype);

	ShapeNPC* circlePrototype = new CircleNPC();
	NPC_Spawner* circleSpawner = new NPC_Spawner(circlePrototype);

	std::vector<ShapeNPC*> m_NPC_VectorArray;
};

#endif // !GAME_HPP

