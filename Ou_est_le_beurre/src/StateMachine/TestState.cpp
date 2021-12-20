//
// Created by paddy on 08.12.21.
//

#include "ou_est_le_beurre/TestState.hpp"
#include <iostream>

TestState::TestState(Game const *game) : State(game) {
    pTextbox = game->getPTextbox();
    pTextbox->set_enabled(true);
    pTextbox->set_text(std::wstring(L"Test center Innsbruck"), std::wstring(L"This is a simple text to test the texbox newline function for longer sentences. In addition it would be also interesting to test the behaviour when the textbox is running out of new lines."));

}

bool TestState::goalReached() {
    // this test state is over when the text of the textbox is fully shown
    if(!pTextbox->get_enabled()){
        return true;
    }
    return false;
}

void TestState::processState() {
    if(!goalReached()){
        std::cout << "processing test state" << std::endl;
    }
}

