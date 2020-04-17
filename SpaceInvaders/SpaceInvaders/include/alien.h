#pragma once
#ifndef ALIEN_H
#define ALIEN_H

#include "SFML/Graphics.hpp" // including the sfml lib
#include "player.h"

class alien {
public:
	bool isDrawnAlien = true; // bool is true because alien is drawn by default
	bool changeDir = false; // bool is false because aliens change the direction only when hit the edge
	int distanceMoved = 0; // integer to count the distance which aliens have moved
	int descend = 0;
	int descendCount = 0;
	void defineAlien(sf::Sprite &alienSprite, int alienPosX, int alienPosY); // function to define the alien sprite and position
	void moveAlien(sf::Sprite &alienSprite); // function to move the aliens
	void descendAlien(sf::Sprite &alienSprite); // used to descend aliens
	void checkDescend(player &player); // used to check the descent level
};

#endif // !ALIEN_H
