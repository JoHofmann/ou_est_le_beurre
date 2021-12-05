//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"

#include <iostream>

Game::Game() :
	player("Momy.png"),
    textbox("Simple_Textbox.png")
{
    textbox.set_enabled(true);
    textbox.set_text(std::string("This is a test text\nWith a newline!\nBlablablabluuu"));
}

void Game::update(float delta_t)
{
    player.update(delta_t);
    textbox.update(delta_t);
}

void Game::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);

    // draw collision map (for testing)
    for (int y = 0; y < globals::YTILECOUNT; ++y) {
    	for (int x = 0; x < globals::XTILECOUNT; ++x) {

    		if(globals::collision_map[y][x]) {

        		sf::RectangleShape rect(sf::Vector2f(globals::TILESIZE, globals::TILESIZE));
        		rect.setPosition(x * globals::TILESIZE, y * globals::TILESIZE);
    			rect.setFillColor(sf::Color::Black);

    			window.draw(rect);
    		}
    	}
	}

    window.draw(player);
    textbox.draw(window);

    window.display();
}

Game::~Game() {

}

