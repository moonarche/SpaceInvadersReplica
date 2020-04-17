#include "alien.h"
#include <iostream>

sf::Texture alienTexture; // declaring the texture 

void alien::defineAlien(sf::Sprite &alienSprite, int alienPosX, int alienPosY) { 

	// If texture couldn't be loaded then Loading failed
	if (!alienTexture.loadFromFile("./resource/alien.png")) {
		alienTexture.loadFromFile("./resource/error.png");
	}

	else { // if texture successfully loaded then ...
		alienSprite.setTexture(alienTexture);
		alienSprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}


	// Dealing with the positions
	alienSprite.setOrigin(650.0f / 2, 650.0f / 2);

	alienSprite.setPosition(sf::Vector2f(alienPosX, alienPosY)); // setting the position of the aliens

}

void alien::moveAlien(sf::Sprite &alienSprite) { // moving the aliens...
	// every time they move this counter increments and when it hits 6 they change the direction of movement
	if (distanceMoved == 6)
		changeDir = true;

	// same thing
	if (distanceMoved == -6)
		changeDir = false;

	if (changeDir == false) { // if false then moving to the right and incrementing
		alienSprite.move(20.f, 0.f);
		distanceMoved++;
		descend++;
	}
	else if (changeDir) { // if true then moving to the left  and decrementing
		alienSprite.move(-20.f, 0.f);
		distanceMoved--;
		descend++;
	}

}

void alien::descendAlien(sf::Sprite &alienSprite) {
	if (descend == 12) { // when the descend integer which increments every time aliens move reaches 12
		alienSprite.move(0.f, 50.f); // aliens descned with 50 pixels
		descendCount++; // meanwhile the counter increments every time they descend
		descend = 0; // but the descned integer resets to zero
	}
}

void alien::checkDescend(player &player) {
	if (descendCount == 4) { // when the counter reaches 4 (it means aliens managed to descned 4 times)
		player.playerHealth = 0; // the player dies
	}
}