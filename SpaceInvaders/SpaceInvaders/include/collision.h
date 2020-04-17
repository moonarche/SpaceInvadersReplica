#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "SFML/Graphics.hpp"
#include "barrier.h"
#include "bullet.h"
#include "player.h"
#include "scoreManager.h"

class collision {
public:
	void checkCollisionPlayer(sf::Sprite &object); // making sure that player doesn't go beyond the borders

	void collisionAlienBullet(sf::Sprite &bulletSprite, sf::Sprite &alienSprite, bool &isDrawnBullet, bool &isDrawnAlien, scoreManager &scoreManager); // the names speak for themselves
	void collisionBarrierBullet(sf::Sprite &bulletSprite, sf::Sprite &barrierSprite, bool &isDrawnBullet, bool &isDrawnBarrier, barrier &barrier, bullet &bullet); // ...
	void collisionAlienBulletPlayer(sf::Sprite &bulletSpriteAlien, sf::Sprite &playerSprite, bool &isDrawnBulletAlien, bool &isDrawnPlayer, player &player); // ...
};
#endif // !COLLISION_H
