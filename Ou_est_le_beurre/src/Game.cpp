//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"

#include <iostream>

Game::Game()
{
	pPlayer = std::make_shared<Player>("Momy.png");
	pTextbox = std::make_shared<Textbox>("Simple_Textbox.png");

	pPlayer->set_enabled(true);

	pTextbox->set_enabled(true);
	pTextbox->set_text(std::string("This is a simple text to test the texbox newline function for longer sentences. In addition it would be also interesting to test the behaviour when the textbox is running out of new lines."));

	gameObjects.push_back(pPlayer);
	gameObjects.push_back(pTextbox);
}

void Game::update(float delta_t)
{
    // update gameObjects
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
    	(*it)->update(delta_t);
	}
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

    // draw gameObjects
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
    	window.draw(*(*it));
	}

    window.display();
}

Game::~Game() {

}

