
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Asteroids.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	Asteroids asteroid;
	sf::RenderWindow m_window; 
	sf::Font m_ArialBlackfont; 

	sf::Texture m_backgroundTexture; 
	sf::Sprite m_backgroundSprite;
	bool m_exitGame; 

};

#endif // !GAME_HPP

