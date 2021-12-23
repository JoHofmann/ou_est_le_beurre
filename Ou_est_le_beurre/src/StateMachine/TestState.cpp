//
// Created by paddy on 08.12.21.
//

#include "ou_est_le_beurre/StateMachine/TestState.hpp"
#include <iostream>

TestState::TestState(Game *game) : State(game) {
    pTextbox = game->getPTextbox();
    pTextbox->set_enabled(true);
    pTextbox->set_text(std::wstring(L"Test center Innsbruck"), std::wstring(L"Test"));

    events = game->getEvents();

    // set all events false
    for (auto it = events.begin(); it < events.end(); ++it) {
    	(*it)->setEnabled(false);
	}

    events[0]->setEnabled(true);	// fridge event
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
//        std::cout << "processing test state" << std::endl;
    }
}

