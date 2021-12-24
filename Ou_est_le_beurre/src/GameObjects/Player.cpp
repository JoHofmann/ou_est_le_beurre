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
	ctrl_direction(IDLE),
	timePerTile(0.7f),
	offsetTime(0.1f),
	moveable(true),
	pTilemap(_pTilemap),
	moving(false),
	rot_only(false),
    moveState(NONE)
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
            default: std::cerr << "invalid direction (vermutlich IDLE)" << std::endl;
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

void Player::setCtrlDirection(Direction _ctrl_direction, bool _rot_only) {
	ctrl_direction = _ctrl_direction;

	rot_only = _rot_only;
}

bool Player::isMoving() {
	return moving;
}


void Player::moveTile(float delta_t) {
	static sf::Vector2f startPos;
	static float movTime = 0.f;
	static float rotTime  = 0.f;
    if(moveState == NONE){
        moving = false;
    }

	if(moveState == NONE || moveState == ROTATING) {	// init move


		if((ctrl_direction == IDLE && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || ctrl_direction == UP) { 			// move up
            direction = UP;
            moveState = ROTATING;
		}

		else if((ctrl_direction == IDLE && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || ctrl_direction == LEFT) {		// move left
            direction = LEFT;
            moveState = ROTATING;
		}
		else if((ctrl_direction == IDLE && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || ctrl_direction == DOWN) {		// move down
            direction = DOWN;
            moveState = ROTATING;
        }
		else if((ctrl_direction == IDLE && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || ctrl_direction == RIGHT) {		// move right
            direction = RIGHT;
            moveState = ROTATING;
		}
    }

    if(moveState == ROTATING) {
        moving = true;
        rotTime += delta_t;

        sprite.setTextureRect(sf::IntRect(globals::TILESIZE * (3*direction), 0, globals::TILESIZE, globals::TILESIZE));

        static Direction prevDirection = IDLE;

        if(prevDirection != direction) {
            moveState = NONE;
            rotTime = 0.f;
        }

        prevDirection = direction;

        if(rotTime >= offsetTime) { // finsished rotatiing

            startPos = this->getPosition();

            switch (direction) {
                case UP:
                    if(inMap(gridPostion.x, gridPostion.y - 1) &&
                       !globals::collision_map[gridPostion.y - 1][gridPostion.x]) {    // check if next field is accessable
                        moveState = WALKING;
                    }
                    break;
                case DOWN:
                    if(inMap(gridPostion.x, gridPostion.y + 1) &&
                       !globals::collision_map[gridPostion.y + 1][gridPostion.x]) {    // check if next field is accessable
                        moveState = WALKING;
                    }
                        break;
                case LEFT:
                    if(inMap(gridPostion.x - 1, gridPostion.y) &&
                       !globals::collision_map[gridPostion.y][gridPostion.x - 1]) {	// check if next field is accessable
                        moveState = WALKING;
                    }

                    break;
                case RIGHT:
                    if(inMap(gridPostion.x + 1, gridPostion.y) &&
                       !globals::collision_map[gridPostion.y][gridPostion.x + 1]) {	// check if next field is accessable
                        moveState = WALKING;
                    }
                    break;

                case IDLE:   // schlecht wenn hier IDLE is
                    break;
            }

            rotTime = 0.f;
        }
    }

    if(moveState == WALKING) {	// executing move

        moving = true;

        movTime += delta_t;

        float progress = movTime / timePerTile;	// progress [0 - 1]
        setWalkingAnimation(progress);

		if(progress >= 1.f) {	// move completed
			progress = 1.f;		// set end position fix
            movTime = 0.f;
            moveState = NONE;

			ctrl_direction = IDLE;
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





