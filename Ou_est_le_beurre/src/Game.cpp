//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"
#include "ou_est_le_beurre/TestState.hpp"

#include <iostream>

Game::Game()
{
    // Background Music
    // load something into the sound buffer...
    if (!soundBuffer.loadFromFile(AUDIO_PATH + "Background_Music.wav"))
        std::cerr << "Problems while loading background music" << std::endl;

    backgroundMusic.setBuffer(soundBuffer);
    backgroundMusic.setLoop(true);

    backgroundMusic.play();


    pPlayer = std::make_shared<Player>("Momy.png");
    pTextbox = std::make_shared<Textbox>("Simple_Textbox.png");

    pPlayer->set_enabled(true);

    gameObjects.push_back(pPlayer);
    gameObjects.push_back(pTextbox);


    // TODO add all states to states vector
    // TODO I really don't know how I can put a child of State into a vector of states
    std::shared_ptr<TestState> pTestState = std::make_shared<TestState>(this);
    states.push_back(pTestState);
    // TODO start iterator
    stateIterator = states.begin();
}

void Game::updateStateMachine(float delta_t){
    if((*stateIterator)->goalReached()){
        if((*stateIterator) == states.back()){
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

const std::shared_ptr<Textbox> &Game::getPTextbox() const {
    return pTextbox;
}

