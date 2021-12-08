//
// Created by paddy on 08.12.21.
//

#ifndef OUESTLEBEURRE_STATE_HPP
#define OUESTLEBEURRE_STATE_HPP

#include "ou_est_le_beurre/StateMachine.hpp"
#include "ou_est_le_beurre/Game.hpp"
#include "Game.hpp"

class State {
public:
    State(Game const *);
    void update(float);
    virtual bool goalReached()=0;

    // *** Getter and Setter ***
    float getElapsedTime() const;

protected:
    Game const *game;
private:
    // *** private fields ***
    float elapsedTime;

    // *** private functions ***
    virtual void processState()=0;
};


#endif //OUESTLEBEURRE_STATE_HPP
