//
// Created by paddy on 08.12.21.
//

#ifndef OUESTLEBEURRE_TESTSTATE_HPP
#define OUESTLEBEURRE_TESTSTATE_HPP

#include "ou_est_le_beurre/State.hpp"

class TestState : public State{
public:
    TestState(Game const *);

    bool goalReached() override;
private:
    void processState() override;

};


#endif //OUESTLEBEURRE_TESTSTATE_HPP
