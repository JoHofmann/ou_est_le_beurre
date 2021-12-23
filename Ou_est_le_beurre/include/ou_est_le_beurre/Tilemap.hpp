/*
 * Tilemap.hpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_TILEMAP_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_TILEMAP_HPP_

#include <vector>
#include <memory>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/GameObject.hpp"
#include "ou_est_le_beurre/Tile.hpp"


class Tilemap : public GameObject{
public:
	Tilemap(int*);
	~Tilemap();

	void update(float) override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    std::vector<std::vector<std::shared_ptr<Tile>>>& getTilemap();

    const std::shared_ptr<Tile>& getTile(sf::Vector2i);

private:

	std::vector<std::vector<std::shared_ptr<Tile>>> tilemap;
};

#endif /* INCLUDE_OU_EST_LE_BEURRE_TILEMAP_HPP_ */
