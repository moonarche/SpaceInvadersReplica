#pragma once
#ifndef BARRIER_H
#define BARRIER_H
#include "SFML/Graphics.hpp"

class barrier {
public:
	int barrierDamage = 0; // barrier damage integer which increases each time it gets hit
	bool isDrawnBarrier = true; // boolean that is true because barriers are drawn by default

	void defineBarrier(sf::Sprite &barrierSprite, int barrierPosX); // function to give the barrier all the attributes it needs

};

#endif // !BARRIER_H
