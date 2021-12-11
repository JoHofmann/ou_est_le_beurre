/*
 * Player.cpp
 *
 *  Created on: Dec 1, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Player.hpp"

#include <iostream>

Player::Player(const std::string &tex_path) :
	direction(DOWN), timePerTile(0.25f), offsetTime(0.1f)
{
	// load whole texture
    if (!texture.loadFromFile(TEXTURES_PATH + tex_path))
    {
        std::cerr << "error while loading player texture" << std::endl;
    }

    // set players texture as first sprite
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, globals::TILESIZE, globals::TILESIZE));

//	shape = sprite.getGlobalBounds();

	// init player position in middle
	position = sf::Vector2f(globals::WIDTH/2.f, globals::HEIGHT/2.f);
	sprite.setPosition(position);
}

Player::~Player() {
}

void Player::update(float delta_t) {

	if(enabled) {
		// update positions
		gridPostion = sf::Vector2i(position.x / globals::TILESIZE, position.y / globals::TILESIZE);

		moveTile(delta_t);

		sprite.setPosition(position);
	}
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(enabled) {
		target.draw(sprite, states);
	}
}


void Player::moveTile(float delta_t) {

	static bool moving = false, walking = false;
	static Direction prevDirection;
	static sf::Vector2f startPos;
	static float time = 0.f;
	static float rotTime  = 0.f;

	// update watch
	time += delta_t;

	if(!moving) {	// init move

		startPos = position;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 			// move up
			direction = UP;

			sprite.setTextureRect(sf::IntRect(0, 0, globals::TILESIZE, globals::TILESIZE));

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.y - 1, gridPostion.x) &&
						!globals::collision_map[gridPostion.y - 1][gridPostion.x]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {		// move left
			direction = LEFT;

			sprite.setTextureRect(sf::IntRect(3*globals::TILESIZE, 0, globals::TILESIZE, globals::TILESIZE));

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.y, gridPostion.x - 1) &&
						!globals::collision_map[gridPostion.y][gridPostion.x - 1]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {		// move down
			direction = DOWN;

			sprite.setTextureRect(sf::IntRect(2*globals::TILESIZE, 0, globals::TILESIZE, globals::TILESIZE));

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.y + 1, gridPostion.x) &&
						!globals::collision_map[gridPostion.y + 1][gridPostion.x]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {		// move right
			direction = RIGHT;

			sprite.setTextureRect(sf::IntRect(globals::TILESIZE, 0, globals::TILESIZE, globals::TILESIZE));

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.y, gridPostion.x + 1) &&
						!globals::collision_map[gridPostion.y][gridPostion.x + 1]) {	// check if next field is accessable
					moving = true;
				}
			}
		}

		prevDirection = direction;
		walking = false;

	}else{	// executing move

		walking = true;

		float progress = time / timePerTile;	// progress [0 - 1]

		if(progress >= 1.f) {	// move completed
			progress = 1.f;		// set end position fix
			moving = false;
		}

		switch(direction) {
		case UP:
			position = sf::Vector2f(startPos.x, startPos.y - (globals::TILESIZE * progress));
			break;
		case LEFT:
			position = sf::Vector2f(startPos.x - (globals::TILESIZE * progress), startPos.y);
			break;
		case DOWN:
			position = sf::Vector2f(startPos.x, startPos.y + (globals::TILESIZE * progress));
			break;
		case RIGHT:
			position = sf::Vector2f(startPos.x + (globals::TILESIZE * progress), startPos.y);
			break;

		default:
			std::cerr << "should not happen" << std::endl;
			break;
		}
	}
}

// check if pos(x, y) is in map
bool Player::inMap(int x, int y) {
	return x >= 0 && y >= 0 && x < globals::XTILECOUNT && y < globals::YTILECOUNT;
}






