//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"

#include <iostream>

Game::Game() :
	player("Momy.png")
{

}

void Game::update(float delta_t)
{
    player.update(delta_t);
}

void Game::draw(sf::RenderWindow &window)
{
    window.clear();

    window.draw(player);
    //window.draw(Momy.png);

    window.display();
}

Game::~Game() {

}

