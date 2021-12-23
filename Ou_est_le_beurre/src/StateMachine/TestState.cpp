//
// Created by paddy on 08.12.21.
//

#include "ou_est_le_beurre/StateMachine/TestState.hpp"
#include <iostream>

TestState::TestState(Game *game) : State(game) {
    pTextbox = game->getPTextbox();
    pTextbox->set_enabled(true);
    pTextbox->set_text(std::wstring(L"Test center Innsbruck"), std::wstring(L"Test"));
    game->getPTilemap()->resetEvents();
    std::vector<sf::Vector2i> eventTiles;

    std::vector<std::shared_ptr<Event>> events;
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Test Event"));
    eventTiles.push_back(sf::Vector2i(2, 2));
    events.push_back(std::make_shared<TextboxEvent>(game , L"Muttern", L"Schon wieder die dreckige Pfanne (schüttelt den Kopf)"));
    eventTiles.push_back(sf::Vector2i(2, 3));

    game->getPTilemap()->setEvents(eventTiles);
    game->setEvents(events);
    //game->getPlayer()->setCtrlDirection(Direction::UP, true);

}

bool TestState::goalReached() {
    // this test state is over when the text of the textbox is fully shown
//    if(!pTextbox->get_enabled()){
//        return true;
//    }
    return false;
}

void TestState::processState() {
    if(!goalReached()){

    }
}

