/*
 * Player.cpp
 *
 *  Created on: Dec 1, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Player.hpp"
#include "ou_est_le_beurre/Tilemap.hpp"

#include <iostream>
#include <cmath>

Player::Player(const std::string &tex_path, std::shared_ptr<Tilemap>& _pTilemap) :
	direction(DOWN),
	timePerTile(0.7f),
	offsetTime(0.1f),
	moveable(true),
	pTilemap(_pTilemap)
{
	// load whole texture
    if (!texture.loadFromFile(TEXTURES_PATH + tex_path))
    {
        std::cerr << "error while loading player texture" << std::endl;
    }

    // set players texture as first sprite
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(3*direction, 0, globals::TILESIZE, globals::TILESIZE));

//	shape = sprite.getGlobalBounds();

	// init player position in middle
	this->setPosition(sf::Vector2f(globals::WIDTH/2.f, globals::HEIGHT/2.f));
	sprite.setPosition(this->getPosition());
}

Player::~Player() {
}

void Player::update(float delta_t) {

	if(enabled) {
		// update positions
		gridPostion = sf::Vector2i(this->getPosition()) / globals::TILESIZE;

		observed = gridPostion;
		switch(direction) {
		case UP: 	observed.y -= 1;
			break;
		case RIGHT:	observed.x += 1;
			break;
		case DOWN:	observed.y += 1;
			break;
		case LEFT:	observed.x -= 1;
			break;
		}

		// trigger observed tile
		if(inMap(observed.x, observed.y) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			pTilemap->getTile(observed)->triggerd();
		}

		if(moveable) {
			moveTile(delta_t);
		}

		// update sprite position
		sprite.setPosition(this->getPosition());
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

		startPos = this->getPosition();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 			// move up
			direction = UP;

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.x, gridPostion.y - 1) &&
						!globals::collision_map[gridPostion.y - 1][gridPostion.x]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {		// move left
			direction = LEFT;

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.x - 1, gridPostion.y) &&
						!globals::collision_map[gridPostion.y][gridPostion.x - 1]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {		// move down
			direction = DOWN;

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.x, gridPostion.y + 1) &&
						!globals::collision_map[gridPostion.y + 1][gridPostion.x]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {		// move right
			direction = RIGHT;

			if(prevDirection != direction && !walking) {
				time = 0.f;
			}else if(time >= offsetTime) {
				time = 0.f;

				if(inMap(gridPostion.x + 1, gridPostion.y) &&
						!globals::collision_map[gridPostion.y][gridPostion.x + 1]) {	// check if next field is accessable
					moving = true;
				}
			}
		}
        sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction), 0, globals::TILESIZE, globals::TILESIZE));

		prevDirection = direction;
		walking = false;

	}else{	// executing move

		walking = true;

		float progress = time / timePerTile;	// progress [0 - 1]
        setWalkingAnimation(progress);

		if(progress >= 1.f) {	// move completed
			progress = 1.f;		// set end position fix
			moving = false;
		}

		switch(direction) {
		case UP:
			this->setPosition(sf::Vector2f(startPos.x, startPos.y - (globals::TILESIZE * progress)));
			break;
		case LEFT:
			this->setPosition(sf::Vector2f(startPos.x - (globals::TILESIZE * progress), startPos.y));
			break;
		case DOWN:
			this->setPosition(sf::Vector2f(startPos.x, startPos.y + (globals::TILESIZE * progress)));
			break;
		case RIGHT:
			this->setPosition(sf::Vector2f(startPos.x + (globals::TILESIZE * progress), startPos.y));
			break;

		default:
			std::cerr << "should not happen" << std::endl;
			break;
		}
	}
}

void Player::setWalkingAnimation(float progress){
    if(direction == UP || direction == DOWN){
        if(progress < 0.5f){
            sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction + 1), 0, globals::TILESIZE, globals::TILESIZE));
        }else if(progress < 1.0f){
            sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction + 2), 0, globals::TILESIZE, globals::TILESIZE));
        }
    }else{
        if(progress < 0.33f){
            sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction + 1), 0, globals::TILESIZE, globals::TILESIZE));
        }else if(progress < 0.66f){
            sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction), 0, globals::TILESIZE, globals::TILESIZE));
        }else if(progress < 1.0f){
            sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction + 2), 0, globals::TILESIZE, globals::TILESIZE));
        }
    }
}

// check if pos(x, y) is in map
bool Player::inMap(int x, int y) {

	return x >= 0 && y >= 0 && x < globals::XTILECOUNT && y < globals::YTILECOUNT;
}

void Player::setGridPosition(sf::Vector2i _gridPosition) {
    this->setPosition(static_cast<sf::Vector2f>(_gridPosition * globals::TILESIZE));
}

sf::Vector2i& Player::getGridPosition() {
	return gridPostion;
}

void Player::setMoveable(bool _moveable) {
	moveable = _moveable;
}

bool Player::getMoveable() {
	return moveable;
}





