/*
 * Tile.hpp
 *
 *  Created on: Dec 21, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_TILE_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_TILE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "ou_est_le_beurre/GameObject.hpp"
#include "ou_est_le_beurre/Textbox.hpp"
#include "ou_est_le_beurre/globals.hpp"


class Tile : public GameObject{
public:

	Tile(int* _indexPointer, int, bool);

	void setWalkable(bool);
	bool getWalkable();
	void setEventIndex(int);

	void triggerd();

	const sf::Vector2i& getGridPosition();
    void update(float) override;
    void draw(sf::RenderTarget&, sf::RenderStates) const override;

private:

private:
	bool walkable;

	int eventIndex;
	int *indexPointer;
};



#endif /* INCLUDE_OU_EST_LE_BEURRE_TILE_HPP_ */
