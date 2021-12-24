//
// Created by paddy on 24.12.21.
//

#include "ou_est_le_beurre/Events/ChauAmoreEvent.hpp"
#include "ou_est_le_beurre/Game.hpp"

ChauAmoreEvent::ChauAmoreEvent(Game *_game) : Event(), pGame(_game){
    pTextbox = pGame->getPTextbox();
    pPapo = pGame->getPPapo();
    pPlayer = pGame->getPlayer();
}


void ChauAmoreEvent::update(float) {
    if(isActive()) {
        // TODO show angry textbox
        // TODO walk trajectory
        if (!pPapo->isMoving() && currentState == WALKING_IN) {
            std::cout << papoEnterTrajectory.size() << std::endl;
            // if there is still some trajectory to walk
            if(!papoEnterTrajectory.empty()){
                pPapo->setCtrlDirection(papoEnterTrajectory.front(), false);
                papoEnterTrajectory.erase(papoEnterTrajectory.begin());
            }
            // else rotate and change state
            else {
                pPapo->setCtrlDirection(Direction::DOWN, true);
                currentState = TALKING;
            }
        } else if(currentState == TALKING) {
            // talk
            if(!pTextbox->get_enabled() && !pTextbox->isTextIsFinished()){
                pTextbox->set_enabled(true);
            }
            if(pTextbox->isTextIsFinished()){
                currentState = WALKING_BACK;
            }
        } else if(!pPapo->isMoving() && currentState == WALKING_BACK){
            // walk back
            if(!papoExitTrajectory.empty()){
                pPapo->setCtrlDirection(papoExitTrajectory.front(), false);
                papoExitTrajectory.erase(papoExitTrajectory.begin());
            }else{
                // Event is done
                pPapo->set_enabled(false);
                setActive(false);
            }
        }
    }
}

void ChauAmoreEvent::init() {
    // set papo to start pos
    pPapo->setGridPosition(sf::Vector2i(0, 2));
    pPapo->set_enabled(true);
    pTextbox->set_text(L"Vatern", L"Ciao d'Amore. Es tut so weh...");
    pTextbox->set_enabled(false);
    //pPapo->setMoveable(false);
    // lock player control
    pPlayer->setMoveable(false);

    currentState = WALKING_IN;

    // define papo walk trajectory
    papoEnterTrajectory.empty();
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::UP);
    papoEnterTrajectory.push_back(Direction::RIGHT);
    papoEnterTrajectory.push_back(Direction::RIGHT);

    papoExitTrajectory.empty();
    papoExitTrajectory.push_back(Direction::DOWN);
    papoExitTrajectory.push_back(Direction::LEFT);
    papoExitTrajectory.push_back(Direction::LEFT);
    papoExitTrajectory.push_back(Direction::LEFT);
    papoExitTrajectory.push_back(Direction::LEFT);
    papoExitTrajectory.push_back(Direction::LEFT);

    this->setActive(true);
}
