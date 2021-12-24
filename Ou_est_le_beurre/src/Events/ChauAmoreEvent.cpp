//
// Created by paddy on 24.12.21.
//

#include "ou_est_le_beurre/Events/ChauAmoreEvent.hpp"
#include "ou_est_le_beurre/Game.hpp"

ChauAmoreEvent::ChauAmoreEvent(Game *_game) : Event(), pGame(_game){
    pTextbox = pGame->getPTextbox();
    pPapo = pGame->getPPapo();
    pPlayer = pGame->getPlayer();
    currentDirection = Direction::IDLE;

    // TODO define papo walk trajectory
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::UP);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    //papoExitTrajectory
}


void ChauAmoreEvent::update(float) {
    if(isActive()) {
        // TODO show angry textbox
        // TODO walk trajectory
        if (!pPapo->isMoving()) {
            if(!papoEnterTrajectory.empty()){
                //std::cout << "traj empty" << std::endl;
                Direction d = papoEnterTrajectory.front();
                papoEnterTrajectory.erase(papoEnterTrajectory.begin());
                pPapo->setCtrlDirection(d, false);
            }
        }
        // TODO open Textbox with chau amore
    }
}

void ChauAmoreEvent::init() {
    // set papo to start pos
    pPapo->setGridPosition(sf::Vector2i(0, 2));
    pPapo->set_enabled(true);
    //pPapo->setMoveable(false);
    // lock player control
    pPlayer->setMoveable(false);
    this->setActive(true);
}
