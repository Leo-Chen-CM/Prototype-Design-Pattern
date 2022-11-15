#include "Game.h"
#include <iostream>

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ ScreenSize::WIDTH, ScreenSize::HEIGHT, 32U }, "Practical Prototype" },
	m_exitGame{false} //when true game will exit
{
	m_enemy = new GenericEnemy(sf::Vector2f(50.0f,50.0f), sf::Color::Blue);
	m_enemyVectorArray.push_back(m_enemy);
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	if (sf::Keyboard::Space == t_event.key.code)
	{
		addAnotherEnemy();
	}

	if (sf::Keyboard::C == t_event.key.code)
	{
		cloneTheSameEnemy();
	}

	if (sf::Keyboard::D == t_event.key.code)
	{
		deleteLastEnemy();
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	for (Entity* e : m_enemyVectorArray)
	{
		e->Update();
	}

	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	for (Entity* e : m_enemyVectorArray)
	{
		e->Draw(m_window);
	}
	m_window.display();
}

//Adds another enemy through the Generic Enemy Constructor
void Game::addAnotherEnemy()
{
	GenericEnemy* e = new GenericEnemy(sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1),
		sf::Color(rand() %255+1, rand() % 255 + 1, rand() % 255 + 1));
	m_enemyVectorArray.push_back(e);
	std::cout << "Manually added a new enemy" << std::endl;
}

//Adds the same enemy through Generic Enemy's clone method
void Game::cloneTheSameEnemy()
{
	m_enemyVectorArray.push_back(m_enemy->Clone());
	std::cout << "Cloned a new enemy from the same enemy" << std::endl;
}

void Game::deleteLastEnemy()
{
	if (!m_enemyVectorArray.empty())
	{
		m_enemyVectorArray.pop_back();
		std::cout << "Manually delete the last enemy" << std::endl;
	}
	else
	{
		std::cout << "There is no enemy left" << std::endl;
	}
}
