#include "barrier.h"
#include <iostream>
#include "window.h"

sf::Texture barrierTexture; // declaring the texture object

void barrier::defineBarrier(sf::Sprite &barrierSprite, int barrierPosX) {
	// If texture couldn't be loaded then showing the error.png
	if (!barrierTexture.loadFromFile("./resource/barrier100.jpg")) {
		barrierTexture.loadFromFile("./resource/error.png");
	}

	else {
		//repeating the texture to fit the sprite if necessary 
		barrierTexture.setRepeated(true);
	}


	// Setting the texture of the sprite
	barrierSprite.setTexture(barrierTexture);

	// Dealing with the positions
	barrierSprite.setOrigin(200.0f / 2, 20.0f / 2);
	barrierSprite.setTextureRect(sf::IntRect(0, 0, 200, 20));
	barrierSprite.setPosition(sf::Vector2f(barrierPosX, 500.f));
}