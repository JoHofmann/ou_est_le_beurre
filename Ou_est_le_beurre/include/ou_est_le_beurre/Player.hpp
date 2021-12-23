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
#include <iostream>
#include <memory>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/GameObject.hpp"

class Tilemap;

enum Direction { DOWN, RIGHT, LEFT, UP };

class Player : public GameObject
{
public:
	Player(const std::string &, std::shared_ptr<Tilemap>&);
	~Player();

    void update(float) override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    void setGridPosition(sf::Vector2i);
    sf::Vector2i& getGridPosition();

    void setMoveable(bool);
    bool getMoveable();

private:
	void moveTile(float);
	bool inMap(int, int);

private:
	sf::Texture texture;
	sf::Sprite sprite;

	// position + direction
	sf::Vector2i gridPostion;	// position in grid postion(2 * TILESIZE, 3 * TILESIZE) -> gridPosition(2, 3)
	sf::Vector2i observed;

	Direction direction;

	// moveTile
	const float timePerTile;	// in seconds
	const float offsetTime;		// time to wait between rotating and moving


	bool moveable;

    void setWalkingAnimation(float);
	std::shared_ptr<Tilemap> pTilemap;
};

#endif
