#include <iostream>
#include "collision.h"

void collision::checkCollisionPlayer(sf::Sprite &object) {
	if (object.getPosition().x >= 1280) { // getting the position and if the player goes beyond this point boom he doesn't
		object.move(-20.f, 0.f);
	}

	if (object.getPosition().x <= 50) { // same here
		object.move(20.f, 0.f);
	}
}

void collision::collisionAlienBullet(sf::Sprite &bulletSprite, sf::Sprite &alienSprite, bool &isDrawnBullet, bool &isDrawnAlien, scoreManager &scoreManager) {
	
	if (bulletSprite.getGlobalBounds().intersects(alienSprite.getGlobalBounds())) { // getting the bounds of the bullet sprite and if it interscets the alien sprite
		isDrawnBullet = false; // removing the bullet
		isDrawnAlien = false; // removing the alien a.k.a. the guy dies
		bulletSprite.setPosition(sf::Vector2f(0.f, 0.f)); // moving them away immediately so we don't feel the intersection 
		alienSprite.setPosition(sf::Vector2f(-500.f, 0.f));

		scoreManager.score++; // increasing the score of the player
	}
}

void collision::collisionBarrierBullet(sf::Sprite &bulletSprite, sf::Sprite &barrierSprite, bool &isDrawnBullet, bool &isDrawnBarrier, barrier &barrier, bullet &bullet) {

	if (bulletSprite.getGlobalBounds().intersects(barrierSprite.getGlobalBounds())) { // if the bullet hits the barrier the if statement runs
		isDrawnBullet = false; // removing bullet
		bulletSprite.setPosition(sf::Vector2f(-200.f, 0.f)); // moving it away
		barrier.barrierDamage++; // incrementing the barrier damage
		
	}

	if (barrier.barrierDamage == 3) { // if the barrier damage is 3
		isDrawnBarrier = false;
		barrierSprite.setPosition(sf::Vector2f(-50.f, 0.f)); // moving away
		barrier.barrierDamage = 0; // restoring the damage
	}
}

void collision::collisionAlienBulletPlayer(sf::Sprite &bulletSpriteAlien, sf::Sprite &playerSprite, bool &isDrawnBulletAlien, bool &isDrawnPlayer, player &player) {
	if (bulletSpriteAlien.getGlobalBounds().intersects(playerSprite.getGlobalBounds())) { // if the bullet from the alien hits the player
		isDrawnPlayer = false; // removing the player
		isDrawnBulletAlien = false; // removing the bullet
		bulletSpriteAlien.setPosition(sf::Vector2f(-100.f, 0.f)); // moving away the bullet sprite of the alien


		if (!isDrawnPlayer && player.playerHealth != 0) // and if player is not drawn and the health is not 0 then
		{
			player.playerHealth--; // decrementing the health
			isDrawnPlayer = true; // respawning
			playerSprite.setPosition(sf::Vector2f(1280 / 2, 650)); // pos
			std::cout << "Health Remaining: " << player.playerHealth << "\n";
		}
	}
}