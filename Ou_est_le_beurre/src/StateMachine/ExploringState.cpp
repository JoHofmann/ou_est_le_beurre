//
// Created by paddy on 23.12.21.
//

#include "ou_est_le_beurre/StateMachine/ExploringState.hpp"

ExploringState::ExploringState(Game *game) : State(game) {
}



bool ExploringState::goalReached() {
    return false;
}

void ExploringState::processState() {

}

void ExploringState::initState() {
    // init events
    std::vector<sf::Vector2i> eventTiles;

    std::vector<std::shared_ptr<Event>> events;
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Nein. Hier ist die Butter bestimmt nicht..."));
    eventTiles.push_back(sf::Vector2i(5, 0));
    events.push_back(std::make_shared<ChauAmoreEvent>(game));
    eventTiles.push_back(sf::Vector2i(6,5));

    game->getPTilemap()->setNewEvents(eventTiles);
    game->setEvents(events);
}
