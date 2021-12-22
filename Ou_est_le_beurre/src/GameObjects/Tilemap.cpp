/*
 * Tilemap.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Tilemap.hpp"

Tilemap::Tilemap(int* indexPointer) {

	// init tilemap as default
	for (int y = 0; y < globals::YTILECOUNT; ++y) {

		std::vector<std::shared_ptr<Tile>> tmp_vec;

		for (int x = 0; x < globals::XTILECOUNT; ++x) {
			tmp_vec.push_back(std::make_shared<Tile>(indexPointer, -1, globals::collision_map[y][x]));
		}

		tilemap.push_back(tmp_vec);
	}

	// add events to tiles
	tilemap[2][2]->setEventIndex(0);
}

Tilemap::~Tilemap() {
	// TODO Auto-generated destructor stub
}

void Tilemap::update(float) {

}

void Tilemap::draw(sf::RenderTarget &target, sf::RenderStates states) const {

	for (int y = 0; y < globals::YTILECOUNT; ++y) {
		for (int x = 0; x < globals::XTILECOUNT; ++x) {
			tilemap[y][x]->draw(target, states);
		}
	}
}

std::vector<std::vector<std::shared_ptr<Tile>>>& Tilemap::getTilemap() {
	return tilemap;
}

const std::shared_ptr<Tile>& Tilemap::getTile(sf::Vector2i vec) {
	return tilemap[vec.y][vec.x];
}






