#include <iostream> // for input/output stuff
#include "window.h" // window class
#include "player.h" // player class
#include "alien.h" // alien class
#include "barrier.h" // barrier class
#include "collision.h" // collision checking class
#include "bullet.h" // bullet class
#include "background.h" // background class
#include "SFML/Graphics.hpp" // the god's class
#include <time.h> // time for randomizing class

int main() {
	
	window gWindow; // creating an object for window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Invaders: Replica", sf::Style::Default); // passing arguments to the window class

	collision collision; // creating an object for collisions

	background background; // creating an object for background
	background.setBackground(); // using the function setBackground to set an image as a background

	player player; // the player himself
	sf::Sprite playerSprite; // creating a sprite for the player
	player.definePlayer(playerSprite); // defining the player with the sprite (function in a player class)

	scoreManager scoreManager; // scoreManager object to call the functios from there
	scoreManager.displayInfo(); // giving the sf::Text object some attributes
	scoreManager.displayWin(); // same with the winning title

	bullet bullet, bulletAlien; // bullet objects
	sf::Sprite bulletSprite, bulletSpriteAlien; // sprites for them
	bullet.defineBullet(bulletSprite); // giving the bullet attributes
	bullet.defineBulletAlien(bulletSpriteAlien); // same
	const float bulletSpeed = -10; // creating a constant for the bulletspeed

	// objects for aliens
	alien alien1;
	alien alien2;
	alien alien3;
	alien alien4;
	//sprites for the aliens
	sf::Sprite alienSprite;
	sf::Sprite alienSprite2;
	sf::Sprite alienSprite3;
	sf::Sprite alienSprite4;
	// and giving the object the sprite and a position
	alien1.defineAlien(alienSprite, 200, 200);
	alien2.defineAlien(alienSprite2, 500, 200);
	alien3.defineAlien(alienSprite3, 800, 200);
	alien4.defineAlien(alienSprite4, 1100, 200);

	//creating the barrier objects
	barrier barrier1;
	barrier barrier2;
	barrier barrier3;
	//sprites for them
	sf::Sprite barrierSprite;
	sf::Sprite barrierSprite2;
	sf::Sprite barrierSprite3;
	//giving them sprites and positions
	barrier1.defineBarrier(barrierSprite, 200);
	barrier2.defineBarrier(barrierSprite2, 1280 / 2);
	barrier3.defineBarrier(barrierSprite3, 1280 - 200);

	



	sf::Clock timer; // A timer object
	int timeCounter = 0;



	gWindow.createWindow(window); // creating the window


	//MAIN LOOP//
	while (window.isOpen())
	{
		// check all user events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// User has pressed the close button
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Process any keypresses
			// If player lost or won he can't press a, d and space
			if (scoreManager.score != 4 && player.playerHealth != 0) {
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::A) playerSprite.move(-20.f, 0.f); // move left
					if (event.key.code == sf::Keyboard::D) playerSprite.move(20.f, 0.f); // move right
					if (event.key.code == sf::Keyboard::Space) bullet.shoot(playerSprite, bulletSprite, bullet.isDrawnBullet); // shoot
				}
			}

			// He can only press "esc" to exit
			if (scoreManager.score == 4 || player.playerHealth == 0) {
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape) window.close();
				}
			}

		}

		window.clear(sf::Color::Black); // clearing the window 60 times a second

		window.draw(background.backgroundSprite); // drawing the background

		player.checkHealth(); // checking player's health

		scoreManager.updateInfo(player.playerHealth); // updating the info in the left top corner
		scoreManager.updateWin(); // updating the win score and health

		window.draw(scoreManager.scoreDisplay); // drawing the score in the top left corner
		window.draw(scoreManager.healthDisplay); // drawing the health in the top left corner

		// Section for checking if the aliens have descended enough to kill the player
		alien1.checkDescend(player);
		alien2.checkDescend(player);
		alien3.checkDescend(player);
		alien4.checkDescend(player);


		if (scoreManager.score == 4) { // if score reaches 4 player wins
			window.draw(scoreManager.winDisplay); // drawing the winning title
		}

		if (player.playerHealth == 0) { // if health reaches 0 player loses
			window.draw(scoreManager.loseDisplay); // drawing the losing title
			// also when the player dies all the aliens dissapear
			alien1.isDrawnAlien = false;
			alien2.isDrawnAlien = false;
			alien3.isDrawnAlien = false;
			alien4.isDrawnAlien = false;
		}

		if (player.isDrawnPlayer) { // if bool isDrawnPlayer is true then draw the player and check the collisions
			window.draw(playerSprite);
			collision.checkCollisionPlayer(playerSprite);
		}

		// if isDrawnAlien for every alien is true draw them
		if (alien1.isDrawnAlien) { 
			window.draw(alienSprite);
		}
		if (alien2.isDrawnAlien) {
			window.draw(alienSprite2);
		}
		if (alien3.isDrawnAlien) {
			window.draw(alienSprite3);
		}
		if (alien4.isDrawnAlien) {
			window.draw(alienSprite4);
		}

		// if booleans for barriers are true then draw the barriers
		if (barrier1.isDrawnBarrier) {
			window.draw(barrierSprite);
		}
		if (barrier2.isDrawnBarrier) {
			window.draw(barrierSprite2);
		}
		if (barrier3.isDrawnBarrier) {
			window.draw(barrierSprite3);
		}

		//Player shoots
		if (bullet.isDrawnBullet) { // when the player presses the button the boolean triggers
			window.draw(bulletSprite); // drawing bullet
			bulletSprite.move(0.f, bulletSpeed); // giving the bullet some speed
		}

		//Alien 1 shoots
		if (bullet.isDrawnBulletAlien) { // almost the same procedure but with the alien's bullet
			window.draw(bulletSpriteAlien);
			bulletSpriteAlien.move(0.f, -bulletSpeed);
		}

		//COLLISION CHECKING SECTION!!!

		//Checking the PlayerBullet-Alien collisions
		collision.collisionAlienBullet(bulletSprite, alienSprite, bullet.isDrawnBullet, alien1.isDrawnAlien, scoreManager);
		collision.collisionAlienBullet(bulletSprite, alienSprite2, bullet.isDrawnBullet, alien2.isDrawnAlien, scoreManager);
		collision.collisionAlienBullet(bulletSprite, alienSprite3, bullet.isDrawnBullet, alien3.isDrawnAlien, scoreManager);
		collision.collisionAlienBullet(bulletSprite, alienSprite4, bullet.isDrawnBullet, alien4.isDrawnAlien, scoreManager);

		//Checking the PlayerBullet-Barrier collisions
		collision.collisionBarrierBullet(bulletSprite, barrierSprite, bullet.isDrawnBullet, barrier1.isDrawnBarrier, barrier1, bullet);
		collision.collisionBarrierBullet(bulletSprite, barrierSprite2, bullet.isDrawnBullet, barrier2.isDrawnBarrier, barrier2, bullet);
		collision.collisionBarrierBullet(bulletSprite, barrierSprite3, bullet.isDrawnBullet, barrier3.isDrawnBarrier, barrier3, bullet);


		//Checking the AlienBullet-Barrier collisions
		collision.collisionBarrierBullet(bulletSpriteAlien, barrierSprite, bullet.isDrawnBulletAlien, barrier1.isDrawnBarrier, barrier1, bulletAlien);
		collision.collisionBarrierBullet(bulletSpriteAlien, barrierSprite2, bullet.isDrawnBulletAlien, barrier2.isDrawnBarrier, barrier2, bulletAlien);
		collision.collisionBarrierBullet(bulletSpriteAlien, barrierSprite3, bullet.isDrawnBulletAlien, barrier3.isDrawnBarrier, barrier3, bulletAlien);

		//CHecking the AlienBullet-Player collisions
		collision.collisionAlienBulletPlayer(bulletSpriteAlien, playerSprite, bullet.isDrawnBulletAlien, player.isDrawnPlayer, player);

		window.display(); // displaying everything

		sf::Time elapsedTime = timer.getElapsedTime(); // How much time has elapsed since last iteration

		if (elapsedTime.asSeconds() > 1.0f) // Has one second passed?
		{

			//Randomizing section for aliens' shooting system
			//To shoot the alien must compare two random variables and if the match it shoots
			srand(time(NULL));

			int rand1 = rand() % 7 + 2;
			int rand2 = rand() % 5 + 0;
			int rand3 = rand() % 4 + 0;
			int rand4 = rand() % 10 + 1;
			int rand5 = rand() % 3 + 9;
			int rand6 = rand() % 5 + 8;
			int rand7 = rand() % 3 + 1;
			int rand8 = rand() % 4 + 2;

			std::cout << timeCounter << std::endl; // print out the counter
			timeCounter++; // Increment the counter
			if (timeCounter == 100) timeCounter = 0; // keep the counter in bounds

			//Alien movements every second and shooting
			//As I mentioned above the aliens compare two variables
			if (alien1.isDrawnAlien) {
				alien1.moveAlien(alienSprite);
				alien1.descendAlien(alienSprite);
				if (rand1 == rand2) {
					bullet.shoot(alienSprite, bulletSpriteAlien, bullet.isDrawnBulletAlien);
				}
			}

			if (alien2.isDrawnAlien) {
				alien2.moveAlien(alienSprite2);
				alien2.descendAlien(alienSprite2);
				if (rand3 == rand4) {
					bullet.shoot(alienSprite2, bulletSpriteAlien, bullet.isDrawnBulletAlien);
				}
			}

			if (alien3.isDrawnAlien) {
				alien3.moveAlien(alienSprite3);
				alien3.descendAlien(alienSprite3);
				if (rand5 == rand6) {
					bullet.shoot(alienSprite3, bulletSpriteAlien, bullet.isDrawnBulletAlien);
				}
			}

			if (alien4.isDrawnAlien) {
				alien4.moveAlien(alienSprite4);
				alien4.descendAlien(alienSprite4);
				if (rand7 == rand8) {
					bullet.shoot(alienSprite4, bulletSpriteAlien, bullet.isDrawnBulletAlien);
				}
			}

			timer.restart(); // Restart the timer
		}

	}



	return 0;

}