/*
 * Tile.cpp
 *
 *  Created on: Dec 21, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Tile.hpp"

#include <iostream>

// if no event eventIndex should be -1!
Tile::Tile(int *_indexPointer, int _eventIndex, bool _walkable) :
	eventIndex(_eventIndex),
	walkable(_walkable),
	indexPointer(_indexPointer)
{
	this->set_enabled(true);
}

void Tile::setWalkable(bool _walkable) {
	walkable = _walkable;
}

bool Tile::getWalkable() {
	return walkable;
}

void Tile::setEventIndex(int _eventIndex) {
	eventIndex = _eventIndex;
}

void Tile::triggerd() {
	if((eventIndex != -1) && enabled) {
		*indexPointer = eventIndex;
	}
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(enabled){
        // Since we don't draw the individual tiles yet this function is empty
    }
    return;
}

void Tile::update(float) {
    return;
}
















