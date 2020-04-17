#include "scoreManager.h"
#include <iostream>

void scoreManager::displayInfo() {
	

	if (!font.loadFromFile("./resource/game_over.ttf")) { // loading the font
		std::cout << "[Error] game_over.ttf font file not found." << std::endl;
	}

	scoreDisplay.setFont(font); // setting the font
	healthDisplay.setFont(font); // same

	scoreDisplay.setCharacterSize(100); // setting character size for the text object
	scoreDisplay.setPosition(sf::Vector2f(0.0f, -69.0f)); // setting the position

	healthDisplay.setCharacterSize(100); // same
	healthDisplay.setPosition(sf::Vector2f(0.0f, 0.0f)); // same


}

void scoreManager::updateInfo(int &health) {
	std::string stringScore = std::to_string(score); // converting int to string
	scoreDisplay.setString("Score: " + stringScore); // setting the string to the text object

	std::string stringHealth = std::to_string(health); // same
	healthDisplay.setString("Health: " + stringHealth); // same
}

void scoreManager::displayWin() {
	winDisplay.setFont(font); // setting the font
	winDisplay.setCharacterSize(150); // setting character size for the text object
	winDisplay.setPosition(sf::Vector2f(640 / 2, 360 / 2)); // setting the position

	loseDisplay.setFont(font); // setting the font
	loseDisplay.setCharacterSize(150); // setting character size for the text object
	loseDisplay.setPosition(sf::Vector2f(640 / 2, 360 / 2)); // setting the position
}

void scoreManager::updateWin() {
	std::string stringScore = std::to_string(score); // converting int to string
	winDisplay.setString("You won! Your score is: " + stringScore + "\n" + "Press ESC to exit"); // setting the string to the text object
	loseDisplay.setString("You lost! Your score is: " + stringScore + "\n" + "Press ESC to exit"); // setting the string to the text object
}