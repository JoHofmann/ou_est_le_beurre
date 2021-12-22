/*
 * Tile.cpp
 *
 *  Created on: Dec 21, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Tile.hpp"

Tile::Tile(bool _walkable) :
	walkable(_walkable),
	actionable(false),
	enabled(false)
{

}

void Tile::setWalkable(bool _walkable) {
	walkable = _walkable;
}

bool Tile::getWalkable() {
	return walkable;
}

void Tile::setEnabled(bool _enabled) {
	enabled = _enabled;
}

void Tile::setActionTextbox(Textbox& textbox) {
	actionable = true;


}

void Tile::action() {
	if(actionable && enabled) {

	}
}















