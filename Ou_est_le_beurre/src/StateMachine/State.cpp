//
// Created by paddy on 08.12.21.
//

#include "ou_est_le_beurre/StateMachine/State.hpp"

State::State(Game *game) :
	game(game)
{
    elapsedTime = 0.0;
}

void State::update(float delta_t) {
    State::elapsedTime += delta_t;
    this->processState();
}

// *** Getter and Setter ***
float State::getElapsedTime() const {
    return elapsedTime;
}
