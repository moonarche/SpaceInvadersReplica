#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SFML/Graphics.hpp"

class background {
public:
	sf::Texture backgroundTexture; // declaring objects 
	sf::Sprite backgroundSprite; // ...

	void setBackground(); // function to actually set the background, duh...
};
#endif // !BACKGROUND_H
