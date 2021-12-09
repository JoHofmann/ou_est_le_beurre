//
// Created by paddy on 08.12.21.
//

#include "ou_est_le_beurre/TestState.hpp"
#include <iostream>

TestState::TestState(Game const*game) : State(game) {

}

bool TestState::goalReached() {
    if(getElapsedTime() > 2.0){
        return true;
    }
    return false;
}

void TestState::processState() {
    //Textbox textbox = game->getTextbox();
    std::cout << "processing test state" << std::endl;
}

