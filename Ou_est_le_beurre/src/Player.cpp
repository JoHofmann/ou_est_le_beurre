/*
 * Player.cpp
 *
 *  Created on: Dec 1, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Player.hpp"

#include <iostream>

Player::Player(const std::string &tex_path) :
	speed(0.2f)
{
	// load whole texture
    if (!texture.loadFromFile(TEXTURES_PATH + tex_path))
    {
        std::cerr << "error while loading player texture" << std::endl;
    }

    // set players texture as first sprite
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, globals::TILESIZE, globals::TILESIZE));
}

Player::~Player() {

}

void Player::update(float delta_t) {

	moveTile(delta_t);
}

// direction:
// 0 = up
// 1 = left
// 2 = down
// 3 = right
void Player::moveTile(float delta_t) {

	static bool moving = false;
	static int  moveDirection;
	static sf::Vector2f startPos;
	static float time = 0.f;

	if(!moving) {	// init move

		startPos = this->getPosition();
		time = 0.f;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 			// move up
			moveDirection = 0;
			moving = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {		// move left
			moveDirection = 1;
			moving = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {		// move down
			moveDirection = 2;
			moving = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {		// move right
			moveDirection = 3;
			moving = true;
		}

	}else{	// execute move

		time += delta_t;

		float progress = time / speed;	// progress [0, 1]

		if(progress >= 1.f) {	// move completed
			progress = 1.f;	// set end position fix
			moving = false;
		}

		switch(moveDirection) {
		case 0:
			this->setPosition(startPos.x, startPos.y - (globals::TILESIZE * progress));
			break;
		case 1:
			this->setPosition(startPos.x - (globals::TILESIZE * progress), startPos.y);
			break;
		case 2:
			this->setPosition(startPos.x, startPos.y + (globals::TILESIZE * progress));
			break;
		case 3:
			this->setPosition(startPos.x + (globals::TILESIZE * progress), startPos.y);
			break;

		default:
			std::cerr << "should not happen" << std::endl;
			break;
		}
	}
}








