#include "Game.h"
#include <iostream>

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ ScreenSize::WIDTH, ScreenSize::HEIGHT, 32U }, "Practical Prototype Design Pattern" },
	m_exitGame{false} //when true game will exit
{
	m_entitySquare = new SquareEntity(sf::Vector2f(50.0f, 50.0f), sf::Color::Blue);
	m_entityVectorArray.push_back(m_entitySquare);
	m_entityCircle = new CircleEntity(sf::Vector2f(100.0f, 50.0f), sf::Color::Red);
	m_entityVectorArray.push_back(m_entityCircle);
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
		addAnotherRandomEntity();
	}

	if (sf::Keyboard::S == t_event.key.code)
	{
		cloneTheSameSquareEntity();
	}

	if (sf::Keyboard::C == t_event.key.code)
	{
		cloneTheSameCircleEntity();
	}

	if (sf::Keyboard::Backspace == t_event.key.code)
	{
		deleteLastMadeEntity();
	}

	//if (sf::Keyboard::S == t_event.key.code)
	//{
	//	cloneSquareNPC();
	//}

	//if (sf::Keyboard::A == t_event.key.code)
	//{
	//	cloneCircleNPC();
	//}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	for (Entity* e : m_entityVectorArray)
	{
		if (e->ReturnType() == EntityType::Cricle)
		{
			e->Update(e->GetCircle());
		}
		else
		if (e->ReturnType() == EntityType::Square)
		{
			e->Update(e->GetSquare());
		}
	}

	//for (ShapeNPC* s : m_NPC_VectorArray)
	//{
	//	s->Update();
	//}

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
	for (Entity* e : m_entityVectorArray)
	{
		if (e->ReturnType() == EntityType::Cricle)
		{
			e->Draw(m_window,e->GetCircle());
		}
		else
		if (e->ReturnType() == EntityType::Square)
		{
			e->Draw(m_window, e->GetSquare());
		}
	}

	for (ShapeNPC* s : m_NPC_VectorArray)
	{
		s->Draw(m_window);
	}
	m_window.display();
}

//Adds another entity through the different entity Constructor
void Game::addAnotherRandomEntity()
{

	int type = rand() % 2;

	if (type == 0)
	{
		SquareEntity* e = new SquareEntity(sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1),
			sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
		m_entityVectorArray.push_back(e);
		std::cout << "Manually added a new square entity" << std::endl;
	}
	else
	{
		CircleEntity* c = new CircleEntity(sf::Vector2f(rand() % ScreenSize::WIDTH + 1, rand() % ScreenSize::HEIGHT + 1),
			sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
		m_entityVectorArray.push_back(c);
		std::cout << "Manually added a new circle entity" << std::endl;
	}

}

//Adds the same entity through entity's clone method
void Game::cloneTheSameSquareEntity()
{

	m_entityVectorArray.push_back(m_entitySquare->Clone());
	std::cout << "Cloned a new square from the same entity" << std::endl;
}

void Game::cloneTheSameCircleEntity()
{
	m_entityVectorArray.push_back(m_entityCircle->Clone());
	std::cout << "Cloned a new circle from the same entity" << std::endl;
}

void Game::deleteLastMadeEntity()
{
	if (!m_entityVectorArray.empty())
	{
		m_entityVectorArray.pop_back();
		std::cout << "Manually deletes the last entity" << std::endl;
	}
	else
	{
		std::cout << "There are no entities left" << std::endl;
	}
}

void Game::cloneSquareNPC()
{
	ShapeNPC* s = squareSpawner->spawnMonster();
	std::cout << "Manually clone square NPC" << std::endl;

	m_NPC_VectorArray.push_back(s);
}

void Game::cloneCircleNPC()
{
	ShapeNPC* c = circleSpawner->spawnMonster();
	std::cout << "Manually clone circle NPC" << std::endl;

	m_NPC_VectorArray.push_back(c);
}
