#include "player.h"
#include "bullet.h"
#include <iostream>

sf::Texture playerTexture;

void player::definePlayer(sf::Sprite &playerSprite) {

	// If texture couldn't be loaded then showing the error.png
	if (!playerTexture.loadFromFile("./resource/player.png")) {
		playerTexture.loadFromFile("./resource/error.png");
	}

	else {
		playerSprite.setScale(sf::Vector2f(0.2f, 0.2f)); // If the loading is successful - scaling the playerSprite
	}


	// Setting the texture of the sprite
	playerSprite.setTexture(playerTexture);

	// Dealing with the positions
	playerSprite.setOrigin(playerTexture.getSize().x / 2.0f, playerTexture.getSize().y / 2.0f);

	playerSprite.setPosition(sf::Vector2f(1280 / 2, 650));


}

void player::checkHealth() {
	// if player's health is 0 and player is drawn then changing the boolean to not drawn
	if (playerHealth == 0 && isDrawnPlayer)
	{
		isDrawnPlayer = false;
	}

}