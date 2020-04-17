#pragma once
#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#include "SFML/Graphics.hpp"
#include <string>

class scoreManager {
public:
	int score = 0; // integer for score
	sf::Text scoreDisplay, healthDisplay, winDisplay, loseDisplay; // text objects
	sf::Font font; // font object

	void displayInfo(); // func to define the health and score
	void updateInfo(int &health); // func to update the health and score 60 times a second
	void displayWin(); // func to define winning title
	void updateWin(); // func to update the winning conditions
};
#endif // !SCOREMANAGER_H
