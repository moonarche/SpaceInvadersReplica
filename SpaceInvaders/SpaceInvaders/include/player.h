#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"

class player {

public:
	int playerHealth = 3; // the player's health value
	bool isDrawnPlayer = true; // boolean true because player is drawn by default
	void definePlayer(sf::Sprite &playerSprite); // Used to spawn the player in the environment
	void checkHealth(); // function to check health

};



#endif // !PLAYER_H