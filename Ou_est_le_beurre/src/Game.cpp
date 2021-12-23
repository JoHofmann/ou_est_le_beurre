//
// Created by paddy on 30.11.21.
//

#include "ou_est_le_beurre/Game.hpp"
#include "ou_est_le_beurre/StateMachine/TestState.hpp"

#include <iostream>

Game::Game() :
	tilemap(&eventIndex)
{
    // Background Music
    // load something into the sound buffer...
    if (!soundBuffer.loadFromFile(AUDIO_PATH + "Background_Music.wav"))
        std::cerr << "Problems while loading background music" << std::endl;

    backgroundMusic.setBuffer(soundBuffer);
    backgroundMusic.setLoop(true);

    backgroundMusic.play();

    // background
    if(!tex_background.loadFromFile(TEXTURES_PATH + "kitchen.png")) {
        std::cerr << "Problems while loading baackground texture" << std::endl;
    }
    background.setTexture(tex_background);

    pPlayer = std::make_shared<Player>("Muttern.png", &tilemap);
    pTextbox = std::make_shared<Textbox>("Simple_Textbox.png");
    pFade = std::make_shared<FadeObject>();

    pPlayer->set_enabled(true);

    gameObjects.push_back(pPlayer);
    gameObjects.push_back(pTextbox);
    gameObjects.push_back(pFade);

    // events
    eventIndex = -1;	// default -> no event will be updated

    pFridgeEvent = std::make_shared<TextboxEvent>(L"Muttern", L"Kühlschrank");
    pEggPanEvent = std::make_shared<TextboxEvent>(L"Muttern", L"Schon wieder die dreckige Pfanne (schüttelt den Kopf)");

    events.push_back(pFridgeEvent);
    events.push_back(pEggPanEvent);

    // tilemap
    std::vector<sf::Vector2i> eventTiles;

    // TODO add event Tiles in correct order!!!!
    eventTiles.push_back(sf::Vector2i(2, 2));
    eventTiles.push_back(sf::Vector2i(2, 3));


    tilemap.setEvents(eventTiles);

    // TODO add all states to states vector
    // TODO I really don't know how I can put a child of State into a vector of states
    std::shared_ptr<OpeningState> pOpeningState = std::make_shared<OpeningState>(this);
    states.push_back(pOpeningState);
    //std::shared_ptr<TestState> pTestState = std::make_shared<TestState>(this);
    //states.push_back(pTestState);
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

    // update current event
    if(eventIndex != -1) {
    	events[eventIndex]->update(delta_t);
    }
//	std::cout << eventIndex << std::endl;


    // TODO update all game objects general
    // update gameObjects
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
    	(*it)->update(delta_t);
	}
}

void Game::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);

    window.draw(background);


//    // draw collision map (for testing)
//    for (int y = 0; y < globals::YTILECOUNT; ++y) {
//    	for (int x = 0; x < globals::XTILECOUNT; ++x) {
//
//    		if(globals::collision_map[y][x]) {
//
//        		sf::RectangleShape rect(sf::Vector2f(globals::TILESIZE, globals::TILESIZE));
//        		rect.setPosition(x * globals::TILESIZE, y * globals::TILESIZE);
//    			rect.setFillColor(sf::Color::Black);
//
//    			window.draw(rect);
//    		}
//    	}
//	}

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

const std::shared_ptr<FadeObject> &Game::getPFade() const {
    return pFade;
}

const std::shared_ptr<Player> &Game::getPlayer() const {
	return pPlayer;
}

std::vector<std::shared_ptr<Event>> &Game::getEvents() {
	return events;
}



const int Game::getEventIndex() {
	return eventIndex;
}

void Game::setEventIndex(int _eventIndex) {
	eventIndex = _eventIndex;
}



