//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"
#include "ou_est_le_beurre/TestState.hpp"

#include <iostream>

Game::Game() :
	player("Momy.png"),
    textbox("Simple_Textbox.png")
{
    textbox.set_enabled(true);
    textbox.set_text(std::string("This is a simple text to test the texbox newline function for longer sentences. In addition it would be also interesting to test the behaviour when the textbox is running out of new lines."));

    // TODO add all states to states vector
    TestState *testState = new TestState(this);
    Game::states.push_back(testState);
    // TODO start iterator
    stateIterator = states.begin();
}

void Game::updateStateMachine(float delta_t){
    if((*stateIterator)->goalReached()){
        if((*stateIterator) == (*states.end())){
            // TODO do something
            std::cout << "Game is over" << std::endl;
        }else{
            stateIterator = next(stateIterator);
        }
    }
    (*stateIterator)->update(delta_t);
}

void Game::update(float delta_t)
{
    updateStateMachine(delta_t);

    // TODO update all game objects general
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
    window.draw(textbox);

    window.display();
}

Game::~Game() {
    for(State *state : states){
        delete (*state);
    }
}

const Textbox &Game::getTextbox() const {
    return textbox;
}

