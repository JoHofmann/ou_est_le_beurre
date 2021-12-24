//
// Created by paddy on 23.12.21.
//

#ifndef OUESTLEBEURRE_EXPLORINGSTATE_HPP
#define OUESTLEBEURRE_EXPLORINGSTATE_HPP

#include "ou_est_le_beurre/StateMachine/State.hpp"
#include "ou_est_le_beurre/Game.hpp"
#include "ou_est_le_beurre/Events/ChauAmoreEvent.hpp"

class ExploringState : public State{
public:
    ExploringState(Game *game);

    bool goalReached() override;
    void initState() override;
private:
    void processState() override;

};


#endif //OUESTLEBEURRE_EXPLORINGSTATE_HPP
