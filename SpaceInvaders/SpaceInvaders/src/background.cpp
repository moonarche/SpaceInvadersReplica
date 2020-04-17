#include "background.h"


void background::setBackground(){
	// If texture couldn't be loaded then Loading failed
	if (!backgroundTexture.loadFromFile("./resource/background.png")) {
		backgroundTexture.loadFromFile("./resource/error.png");
	}

	else {
		backgroundSprite.setTexture(backgroundTexture);
	}
	// scaling the background to fit our resolution properly
	backgroundSprite.setScale(0.7, 0.7);
}