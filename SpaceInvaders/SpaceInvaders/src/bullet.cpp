#include "bullet.h" // including the headers of bullet and
#include "alien.h" // alien

sf::Texture bulletTexture; // creating textures
sf::Texture bulletTextureAlien;

void bullet::defineBullet(sf::Sprite &bulletSprite) { // defining bullet with texture and everything else
	if (!bulletTexture.loadFromFile("./resource/bullet.png")) {
		bulletTexture.loadFromFile("./resource/error.png");
	}
	else {
		bulletSprite.setTexture(bulletTexture);
		bulletSprite.setScale(0.1f, 0.1f);
	}
	//trying to set the origin of the bullet in the middle of the bullet
	bulletSprite.setOrigin(bulletTexture.getSize().x / 2.0f, bulletTexture.getSize().y / 2.0f);

}

void bullet::defineBulletAlien(sf::Sprite &bulletSpriteAlien) { // giving the bullet all the attributes it needs
	if (!bulletTextureAlien.loadFromFile("./resource/bulletAlien.png")) {
		bulletTextureAlien.loadFromFile("./resource/error.png");
	}
	else {
		bulletSpriteAlien.setTexture(bulletTextureAlien);
		bulletSpriteAlien.setScale(0.1f, 0.1f);
	}

	bulletSpriteAlien.setOrigin(bulletTextureAlien.getSize().x / 2.0f, bulletTexture.getSize().y / 2.0f);
}

void bullet::shoot(sf::Sprite &object, sf::Sprite &bulletSprite, bool &isDrawnBullet) { // function to shoot
	isDrawnBullet = true; // sets the boolean to true so we can see the bullet
	bulletSprite.setPosition(object.getPosition()); // and sets the position of course
}