//
// Created by paddy on 20.12.21.
//

#include "ou_est_le_beurre/OpeningState.hpp"


OpeningState::OpeningState(Game const *game) : State(game){
    pTextbox = game->getPTextbox();
    // TODO initialize scene
    // TODO momy at door
    // TODO lock player control
}

bool OpeningState::goalReached() {
    return false;
}

void OpeningState::processState() {
    // TODO fade in scene
    // TODO show intro text

}
