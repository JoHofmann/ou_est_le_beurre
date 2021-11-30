//
// Created by paddy on 30.11.21.
//

#include "../include/ou_est_le_beurre/Game.hpp"

#include <iostream>

Game::Game()
{

    if (!t_player.loadFromFile(TEXTURES_PATH + std::string("Momy.png")))
    {
        std::cerr << "error while loading player texture" << std::endl;
    }
    player.setTexture(t_player);

}

void Game::update(float delta_t)
{
    player.move(1, 2);
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

