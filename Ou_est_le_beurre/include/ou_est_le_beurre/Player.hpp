/*
 * Player.hpp
 *
 *  Created on: Dec 1, 2021
 *      Author: johannes
 */

#ifndef OU_EST_LE_BEURRE_PLAYER_HPP_
#define OU_EST_LE_BEURRE_PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include "ou_est_le_beurre/globals.hpp"

class Player : public sf::Sprite
{
public:
	Player(const std::string &);
	~Player();

	void update(float);

private:
	void moveTile(float);

private:
	sf::Texture texture;

	const float speed;	// time[s] / tile
};

#endif /* INCLUDE_OU_EST_LE_BEURRE_PLAYER_HPP_ */
