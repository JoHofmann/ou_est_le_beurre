//
// Created by paddy on 08.12.21.
//

#ifndef OUESTLEBEURRE_TESTSTATE_HPP
#define OUESTLEBEURRE_TESTSTATE_HPP

#include "ou_est_le_beurre/StateMachine/State.hpp"
#include "ou_est_le_beurre/Game.hpp"

class TestState : public State{
public:
    TestState(Game *);

    bool goalReached() override;
    void initState() override;
private:
    void processState() override;

    std::shared_ptr<Textbox> pTextbox;
    std::vector<std::shared_ptr<Event>> events;
};


#endif //OUESTLEBEURRE_TESTSTATE_HPP
