#include "Player.h"

Player::Player()
{
	loadImages();
	initialise();
}

void Player::loadImages()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/ship.png"))
	{
		std::cout << "error with font file file";
	}

	body.setTexture(texture);
	body.setOrigin(780, 759);
	body.setScale(0.035, 0.035);

	for (int index = 0; index < MAX_LIVES; index++)
	{
		livesSprites[index].setTexture(texture);
		livesSprites[index].setOrigin(780, 759);
		livesSprites[index].setScale(0.025, 0.025);
		livesSprites[index].setPosition(50 + 50 * index, 50);
	}
}

sf::Sprite Player::getSprite()
{
	return body;
}

void Player::killPlayer()
{
	lives--;
	dead = true;
	respawnTimer.restart();
}

void Player::respawn()
{
	dead = false;
	invincible = true;
	initialise();
	invincibilityTimer.restart();
}

int Player::getLives()
{
	return lives;
}

bool Player::getLiving()
{
	return dead;
}

bool Player::getInvincible()
{
	return invincible;
}

void Player::initialise()
{
	controller.initialize();

	body.setRotation(controller.returnRotation() + ROTATE_OFFSET);
	body.setPosition(controller.returnXpos(), controller.returnYpos());
}

void Player::processInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		controller.rotateRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		controller.rotateLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		controller.acceleration();
	}
}

void Player::update(double dt)
{
	if (respawnTimer.getElapsedTime().asSeconds() >= 2 && dead)
	{
		respawn();
	}
	if (invincibilityTimer.getElapsedTime().asSeconds() >= 2)
	{
		invincible = false;
	}
	processInput();
	controller.update(dt);

	body.setRotation(controller.returnRotation() + ROTATE_OFFSET);
	body.setPosition(controller.returnXpos(), controller.returnYpos());
}


void Player::draw(sf::RenderWindow& t_window)
{
	if (!dead)
	{
		t_window.draw(body);
	}

	for (int index = 0; index < lives; index++)
	{
		t_window.draw(livesSprites[index]);
	}
}