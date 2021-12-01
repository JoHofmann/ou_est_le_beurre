/*
 * Player.cpp
 *
 *  Created on: Dec 1, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Player.hpp"

#include <iostream>

Player::Player(std::string tex_path) {
	// load whole texture
    if (texture.loadFromFile(TEXTURES_PATH + tex_path))
    {
        std::cerr << "error while loading player texture" << std::endl;
    }

    // set players texture as first sprite
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, globals::TILESIZE, globals::TILESIZE));
}

Player::~Player() {

}

