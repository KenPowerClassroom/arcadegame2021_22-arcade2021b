#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Asteroids", sf::Style::Default)
{
}

void Game::loadContent()
{
	// Font and message
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	m_message.setFont(m_font);
	m_message.setCharacterSize(24);
	m_message.setFillColor(sf::Color::White);
	m_message.setPosition(10, 10);

	// Background
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\background.jpg"))
	{

		std::cout << "problem loading logo" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
}


void Game::run()
{

	srand((int)time(nullptr));

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Clock clock;

	clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			update(timePerFrame);
			draw();

			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	// Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	}


	asteroid.update(t_deltaTime);

	asteroidMovement.moveAsteroid(asteroid);
	asteroidMovement.loopAsteroid(asteroid);
}

void Game::draw()
{
	window.clear();
	window.draw(m_backgroundSprite);

	m_message.setString("Game Play");
	window.draw(m_message);

	player.draw(window);
	asteroid.draw(window);



	window.display();
}