#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "SFML/Graphics.hpp"
#include "player.h"

class bullet {
public:
	bool isDrawnBullet = false; // bool false because we don't want to see the bullet by default
	bool isDrawnBulletAlien = false; // bool false because the same reason
	void defineBullet(sf::Sprite &bulletSprite); // defining
	void defineBulletAlien(sf::Sprite &bulletSpriteAlien); // defining
	void shoot(sf::Sprite &object, sf::Sprite &bulletSprite, bool &isDrawn); // shooting function
};
#endif // !BULLET_H
